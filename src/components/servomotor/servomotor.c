#include  "../../../include/components/servomotor/servomotor.h"

int turnOnServomotorDegrees(double degrees) {
    int duty_cycle;
    float angle = degrees * M_PI/180.0;
    printf("\nAngle: %f\n", angle);
    duty_cycle = angle/M_PI_2*850000+1500000;
    printf("\nduty_cycle: %d\n", duty_cycle);
    setDutycycle(duty_cycle);

    return SUCCESS;
}

int turnOnServomotorRads(double radians) {
    printf("TO DO");

    return SUCCESS;
}
