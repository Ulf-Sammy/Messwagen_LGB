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

unsigned long Zeitinterwall; // die Zeit zwischen zwei Impulsen
unsigned long Z1, Z2;
unsigned long mZ1, mZ2;
int Messimpulse; // von der Lichtschranke
int alt_Messimpulse;
int DiffImpulse;

int D_Spannung;


void setup()
{
	Serial.begin(115200);
	Serial.flush();
	Serial.println(" Starte Messwagen !");
	MessWagen.Begin();
	Display.Begin();

	Zeitinterwall = 0;
	Messimpulse = -1;
	alt_Messimpulse = -1;
	Z1 = 0;
	Z2 = 0;
	attachInterrupt(digitalPinToInterrupt(PIN_TAKTRAD), behandle_interupt, RISING);
}


void loop()
{

	Display.NextMenue(Taste_Pushed(PIN_TASTE_R));
	Display.Zeichne_Anzeige();
	DiffImpulse = Messimpulse - alt_Messimpulse;
	if (DiffImpulse > 0)
	{
		//mZ1 = millis();
			if (MessWagen.StarteMessung(DiffImpulse))
			{
				Z2 = Z1;
				Messimpulse = 0;
				alt_Messimpulse = 0;
			}
			else
			{
				SendeDaten = Display.BerechneNeueDaten(DiffImpulse, Z1 - Z2, D_Spannung);
				MessWagen.Sende_Werte(SendeDaten);
				Display.ZeigeSendedaten();
				alt_Messimpulse = Messimpulse;
				Z2 = Z1;
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