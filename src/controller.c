#include "../include/components/display/lcd.h"
#include "../include/components/pushbutton/pushbutton.h"

int main(int argc,char *argv[]) {
    // Open i2c pseudofile in a writing mode
    int fileDescriptor = open("/dev/i2c-0",O_WRONLY);

    // Init display and backlight of the LCD
    initDisplay(fileDescriptor);
    prepareDisplay(fileDescriptor);
    initBacklight(fileDescriptor);

    const char* textToWrite0 = "TEST\0";
    const char* textToWrite1 = "LINE2\0";

    //getPushbuttonValue();

    writeDisplay(fileDescriptor, textToWrite0, textToWrite1);

    return SUCCESS;
}
