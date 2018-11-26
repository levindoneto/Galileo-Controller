#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/ioctl.h>
#include "../../galileo/i2cutil.h"
#include "../../galileo/jhdlcd.h"
#include "../../commons/errors.h"
#include "../../commons/status.h"

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

#endif
