#ifndef BUZZER_H
#define BUZZER_H

#include "../../galileo/pwm.h"
#include "buzzerconfig.h"

#define DC_TONE1 1500000
#define DC_TONE2 550000

/** Emity a sound in the buzzer regarding a frequency in Hertz.
  * @param:  {int} frequency.
  * @return: {int} status of the operation.
  */
int emitSound(int frequency);

#endif
