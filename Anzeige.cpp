#include "Anzeige.h"

Anzeige::Anzeige()
{
	Display = U8X8_ST7565_ERC12864_4W_HW_SPI(PIN_CS, PIN_DC, PIN_RESET); ///* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9)
	for (int i = 0; i < 128; i++)
	{
		KurvePower[i] = 0;
		KurveSpeed[i] = 0;
	}
	Menue = (MenuAnzeige)0;
	Max_Geschwindigkeit = 0;
	Min_Geschwindigkeit = 1000;
	update = true;
	Geschwindigkeit = 200;
	MessSpannung = 180;
	Messimpulse = 0;
}

Anzeige::~Anzeige()
{
}

void Anzeige::Begin()
{
	Display.begin();
	Display.setContrast(21);

	Display.setFont(FONT_k);
	Display.drawString(0, 0,"starte Messwagen!");
	Display.drawString(0, 2,"   Version 1.0   ");
	Display.drawString(0, 4,"   is booting    ");
	/*
	Display.drawString(0, 6, ".               "); 
	Display.drawString(0, 6, "..!             "); 
	Display.drawString(0, 6, "...!            "); 
	Display.drawString(0, 6, "....!           "); 
	Display.drawString(0, 6, ".....!          "); 
	Display.drawString(0, 6, "......!         "); 
	Display.drawString(0, 6, ".......!        "); 
	Display.drawString(0, 6, ".........!      "); 
	Display.drawString(0, 6, "..........!     "); 
	Display.drawString(0, 6, "...........!    "); 
	Display.drawString(0, 6, "............!   "); 
	Display.drawString(0, 6, ".............!  "); 
	Display.drawString(0, 6, "..............! "); 
	Display.drawString(0, 6, "...............!"); 
	*/
}

void Anzeige::NextMenue(bool M)
{
	if (M)
	{
		if ((MenuAnzeige)Menue == Setup) 
			Menue = 0;
		else 
			Menue++;
		delay(250);
		update = true;
	}
}

void Anzeige::ZeigeSendedaten()
{
	update = true;
}

SendData Anzeige::BerechneNeueDaten(unsigned int diff_imp, unsigned long Zeitinterwall, int DSpannung)
{
	
	SendData SendeDaten;
	Messimpulse = Messimpulse + diff_imp;
	SendeDaten.Nr = Messimpulse;

	MessSpannung = DSpannung * (200 / 255);
	SendeDaten.Po = MessSpannung;

	Streckegefahren = (HalberUmfang * Messimpulse + 0.5);
	Messgeschwindigkeit = (HalberUmfang * diff_imp + 0.5) * 1000 / Zeitinterwall; // mm /sec
	Geschwindigkeit = (Messgeschwindigkeit * 792 / 10000) + 0.5;// Speed in km/h
	SendeDaten.Sp = Geschwindigkeit;

	Mitt_Geschwindigkeit = (Mitt_Geschwindigkeit + Geschwindigkeit) / 2;
	Max_Geschwindigkeit = max(Geschwindigkeit, Max_Geschwindigkeit);
	Min_Geschwindigkeit = min(Geschwindigkeit, Min_Geschwindigkeit);

	Max_Spannung = max(MessSpannung, Max_Spannung);
	Min_Spannung = min(MessSpannung, Min_Spannung);
	update = true;
}

void Anzeige::FuelleKurve(byte Power_Data, byte Speed_Data)
{
	byte PO_V = Power_Data * (32 / 1023);
	byte SP_V = Speed_Data * (32 / 200);
	for (byte i = 128; i > 0; i--)
	{
		KurvePower[i] = KurvePower[i - 1];
		KurveSpeed[i] = KurveSpeed[i - 1];
	}
	KurvePower[0] = PO_V;
	KurveSpeed[0] = SP_V;
}

char *Anzeige::Zeile(char* TA, double N, char* TC)
{
	static char Text[17];
	char TB[7];
	Text[0] = 0;
	dtostrf(N, 6, 2, TB);
	strcat(Text, TA);
	strcat(Text, TB);
	strcat(Text, TC);

	return Text;
}

char* Anzeige::Zeile(char* TA, unsigned int N, char* TC)
{
	static char Text[17];
	char TB[7];
	Text[0] = 0;
	dtostrf(N, 6, 0, TB);
	strcat(Text, TA);
	strcat(Text, TB);
	strcat(Text, TC);

	return Text;
}

char* Anzeige::Zeile(char* TA, byte N, char* TC)
{
	static char Text[17];
	char TB[4];
	sprintf(TB, " %3d", N);
	Text[0] = 0;
	strcat(Text, TA);
	strcat(Text, TB);
	strcat(Text, TC);

	return Text;
}

char* Anzeige::ZeileV(char* TA, byte N, char* TC)
{
	static char Text[17];     //  01234
	char TB[5];               // " 18.0"
	sprintf(TB, " %3d ", N);
 	TB[4] = TB[3];
	TB[3] = '.';
	Text[0] = 0;
	strcat(Text, TA);
	strcat(Text, TB);
	strcat(Text, TC);

	return Text;
}


void Anzeige::Zeichne_Anzeige()
{
	char Buffer[20];
	uint8_t Title[8];
	uint8_t tiles1[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
	uint8_t tiles2[8] = { 2, 2, 2, 2, 2, 2, 2, 2 };
	uint8_t tiles3[8] = { 4, 4, 4, 4, 4, 4, 4, 4 };
	byte Z;

	if (update)
	{
		Display.setFont(FONT_k);
		Display.clearDisplay();

		switch ((MenuAnzeige)Menue)
		{
		case Start:
			Display.draw1x2String(0, 0,"Anzeige Start");
			//              "01234567890123456789"
			// 2             "- Impulse 123456    "
			Display.drawString(0, 2, Zeile(" -  ", Messimpulse," Imp."));

			// 3             "-     123456 mm"	
			Display.drawString(0, 3, Zeile(" -  ", Streckegefahren, " mm"));

			// 4             "- 123456 mm/sec"  Messgeschwindigkeit
			Display.drawString(0, 4, Zeile(" -  ",  Messgeschwindigkeit, " mm/sec" ));

			// 5             "- 123 km/h"
			Display.drawString(0, 5, Zeile(" -    ", Geschwindigkeit, " km/h "));

			// 6              " 20.0 V ");
			Display.drawString(0, 6, ZeileV(" -   ", MessSpannung, " V"));
	
			break;
		case Messen_Z_SP:
			// Serial.print(Zeile("", Geschwindigkeit, ""));

			sprintf(Buffer, "%4d", Geschwindigkeit);
			Display.setFont(FONT_g);
			Display.drawString(0, 2, Buffer);

			Display.setFont(FONT_k);
			Display.draw1x2String(0, 0, "4. Geschwind.");
			Display.drawString(0, 7, "    in [km/h]");

			break;
		case Messen_Z_PO:

			Display.setFont(FONT_g);
			Display.drawString(0, 2, ZeileV("", MessSpannung, ""));

			Display.setFont(FONT_k);
			Display.draw1x2String(0, 0, "4. Spannung  ");
			Display.drawString(0, 7, "    U in [V]");
			break;
		case Kurve_SP:
			Display.drawString(0, 0, "3 Messen KSP ");
			Display.drawTile(0, 3, 1, tiles1);
			Display.drawTile(1, 3, 1, tiles2);
			Display.drawTile(2, 3, 1, tiles3);
			Display.drawTile(3, 3, 1, tiles1);
			Z = 1;
			for (byte j = 0; j < 8; j++)
			{
				for (byte i = 0; i < 8; i++)
				{
					
					Title[i] = Z;
				}
				Display.drawTile(j, 3, 1, Title);
				Z = Z << 1;
			}
			break;
		case Kurve_PO:
			Display.drawString(0, 0, "4 Messen KPO ");
			
			break;
		case Kurve_SP_PO:
			Display.drawString(0, 0, "5 Kurve SP&PO");
			break;
		case Statistik:
			Display.draw1x2String(0, 0, "6 Statistik  ");
			                        //012345678901234567
			Display.drawString(0, 2, "Max Geschwindig.");
			Display.drawString(0, 3, "Min Geschwindig.");
			Display.drawString(0, 4, "================");
			Display.drawString(0, 5, "Max Spannung.");
			Display.drawString(0, 6, "Min Spannung.");
			// Max Gesch
			// Min Gesch
			// Max Spannung
			// Min Spannung
			break;
		case Setup:
			Display.drawString(0, 0, "7 Setup     ");
			break;
		default:
			break;
		}
		update = false;
	}
}
