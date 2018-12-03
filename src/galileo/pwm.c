#include "galileo/pwm.h"

int getPeriodPWM() {
    static char periodString[32];
    if (pgets(periodString, sizeof(periodString),
              "/sys/class/pwm/pwmchip0/device/pwm_period") < 0) {
        printf("\nReturning default PWM period: %d", PWM_DEFAULT_PERIOD);
        return PWM_DEFAULT_PERIOD;
    }
    return (int) periodString;
}

int setPeriodPWM(int periodInNanoseconds) {
    char periodString[32];
    snprintf(periodString, sizeof periodString, "%d", periodInNanoseconds);
    return pputs("/sys/class/pwm/pwmchip0/device/pwm_period", periodString);
}

int setDutycycle(int dutyCycle) {
    char dutyCycleString[32];
    snprintf(dutyCycleString, sizeof dutyCycleString, "%d", dutyCycle);
    return pputs("/sys/class/pwm/pwmchip0/pwm1/duty_cycle", dutyCycleString);
}

int setDutycyclePercent(int percentDutyCycle) {
    if(percentDutyCycle > 100 || percentDutyCycle < 0) {
        return ERROR;
    }
    printf("\ngetPeriodPWM(): %d\n", getPeriodPWM());


    //int dutyCycle = (int) percentDutyCycle * getPeriodPWM() / 100;   //TODO: FIX
    int dutyCycle = (int) percentDutyCycle * PWM_DEFAULT_PERIOD / 100;
    printf("\nDUTY CYCLE TO SET: %d", dutyCycle);
    return setDutycycle(dutyCycle);
}

int enablePWM() {
    return pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "1");
}

int disablePWM() {
    return pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "0");
}
