/*
  DueDDS.cpp - Library for hosting an AD9850 DDS Module
  on the Arduino DUE under hardware SPI.
  Created by m0xpd, March 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SPI.h"
#include "DueDDS.h"



DueDDS::DueDDS(int FQ_UD, int RESET, int SS)
{
	_FQ_UD = FQ_UD;
	_RESET = RESET;
	_SS = SS;
	_TrimFreq = 125000000;
}

void DueDDS::setFrequency(double frequency)
{
  int32_t freq = frequency * 4294967295/_TrimFreq;
  for (int b=0; b<4; b++, freq>>=8) {
    byte response = SPI.transfer(_SS, freq & 0xFF);
  } 
  byte response = SPI.transfer(_SS, 0x00);
  pulseHigh(_FQ_UD);
}

void DueDDS::init()
{
	init_priv();
}

void DueDDS::init_priv()
{
	pinMode(_FQ_UD, OUTPUT);
	pinMode(_RESET, OUTPUT);
	SPI.begin(_SS);
  	SPI.setClockDivider(_SS, 4);
  	SPI.setBitOrder(_SS, LSBFIRST);
  	SPI.setDataMode(_SS, SPI_MODE0);
  	pulseHigh(_RESET);
  	pulseHigh(_FQ_UD);  
        setFrequency(0); 
}

void DueDDS::trim(double TrimFreq)
{
	_TrimFreq=TrimFreq;
}

// Subroutine to generate a positive pulse on 'pin'...
void DueDDS::pulseHigh(int _pin) 
{
digitalWrite(_pin, HIGH);
digitalWrite(_pin, LOW); 
}
