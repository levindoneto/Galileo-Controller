#include  "galileo/pwm.h"

int setPeriodPWM(int periodInNanoseconds) {
    char periodString[32];
    snprintf(periodString, sizeof periodString, "%d", periodInNanoseconds);
    return pputs("/sys/class/pwm/pwmchip0/device/pwm_period", periodString);
}

int setDutycycle(int dutycycle) {
    char dutycycleString[32];
    snprintf(dutycycleString, sizeof dutycycleString,"%d\n", dutycycle);
    return pputs("/sys/class/pwm/pwmchip0/pwm1/duty_cycle", dutycycleString);
}

int enablePWM() {
    return pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "1");
}

int unablePWM() {
    return pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "0");
}
