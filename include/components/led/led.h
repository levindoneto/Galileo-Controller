#ifndef LED_H
#define LED_H

#include "ledconfig.h"

/** Turn on the LED.
  * @param: {void}.
  * @return: {void}.
  */
void turnOnLed();

/** Get value from the led.
  * @param: {void}.
  * @return: {int} logical value (LED_ON=1, LED_OFF=0).
  */
int getLedStatus();

#endif
