// oneMHz
// 
// Demonstrate use of the DueDDS Library
// m0xpd
// March 2014

// include the SPI library:
#include <SPI.h>
// and the new DueDDS Library:
#include <DueDDS.h>
//======================================
// AD9850 Module....
// set pin numbers:
const int FQ_UD = 36;        // any IO port
const int RESET = 40;        // any IO port
// Remember:
// W_CLOCK <=> SCK
// FQ_UD <=> MISO
const int SlaveSelect = 52;  // 4, 10 or 52
double freq = 1000000;

  // Instantiate the DDS...
  DueDDS dds(FQ_UD, RESET, SlaveSelect);

void setup() {
  // start up the DDS...   
  dds.init();  
  // (Optional) trim if your xtal is not at 125MHz...
  dds.trim(125000000); // enter actual osc freq 
  // start the oscillator...
  dds.setFrequency(freq);  
}

void loop() {
}
