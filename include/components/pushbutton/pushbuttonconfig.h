#ifndef PUSHBUTTONCONFIG_H
#define PUSHBUTTONCONFIG_H

#include <fcntl.h> // O_RDONLY

/** Initialize the GPIO of the pushbutton (IO4).
  * @param: {void}.
  * @return: {int} status of the operation.
  */
int initPushbutton();

/** Open the gpio6 which the pushbutton is placed in (IO4).
  * @param: {void}.
  * @return: {int} file descriptor of the pushbutton.
  */
int openPushbutton();

/** Open the gpio6 which the pushbutton is placed in (IO4).
  * @param: {const char*} polling edge (falling, rising, none, both).
  * @return: {int} status of the operation.
  */
int setPollEdge(const char* edge);

/** Unexport the pins used for the pushbutton (IO4).
  * @param: {void}.
  * @return: {int} status of the operation.
  */
int closePushButton();

#endif
