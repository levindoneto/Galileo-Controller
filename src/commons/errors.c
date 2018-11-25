#include "../../include/commons/errors.h"

void throwError(const char *msg) {
    perror(msg);
    exit(ERROR);
}
