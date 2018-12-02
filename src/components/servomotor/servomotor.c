#include  "../../../include/components/servomotor/servomotor.h"

int turnOnServomotorDegrees(int pwmPeriodNs, double degrees) {
    printf("TESTING...");
    double angle;
    // Convert into rads
    angle = degrees * M_PI/180.0;
    // 850.000 = used for conversion into frequency
    // 1.500.000ns = 1.500 us = frequency in anticlockwise
    int dutyCycle = angle/M_PI_2*850000+1500000;
    setPeriodPWM(pwmPeriodNs);
    setDutycycle(dutyCycle);
    enablePWM();
    sleep(1);
    unablePWM();
    return 0;
}

int turnOnServomotorRads(int pwmPeriodNs, double radians) {
    printf("TODO");

    return 0;
}
