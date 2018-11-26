#ifndef LDC_H
#define LDC_H

#include "backlightconfig.h"
#include "lcdconfig.h"
#include "../../commons/errors.h"
#include "../../commons/status.h"

/** Write a message on the LCD display.
  * @param: {const char*} text to be displayed.
  * @return: {int} status of the writing to the display LCD.
  */
int writeDisplay(const char* textToWrite);

#endif
