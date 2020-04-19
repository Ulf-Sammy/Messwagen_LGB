#include "Hardware.h"
// #define B-SENSOR 
#define FUNK-Modul

Hardware::Hardware()
{
}

Hardware::~Hardware()
{
}

void Hardware::Begin()
{
	pinMode(PIN_TAKTRAD, INPUT_PULLUP);
	pinMode(PIN_START, INPUT);
	pinMode(PIN_TASTE_L, INPUT);
	digitalWrite(PIN_TASTE_L, HIGH);
	pinMode(PIN_TASTE_R, INPUT);
	digitalWrite(PIN_TASTE_R, HIGH);
	pinMode(PIN_LED, OUTPUT);
	//
#ifdef FUNK-Modul
	vw_set_tx_pin(PIN_FUNK);
	vw_setup(FUNK_bps); // bps zum funken
#endif // FUNK-Modul

	// 
#ifdef B-SENSOR
	// B-SENSOR
	Wire.begin();
	Wire.beginTransmission(MPU6050_ADRESS); // Begins a transmission to the I2C slave (GY-521 board)
	Wire.write(0x6B); // PWR_MGMT_1 register
	Wire.write(0); // set to zero (wakes up the MPU-6050)
	Wire.endTransmission(true);
#endif 
}

int Hardware::LeseSpannung()
{
	return analogRead(PIN_SPANNUNG);
}

void Hardware::Sende_Werte(SendData Data)
{//                       
	// I Index der Messungen
	// Power Sannung in Volt 200 = 20.0V
	// Speed  Geschwindigkeit
	// Zw Zeit...
	Funk_Data[0] = highByte(Data.Nr);
	Funk_Data[1] = lowByte(Data.Nr);
	Funk_Data[2] = Data.Po;
	Funk_Data[3] = Data.Sp;

#ifdef FUNK-Modul
	vw_send((byte*)Funk_Data, sizeof(Funk_Data));
	vw_wait_tx();
#endif // FUNK-Modul
	//TRACE2("Power = ", Data.Po)
	//TRACE2("Speed = ", Data.Sp)
}


void Hardware::SetzBeschleunigungWerte()
{
#ifdef B-SENSOR
	Beschleunigung.X = Besch_Data[ 0] << 8 | Besch_Data[ 1];
	Beschleunigung.Y = Besch_Data[ 2] << 8 | Besch_Data[ 3];
	Beschleunigung.Z = Besch_Data[ 4] << 8 | Besch_Data[ 5];
	int Tmp			 = Besch_Data[ 6] << 8 | Besch_Data[ 7];
	Gyroskop.X       = Besch_Data[ 8] << 8 | Besch_Data[ 9];
	Gyroskop.Y		 = Besch_Data[10] << 8 | Besch_Data[11];
	Gyroskop.Z       = Besch_Data[12] << 8 | Besch_Data[13];
	Temperatur = Tmp / 340.0 + 36.53;

	char Buffer[200];
	sprintf(Buffer, "B = x: %6d |y: %6d |z: %6d", Beschleunigung.X, Beschleunigung.Y, Beschleunigung.Z);
	Serial.println(Buffer);
	//sprintf(Buffer, "G = x: %6d |y: %6d |z: %6d", Gyroskop.X, Gyroskop.Y, Gyroskop.Z);
	//Serial.println(Buffer);
#endif // B-SENSOR
}



Mess_Besch Hardware::LeseBeschleunigungWerte()
{
#ifdef B-SENSOR
	Wire.beginTransmission(MPU6050_ADRESS);
	Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
	Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
	Wire.requestFrom(MPU6050_ADRESS, MPU6050_DATA_L, true); // request a total of 7*2=14 registers

	for (byte d = 0; d < MPU6050_DATA_L; d++)
	{
		Besch_Data[d] = Wire.read();
	}
#endif // B-SENSOR
	/*
		accX = Wire.read() << 8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
		accY = Wire.read() << 8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
		accZ = Wire.read() << 8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
		tVal = Wire.read() << 8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
		gyrX = Wire.read() << 8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
		gyrY = Wire.read() << 8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
		gyrZ = Wire.read() << 8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)

	*/
	return Mess_Besch();
}

