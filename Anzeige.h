#pragma once

#include <SPI.h>
#include "IO_PIN.h"
#include "U8x8lib.h"

#define FONT_k u8x8_font_torussansbold8_r //u8x8_font_chroma48medium8_r
#define FONT_g u8x8_font_inr33_3x6_n

enum MenuAnzeige { Start, Messen_Z_SP, Messen_Z_PO, Kurve_SP, Kurve_PO, Kurve_SP_PO, Statistik, Setup };


class Anzeige
{
public:
	Anzeige();
	~Anzeige();
	void Begin();
	bool StarteMessung(unsigned long Zeit); 
	void Zeichne_Anzeige();
	void NextMenue(bool M);

	SendData BerechneNeueDaten(byte &Impuse, unsigned long Zeit_1, int D_Spannung);
	void FuelleKurve(byte Power_Data, byte Speed_Data);

protected:
	unsigned int Messimpulse;
	unsigned int Streckegefahren; // in mm
	unsigned int Messgeschwindigkeit; // in mm/sec
	byte NeueImpulse;
	unsigned long NeuStrecke;

	unsigned long alte_Zeit;
	double Zeitinterwall; 

	bool StartOnce;
	bool StopOnce;
	bool ERROR_IMP;
	byte ER_ImP;

	byte   Geschwindigkeit; // km/h
	byte Max_Geschwindigkeit;  // max in km/h
	byte Min_Geschwindigkeit;  // min in  km/h
	byte Mitt_Geschwindigkeit; // mittlere in km/h
	
	byte MessSpannung; // in V max 200 ~ 20.0
	byte Max_Spannung; // max V
	byte Min_Spannung; // min V
	byte Mitt_Spannung; // mittlere V

	unsigned int Menue;
	bool update;
	U8X8 Display;
	//byte KurvePower[129];
	//byte KurveSpeed[129];

	char * Zeile(char* TA, double N, char* TC);
	char * Zeile(char* TA, unsigned int N, char* TC);
	char * Zeile(char* TA, byte N, char* TC);
private:
};

