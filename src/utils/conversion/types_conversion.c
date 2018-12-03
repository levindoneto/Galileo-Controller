#include  "../../../include/utils/conversion/types_conversion.h"

char* intToString(int intValue) {
    char stringBuffer[32]; // hh:mm:ss\0
    snprintf(stringBuffer, sizeof(stringBuffer), "%d", intValue);
    return (char*) stringBuffer;
}

char* longToString(long longValue) {
    char stringBuffer[64];
    snprintf(stringBuffer, sizeof(stringBuffer), "%ld", longValue);
    return (char*) stringBuffer;
}

char* floatToString(float floatValue) {
    char stringBuffer[32];
    snprintf(stringBuffer, sizeof(stringBuffer), "%f", floatValue);
    return (char*) stringBuffer;
}

char* doubleToString(double doubleValue) {
    char stringBuffer[64];
    snprintf(stringBuffer, sizeof(stringBuffer), "%lf", doubleValue);
    return (char*) stringBuffer;
}
