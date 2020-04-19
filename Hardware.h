#pragma once
#include <Arduino.h>
#include "IO_PIN.h"

#include <VirtualWire_Config.h>
#include <VirtualWire.h>
#include <Wire.h>



class Hardware
{
public:
	Hardware();
	~Hardware();
	void Begin();
	int LeseSpannung();

	void Sende_Werte(SendData Data);
	
	void LeseBeschleunigungwerte();
	void SetzBeschleunigungWerte();
	Mess_Besch LeseBeschleunigungWerte();

protected:
	byte Funk_Data[FUNK_nr];
	byte Besch_Data[MPU6050_DATA_L];
	Mess_Besch Besch_Messung;
	SendData SendeDaten;
};

