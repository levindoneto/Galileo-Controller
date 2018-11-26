#ifndef BACKLIGHTCONFIG_H
#define BACKLIGHTCONFIG_H

#include "../../commons/data.h"
#include "../../commons/errors.h"
#include "../../commons/status.h"
#include "lcdconfig.h"

/** Initialize the backlight of the LCD display.
  * @param: {int} file descriptor.
  * @return: {void}.
  */
void initBacklight(int i2cFileDescriptor);

#endif
