#include  "../../../include/utils/conversion/measurement_conversion.h"

double degreesToRads(double degrees) {
    return degrees * M_PI / 180.0;
}

double radsToDegrees(double rads) {
    return rads * 180.0 / M_PI;
}
