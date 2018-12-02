#include "../../../include/components/display/lcdconfig.h"

int initDisplay() {
    // Open i2c pseudofile in a writing mode
    int i2cFileDescriptor = open("/dev/i2c-0",O_WRONLY);

    if(i2cFileDescriptor < SUCCESS) {
        throwError("Error on opening /dev/i2c-0");
    }
    usleep(30000);	// Await 30 ms after turning the lcd on

    // Initialization of the display LCD
    if(ioctl(i2cFileDescriptor, I2C_SLAVE,LCD_ADDR) < SUCCESS) {
        throwError("Error on ioctl on /dev/i2c-0");
    }
    return i2cFileDescriptor;
}

void prepareDisplay(int i2cFileDescriptor) {
    i2c_write_reg(i2cFileDescriptor, LCD_C0,LCD_FUNCTIONSET | LCD_2LINE);
    usleep(40);
    i2c_write_reg(i2cFileDescriptor, LCD_C0,LCD_DISPLAYSWITCH | LCD_DISPLAYON |
                  LCD_CURSOROFF | LCD_BLINKOFF);
    usleep(40);
    i2c_write_reg(i2cFileDescriptor, LCD_C0, LCD_SCREENCLEAR);
    usleep(1600);
    i2c_write_reg(i2cFileDescriptor, LCD_C0, LCD_INPUTSET |
                  LCD_ENTRYLEFT | LCD_DECREMENT);
}
