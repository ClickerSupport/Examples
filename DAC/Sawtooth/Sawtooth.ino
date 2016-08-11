/* 
 * Generate a triangle wave on the DAC Click. Relies on the MCPDAC library
 * 
 * * https://github.com/MajenkoLibraries/MCPDAC
 */

#include <SPI.h>
#include <MCPDAC.h>

void setup()
{
  // CS on pin 10, no LDAC pin (tie it to ground).
  MCPDAC.begin(PIN_C1_CS);
  
  // Set the gain to "LOW" mode - 0 to 2048mV.
  MCPDAC.setGain(CHANNEL_A,GAIN_LOW);
  
  // Do not shut down channel A, but shut down channel B.
  MCPDAC.shutdown(CHANNEL_A,false);
}

void loop()
{
  static unsigned int volts = 0;
  
  // Set the voltage of channel A.
  MCPDAC.setVoltage(CHANNEL_A,volts&0x0fff);

  // Increase the voltage in steps of 100mV.
  volts+=100;
}
