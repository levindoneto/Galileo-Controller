#include <errors.h>

static void throwError(const char *msg) {
    perror(msg);
    exit(-errno);
}
