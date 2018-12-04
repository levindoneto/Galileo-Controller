#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <poll.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include "../../libgalileo/galileo2io.h"
#include "../../commons/status.h"
#include "pushbuttonconfig.h"

#define CLICKED 1
#define NOT_CLICKED 0

// Polling constants
#define INIT 1
#define N_FD_POOLS 1
#define MIN_TIMEOUT_MS 1

/**
  * struct pollfd {
  *     int fd;        // file descriptor
  *     short events;  // requested events
  *     short revents; // returned events
  * };
  */

/** Get click of the pushbutton by the polling made.
  * @param: {int} return from polling.
  * @return: {int} logical value (CLICKED=1, NOT_CLICKED=0).
  */
int getClick(int pollResult);

#endif
