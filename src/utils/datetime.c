#include "../../include/utils/datetime.h"

long int getCurrentTimeTimestamp() {
    return (unsigned long)time(NULL);
}

char* getCurrentTimeISO() {
    time_t t     = time(NULL);
    struct tm tm = *localtime(&t);
    static char timeBuffer[10]; // hh:mm:ss\0
    const char* formatTime = "%d:%d:%d";
    sprintf(timeBuffer, formatTime, tm.tm_hour, tm.tm_min, tm.tm_sec);

    return (char*) timeBuffer;
}

char* getCurrentDateISO() {
    time_t t     = time(NULL);
    struct tm tm = *localtime(&t);
    static char dateBuffer[12]; // dd/mm/yyyy\0
    const char* formatDate = "%d/%d/%d";
    sprintf(dateBuffer, formatDate, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    return (char*) dateBuffer;
}
