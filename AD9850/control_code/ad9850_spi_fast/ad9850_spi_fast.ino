#include <AD9850SPI.h>
#include <SPI.h>

const int W_CLK_PIN = 13;
const int FQ_UD_PIN = 8;
const int RESET_PIN = 9;

// Arduino Pin->11 to DDS Pin->7 for DATA line in SPI comm

double freq = 100;              // 1Hz signal of sine or sq, sine level is lower than square
double trimFreq = 124999500;  // Clock freq in double format

int phase = 0;

void setup(){
  DDS.begin(W_CLK_PIN, FQ_UD_PIN, RESET_PIN);
  DDS.calibrate(trimFreq);
}

void loop(){
  DDS.setfreq(freq, phase);   // Set frequency and phase of the signal
  delay(10000);
//  DDS.down();
//  delay(3000);
//  DDS.up();
//  delay(2000);
//  DDS.setfreq(freq + 500, phase);
//  delay(5000);
//  DDS.down();
  while(1);
}
