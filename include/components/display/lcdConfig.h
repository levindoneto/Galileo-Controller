#include <errors.h>
#include <time.h>
#include <status.h>

#ifndef LDCCONFIG_H
#define LDCCONFIG_H

/** Initialize the the LCD display.
  * @param: {int} file descriptor.
  * @return: {void}.
  */
void initDisplay(int i2cFileDescriptor);

/** Prepare the LCD display to receive data.
  * @param: {int} file descriptor.
  * @return: {void}.
  */
void prepareDisplay(int i2cFileDescriptor);
