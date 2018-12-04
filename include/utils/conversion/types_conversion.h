#ifndef TYPES_CONVERSION_H
#define TYPES_CONVERSION_H

/** Convert an integer to a string.
  * @param:  {int} value to be converted.
  * @return: {char*} string.
  */
char* intToString(int intValue);

/** Convert a long int to a string.
  * @param:  {long int} value to be converted.
  * @return: {char*} string.
  */
char* longToString(long int longValue);

/** Convert a float to a string.
  * @param:  {float} value to be converted.
  * @return: {char*} string.
  */
char* floatToString(float doubleValue);

/** Convert a double to a string.
  * @param:  {double} value to be converted.
  * @return: {char*} string.
  */
char* doubleToString(double doubleValue);

#endif
