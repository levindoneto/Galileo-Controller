#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <unistd.h> // sleep(int seconds)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/datetime.h"
#include "commons/status.h"
#include "../include/components/display/lcd.h"
#include "../include/components/pushbutton/pushbutton.h"
#include "../include/components/pushbutton/configTx.h"
#include "../include/components/pushbutton/configRx.h"
/** Break the flow of execution on the main loop.
  * @param:  {int} running signal.
  * @return: {void}.
  */
void quit(int signal);

#endif
