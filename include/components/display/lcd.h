#ifndef LDC_H
#define LDC_H

#include "backlightconfig.h"
#include "lcdconfig.h"
#include "../../commons/errors.h"
#include "../../commons/status.h"

#define FIRST_ROW_LCD 0
#define SECOND_ROW_LCD 0x40

/** Write a message on the LCD display.
  * @param: {int} file descriptor.
            {const char*} text to be displayed in the 1st line.
            {const char*} text to be displayed in the 2nd line.
  * @return: {int} status of the writing to the display LCD.
  */
  int writeDisplay(int fileDescriptor, const char* textToWriteLine0,
                   const char* textToWriteLine1);

#endif
