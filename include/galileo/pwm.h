#ifndef PWM_H
#define PWM_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libgalileo/galileo2io.h"
#include "commons/status.h"

#define PWM_MAX_PERIOD     41600000 // in ns
#define PWM_MIN_PERIOD     656000   // in ns
#define PWM_DEFAULT_PERIOD 20000000 // in ns

/** Get the period(ns) set in the PWM_1 (IO3).
  * @param:  {void}.
  * @return: {int} period in nanoseconds.
  */
int getPeriodPWM();

/** Set period(ns) in the PWM_1 (IO3).
  * @param:  {int} period in nanoseconds.
  * @return: {int} status of the operation.
  */
int setPeriodPWM(int periodInNanoseconds);

/** Set duty cycle (ns) in the PWM_1 (IO3).
  * @param:  {int} duty cycle.
  * @return: {int} status of the operation.
  */
int setDutycycle(int dutyCycle);

/** Set duty cycle (%) in the PWM_1 (IO3).
  * @param:  {int} percent duty cycle.
  * @return: {int} status of the operation.
  */
int setDutycyclePercent(int percentDutyCycle);

/** Enable the GalileoGen2's PWM_1 (IO3).
  * @param:  {void}.
  * @return: {int} status of the operation.
  */
int enablePWM();

/** Disable the GalileoGen2's PWM_1 (IO3).
  * @param:  {void}.
  * @return: {int} status of the operation.
  */
int disablePWM();

#endif
