#pragma once

// CPU Basis UNO

#define PIN_CLOCK    13 // clock=*/ 13
#define PIN_DATA     11 // data=*/ 11
#define PIN_CS       10 // cs=*/ 10,
#define PIN_RESET    9  // reset=*/ 9
#define PIN_DC		 8  // dc=*/ 8, 
#define PIN_FUNK	 7  //  Daten funken
#define PIN_TASTE_L  A4  // Taste links
#define PIN_TASTE_R  A5  // Taste rechts
#define PIN_REED     4  // Start der Messung
#define PIN_LED		 3  // neue Led Anzeige
#define PIN_TAKTRAD  2   // Strecke messen mit dem Rad
//		PIN_TX		 1
//      PIN_RX		 0
#define PIN_SPANNUNG A0  // Gleis Spannung messen
#define PIN_START	 A1  // Starte Messung Reedrelay
#define PIN_A2		 A2
#define PIN_A3		 A3
#define PIN_SDA		 A4  // Data I²C
#define PIN_SCL		 A5  // Clock I²C
// Funk-Modul
#define FUNK_bps	1000
#define FUNK_nr		4
// Beschleinigungs-Modul
#define MPU6050_ADRESS 0x68
#define MPU6050_DATA_L 14


#define Taste_Pushed(A) digitalRead(A) == LOW
#define TRACE(A) Serial.println(A);
#define TRACE2(A,B) Serial.print(A); Serial.println(B);
#define TRACE3(A,B,C) Serial.print(A); Serial.print(B);Serial.println(C);


struct SendData
{
	unsigned int Nr;
	byte Po;
	byte Sp;
/*
	SendData(unsigned int N,byte P, byte S)
	{
		Nr = N;
		Po = P;
		Sp = S;
	}
*/
};
struct B_Werte
{
	int x;
	int y;
	int z;
};

struct Mess_Besch
{
	B_Werte Bes;
	B_Werte Gyo;
	double  Temp;
};