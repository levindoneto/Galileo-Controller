#include  "../../../include/components/servomotor/servomotor.h"

int turnOnServomotorDegrees(int pwmPeriodNs, double degrees) {
    double angle = degrees * M_PI/180.0; // Convert into rads
    // 850.000 = used for conversion into frequency
    // 1.500.000ns = 1.500 us = frequency in anticlockwise
    int dutyCycle = angle/M_PI_2*850000+1500000;
    setPeriodPWM(pwmPeriodNs);
    setDutycycle(dutyCycle);
    enablePWM();
    sleep(1); // 1 second of sleeping before unabling the PWM
    unablePWM();
    return SUCCESS;
}

int turnOnServomotorRads(int pwmPeriodNs, double radians) {
    int dutyCycle = radians/M_PI_2*850000+1500000;
    setPeriodPWM(pwmPeriodNs);
    setDutycycle(dutyCycle);
    enablePWM();
    sleep(1); // 1 second of sleeping before unabling the PWM
    unablePWM();

    return SUCCESS;
}
