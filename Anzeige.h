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
	void Zeichne_Anzeige();
	void NextMenue(bool M);

	void ZeigeSendedaten();
	SendData BerechneNeueDaten(unsigned int diff_imp, unsigned long Zeitinterwall, int D_Spannung);
	void FuelleKurve(byte Power_Data, byte Speed_Data);

protected:
	const double HalberUmfang = 31 * M_PI_2; // U = Pi/2 *31   {U = Pi * d}

	unsigned int Messimpulse;
	unsigned int Streckegefahren; // in mm
	double Messgeschwindigkeit; // in mm/sec

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
	byte KurvePower[129];
	byte KurveSpeed[129];

	char * Zeile(char* TA, double N, char* TC);
	char * Zeile(char* TA, unsigned int N, char* TC);
	char * Zeile(char* TA, byte N, char* TC);
	char * ZeileV(char* TA, byte N, char* TC);
private:
};

