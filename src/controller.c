#include "../include/controller.h"

int main(int argc,char *argv[]) {

    // TEST DISPLAY LCD - I2C
    // Init display and backlight of the LCD
    int fileDescriptor = initDisplay();
    prepareDisplay(fileDescriptor);
    initBacklight(fileDescriptor);
    const char* textToWrite0 = "TEST\0";
    const char* textToWrite1 = "LINE2\0";
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
    printf("status: %d", closeLed(ledFD));

    // TEST SERVOMOTOR-PWM - IO3
    turnOnServomotorDegrees(2000000, 90.0);
    sleep(3);
    turnOnServomotorDegrees(2000000, -90.0);
    sleep(3);

    return SUCCESS;
}
