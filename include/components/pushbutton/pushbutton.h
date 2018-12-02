#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libgalileo/galileo2io.h"
#include "commons/status.h"
#include "pushbuttonconfig.h"

/** Get value from pushbutton by polling the GPIO which it is in (IO4).
  * @param: {void}.
  * @return: {int} logical value (pressed=1, not_pressed=0).
  */
int getPushbuttonValue();

#endif
