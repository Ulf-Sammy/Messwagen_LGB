#pragma once
#include <Arduino.h>
#include "IO_PIN.h"
#include <Wire.h>
#include "MPU6050.h"


class Hardware
{
public:
	Hardware();
	~Hardware();
	void Begin();
	int LeseSpannung();

	void Sende_Werte(SendData Data);
	
	Gyro_Werte LeseBeschleunigungWerte();

protected:
	MPU6050 *Gyro_Sensor;
	byte Funk_Data[FUNK_nr];
	SendData SendeDaten;
};

