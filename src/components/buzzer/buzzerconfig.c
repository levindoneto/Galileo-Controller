#include  "../../../include/components/buzzer/buzzerconfig.h"

int setupBuzzer(int initDutyCyclePercent) {
    enablePWM();
    setPeriodPWM(PWM_DEFAULT_PERIOD);
    return setDutycyclePercent(initDutyCyclePercent);
}
