#ifndef PWM_H
#define PWM_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/galileo2io.h"

/** Set period(ns) in the PWM_1 (IO3).
  * @param:  {int} period in nanoseconds.
  * @return: {int} status of the operation.
  */
int setPeriodPWM(int periodInNanoseconds);

/** Set duty cycle (ns) in the PWM_1 (IO3).
  * @param:  {int} duty cycle.
  * @return: {int} status of the operation.
  */
int setDutycycle(int dutycycle);

/** Enable the GalileoGen2's PWM_1 (IO3).
  * @param:  {void}.
  * @return: {int} status of the operation.
  */
int enablePWM();

/** Unable the GalileoGen2's PWM_1 (IO3).
  * @param:  {void}.
  * @return: {int} status of the operation.
  */
int unablePWM();

#endif
