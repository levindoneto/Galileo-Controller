#ifndef BUZZER_H
#define BUZZER_H

#include "../../galileo/pwm.h"

/** Enable the PWM, set default period and set duty cycle to zero.
  * @param:  {int} init duty cycle.
  * @return: {int} status of the operation.
  */
int setupBuzzer(int initDutyCyclePercent);

#endif
