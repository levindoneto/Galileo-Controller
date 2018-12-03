#include "../../include/commons/errors.h"

void throwError(const char *msg) {
    perror(msg);
    exit(ERROR);
}

int showError(const char *errorMessage) {
    printf("Error: %s\n", errorMessage);
    return ERROR;
}
