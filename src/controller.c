#include "../include/controller.h"

int main(int argc,char *argv[]) {

    // TEST DISPLAY LCD - I2C
    // Init display and backlight of the LCD
    int fileDescriptor = initDisplay();
    prepareDisplay(fileDescriptor);
    initBacklight(fileDescriptor);
    setBacklightColor(fileDescriptor, GREEN);
    const char* textToWrite0 = "OLA MUNDO\0";
    const char* textToWrite1 = "GREMIO\0";
    writeDisplay(fileDescriptor, textToWrite0, textToWrite1);

    // TEST LED - IO6
    int test;
    scanf("%d", &test);
    printf("Turn on led IO6...");
    int ledFD = initLed();
    scanf("init: %d", ledFD);
    turnOnLed(ledFD);
    scanf("%d", &test);
    printf("Turn off led...");
    turnOffLed(ledFD);
    printf("\nstatus: %d\n\n", closeLed(ledFD));

    // TEST OVERWRITE DISPLAY
    fileDescriptor = initDisplay();
    prepareDisplay(fileDescriptor);
    initBacklight(fileDescriptor);
    setBacklightColor(fileDescriptor, RED);
    textToWrite0 = "HORA\0";
    textToWrite1 = "TIME\0";
    writeDisplay(fileDescriptor, textToWrite0, textToWrite1);

    // TEST DATETIME
    getCurrentTimeTimestamp();
    printf("TIME ISO: %s\n", getCurrentTimeISO());
    getCurrentDateISO();

    // TEST SERVOMOTOR-PWM - IO3
    // PWM CONFIG
    disablePWM();
    printf("\n\n\n\ndefault period set: %d\n\n\n", PWM_DEFAULT_PERIOD);
    setPeriodPWM(PWM_DEFAULT_PERIOD);
    setDutycyclePercent(0); // init pwm with 0 duty cycle
    enablePWM();
    turnOnServomotorDegrees(90);
    sleep(6);
    disablePWM();

    setPeriodPWM(PWM_DEFAULT_PERIOD);
    setDutycyclePercent(0); // init pwm with 0 duty cycle
    enablePWM();
    turnOnServomotorDegrees(-90);
    sleep(6);
    disablePWM();


    return SUCCESS;
}
