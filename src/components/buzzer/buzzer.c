#include  "../../../include/components/buzzer/buzzer.h"

int emitSound(int frequency) {
    return setPeriodPWM(intToString(hzToNs(frequency)));
    //return setDutycyclePercent(dutyCycle); // init pwm with 0 duty cycle
}
