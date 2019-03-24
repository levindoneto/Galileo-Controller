#ifndef configRx_H
#define configRx_H

#include <fcntl.h> // O_RDONLY

/** Open the gpio6 which the pushbutton is placed in (IO4).
  * @param: {void}.
  * @return: {int} file descriptor of the pushbutton.
  */
int openClkRx();

/** Open the gpio6 which the pushbutton is placed in (IO4).
  * @param: {const char*} polling edge (falling, rising, none, both).
  * @return: {int} status of the operation.
  */
int setPollEdgeRx(const char* edge);

/** Unexport the pins used for the pushbutton (IO4).
  * @param: {void}.
  * @return: {int} status of the operation.
  */
int closeClkRx();

#endif
