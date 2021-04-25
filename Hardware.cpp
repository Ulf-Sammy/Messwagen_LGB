#include "Hardware.h"
// #define B-SENSOR 


Hardware::Hardware()
{
}

Hardware::~Hardware()
{
}

void Hardware::Begin()
{
	Gyro_Sensor = new MPU6050(Wire);
	pinMode(PIN_TAKTRAD, INPUT_PULLUP);
	pinMode(PIN_START, INPUT);
	pinMode(PIN_TASTE_L, INPUT);
	digitalWrite(PIN_TASTE_L, HIGH);
	pinMode(PIN_TASTE_R, INPUT);
	digitalWrite(PIN_TASTE_R, HIGH);
	pinMode(PIN_LED, OUTPUT);

	Serial.println("Done.");
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
	char32_t Wert;

	Funk_Data[0] = highByte(Data.Nr);
	Funk_Data[1] = lowByte(Data.Nr);
	Funk_Data[2] = Data.Po;
	Funk_Data[3] = Data.Sp;
	Wert = Data.GW.T; // Temperatur
	Funk_Data[ 4] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[ 5] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[ 6] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[ 7] = Wert & 0x000000FF;
	Wert = Data.GW.x; // Winkel X
	Funk_Data[ 8] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[ 9] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[10] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[11] = Wert & 0x000000FF;
	Wert = Data.GW.y; // Winkel Y
	Funk_Data[12] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[13] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[14] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[15] = Wert & 0x000000FF;
	Wert = Data.GW.z; //  Winkel Z
	Funk_Data[16] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[17] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[18] = Wert & 0x000000FF; Wert = Wert >> 8;
	Funk_Data[19] = Wert & 0x000000FF;

}


Gyro_Werte Hardware::LeseBeschleunigungWerte()
{
	Gyro_Werte Werte;
	Werte.x = Gyro_Sensor->getAngleX();
	Werte.y = Gyro_Sensor->getAngleY();
	Werte.z = Gyro_Sensor->getAngleZ();
	Werte.T = Gyro_Sensor->getTemp();
	return Werte;
}

