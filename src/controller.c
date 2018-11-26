#include "../include/components/display/lcd.h"

int main(int argc,char *argv[]) {
    // Open i2c pseudofile in a writing mode
    int fileDescriptor = open("/dev/i2c-0",O_WRONLY);

    // Init display and backlight of the LCD
    initDisplay(fileDescriptor);
    prepareDisplay(fileDescriptor);
    initBacklight(fileDescriptor);

    const char* textToWrite0 = "TEST CONTROLLER";
    const char* textToWrite1 = "LINE 2 ...";

    writeDisplay(fileDescriptor, textToWrite0, textToWrite1);

    return SUCCESS;
}
