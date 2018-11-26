#ifndef ERRORS_H
#define ERRORS_H

#include <errno.h>
#include "status.h"

/**
  * Function for showing a error message to the user.
  * @param: {const char *} error message.
  * @return: {void}.
  */
void throwError(const char *errorMessage);

#endif
