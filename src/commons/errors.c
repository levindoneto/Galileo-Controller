static void throwError(const char *msg) {
    perror(msg);
    exit(-errno);
}
