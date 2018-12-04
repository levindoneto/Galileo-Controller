#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <unistd.h> // sleep(int seconds)
#include "../../commons/status.h"
#include "../../galileo/pwm.h"
#include "../../utils/conversion/measurement_conversion.h"

/** Rotate the servomotor clockwise when degrees<0 and anticlockwise otherwise.
  * @param:  {double} degrees.
  * @return: {int} status of the operation.
  */
int turnOnServomotorDegrees(double degrees);

/** Rotate the servomotor by a number of radians factor.
  * @param:  {double} radians.
  * @return: {int} status of the operation.
  */
int turnOnServomotorRads(double radians);

#endif
