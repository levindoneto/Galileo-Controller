#ifndef LED_H
#define LED_H

#include "ledconfig.h"

/** Turn on the LED.
  * @param: {int} led's file descriptor.
  * @return: {void}.
  */
void turnOnLed(int ledFileDescriptor);

/** Turn off the LED.
  * @param: {int} led's file descriptor.
  * @return: {void}.
  */
void turnOffLed(int ledFileDescriptor);

/** Get value from the led.
  * @param: {int} led's file descriptor.
  * @return: {int} logical value (LED_ON=1, LED_OFF=0).
  */
int getLedStatus(int ledFileDescriptor);

#endif
