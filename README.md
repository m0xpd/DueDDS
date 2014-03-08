DueDDS
======

A Library to host an AD9850 DDS Module on Arduino DUE, using hard SPI

This is a library which controls the widely available, low-cost Direct Digital Synthesis Modules,
based on the Analog Devices 9850 chip
on the Arduino Due.

Uses the Due's enhanced hardware SPI capability

The module's W_CLOCK line and DATA line are connected to SCK and MISO respectively on the SPI header. 
Two IO lines are required for the other "control lines" to the AD9850 module (RESET & FQ_UD).
A further "Slave Select" line (one of lines 4, 10, or 52) is nominated but not used.
