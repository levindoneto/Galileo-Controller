#ifndef LDC_H
#define LDC_H

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/ioctl.h>
#include <i2cutil.h>
#include <jhdlcd.h>
#include <backlightConfig.h>
#include <lcdConfig.h>
#include <errors.h>
#include <status.h>

/** Write a message on the LCD display.
  * @param: {const char*} text to be displayed.
  * @return: {int} status of the writing to the display LCD.
  */
int writeDisplay(const char* textToWrite)
