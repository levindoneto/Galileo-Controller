#ifndef LEDCONFIG_H
#define LEDCONFIG_H

#include <fcntl.h>
#include <unistd.h>
#include "ledstatus.h"

/** Initialize the GPIO of the led (IO6).
  * @param:  {void}.
  * @return: {int} led's file descriptor.
  */
int initLed();

/** Close led's pseudofile (IO6).
  * @param:  {int} file descriptor of the gpio which corresponds to the IO6.
  * @return: {int} status of closing the led's pseudofile.
  */
int closeLed(int ledFileDescriptor);

#endif
