#ifndef BACKLIGHTCONFIG_H
#define BACKLIGHTCONFIG_H

#include <data.h>
#include <errors.h>
#include <status.h>

/** Initialize the backlight of the LCD display.
  * @param: {int} file descriptor.
  * @return: {void}.
  */
void initBacklight(int i2cFileDescriptor);
