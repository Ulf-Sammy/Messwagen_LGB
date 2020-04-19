/*
    Name:       Messwagen_LGB.ino
    Created:	28.12.2019 17:50:53
    Author:     SNOOPY\Ulf
	Spannung messen und funken
*/

#include "IO_PIN.h"
#include "Anzeige.h"
#include "Hardware.h"

Hardware MessWagen;
Anzeige Display;
SendData SendeDaten;
unsigned long Z1;
//unsigned long mZ1, mZ2;
byte Messimpulse; // von der Lichtschranke

int D_Spannung;


void setup()
{
	Serial.begin(115200);
	Serial.flush();
	Serial.println(" Starte Messwagen !");
	MessWagen.Begin();
	Display.Begin();

	Messimpulse = 0 ;
	attachInterrupt(digitalPinToInterrupt(PIN_TAKTRAD), behandle_interupt, RISING);
}


void loop()
{

	Display.NextMenue(Taste_Pushed(PIN_TASTE_R));
	Display.Zeichne_Anzeige();
	if (Messimpulse > 0)
	{

		//mZ1 = millis();
			if (Display.StarteMessung(Z1))
			{
				Messimpulse = 0;
			}
			else
			{
				SendeDaten = Display.BerechneNeueDaten(Messimpulse, Z1 , D_Spannung);
				MessWagen.Sende_Werte(SendeDaten);
			}
		//mZ2 = millis();
		//Serial.println(mZ2 - mZ1);	
	}
}



void behandle_interupt()
{
	Z1 = millis();
	D_Spannung = MessWagen.LeseSpannung();
	Messimpulse++;
}