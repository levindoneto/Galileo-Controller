#ifndef configTx_H
#define configTx_H

#include <fcntl.h> // O_RDONLY

/** Open the gpio6 which the pushbutton is placed in (IO4).
  * @param: {void}.
  * @return: {int} file descriptor of the pushbutton.
  */
int openAckTx();

/** Open the gpio6 which the pushbutton is placed in (IO4).
  * @param: {const char*} polling edge (falling, rising, none, both).
  * @return: {int} status of the operation.
  */
int setPollEdgeTx(const char* edge);

/** Unexport the pins used for the pushbutton (IO4).
  * @param: {void}.
  * @return: {int} status of the operation.
  */
int closeAckTx();

#endif
