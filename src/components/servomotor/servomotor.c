#include  "../../../include/components/servomotor/servomotor.h"

int turnOnServomotorDegrees(double degrees) {
    int duty_cycle;
    duty_cycle = degreesToRads(degrees)/M_PI_2*850000+1500000;
    setDutycycle(duty_cycle);

    return SUCCESS;
}

int turnOnServomotorRads(double radians) {
    int duty_cycle;
    duty_cycle = radians/M_PI_2*850000+1500000;
    setDutycycle(duty_cycle);

    return SUCCESS;
}
