#ifndef ERRORS_H
#define ERRORS_H

#include <stdlib.h>
#include <errno.h>
#include "status.h"

/**
  * Function for showing a error message to the user.
  * @param:  {const char *} error message.
  * @return: {void}.
  */
void throwError(const char *errorMessage);

/**
  * Function for showing a error message to the user and returning an error
  * without stopping the program.
  * @param:  {const char *} error message.
  * @return: {int} ERROR status.
  */
int showError(const char *errorMessage);

#endif
