/*
  DueDDS.h - Library for hosting an AD9850 DDS Module
  on the Arduino DUE under hardware SPI.
  Created by m0xpd, March 2014.
  Released into the public domain.
*/
#ifndef DueDDS_h
#define DueDDS_h

#include "Arduino.h"

class DueDDS
{
	public:
	DueDDS(int FQ_UD, int RESET, int SS);
	void setFrequency(double frequency);
	void init();
	void trim(double TrimFreq);
	private:
	void pulseHigh(int _pin);
	int _FQ_UD;
	int _RESET;
	int _SS;
	double _TrimFreq;
	void init_priv();
};

#endif
