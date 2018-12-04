#ifndef MEASUREMENT_CONVERSION_H
#define MEASUREMENT_CONVERSION_H

#include <math.h>

/** Convert degrees to radians.
  * @param:  {double} degrees.
  * @return: {double} radians.
  */
double degreesToRads(double degrees);

/** Convert radians to degrees.
  * @param:  {double} radians.
  * @return: {double} degrees.
  */
double radsToDegrees(double rads);

/** Convert time in seconds to nanoseconds.
  * @param:  {int} time in seconds.
  * @return: {int} time in ns.
  */
int secToNs(int seconds);

/** Convert frequency in Hz to time in nanoseconds.
  * @param:  {int} frequency.
  * @return: {int} time.
  */
int hzToNs(int frequency);

#endif
