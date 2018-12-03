#ifndef EEPROM_H
#define EEPROM_H

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include "../libgalileo/i2cutil.h"
#include "../commons/errors.h"

/** Write a string into the Galileo's EEPROM.
  * @param:  {char*} string text to be written.
  * @return: {int} status of the operation.
  */
int writeToEeprom(char* text);

/** Read a string from the Galileo's EEPROM.
  * @param:  {void}.
  * @return: {char*} read string.
  */
char* readFromEeprom();

#endif
