#ifndef DATETIME_H
#define DATETIME_H

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/** Get the current timestamp.
  * @param:  {void}.
  * @return: {long int} timestamp.
  */
long int getCurrentTimeTimestamp();

/** Get the current time in a HH:MM:SS format.
  * @param:  {void}.
  * @return: {char*} iso time.
  */
char* getCurrentTimeISO();

/** Get the current date in a DD/MM/YYYY format.
  * @param:  {void}.
  * @return: {char*} iso date.
  */
char* getCurrentDateISO();

#endif
