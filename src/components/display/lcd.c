#include "../../../include/components/display/lcd.h"

int writeDisplay(int fileDescriptor, const char* textToWriteLine0,
                 const char* textToWriteLine1) {
    int i;
    // Write string on the LCD display
    if(ioctl(fileDescriptor,I2C_SLAVE,LCD_ADDR) < SUCCESS) {
        throwError("ioctl on /dev/i2c-0");
    }
    for(i = 0; i < strlen(textToWriteLine0); i++) {
        i2c_write_reg(fileDescriptor, LCD_RS, textToWriteLine0[i]);
    }

    close(fileDescriptor);
    return SUCCESS;
}
