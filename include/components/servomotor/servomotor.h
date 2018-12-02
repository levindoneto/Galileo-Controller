#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <unistd.h> // sleep(int seconds)
#include "../../commons/status.h"
#include "../../galileo/pwm.h"

/** Rotate the servomotor clockwise when degrees<0 and anticlockwise otherwise.
  * @param:  {int} pwm period in ns.
             {double} degrees.
  * @return: {int} status of the operation.
  */
int turnOnServomotorDegrees(int pwmPeriodNs, double degrees);

/** Rotate the servomotor by a number of radians factor.
  * @param:  {int} pwm period in ns.
             {double} radians.
  * @return: {int} status of the operation.
  */
int turnOnServomotorRads(int pwmPeriodNs, double radians);

#endif
