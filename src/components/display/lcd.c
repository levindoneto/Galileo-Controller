#include "../../../include/components/display/lcd.h"

int writeDisplay(int fileDescriptor, const char* textToWriteLine0,
                 const char* textToWriteLine1) {
    int i;
    // Write string on the LCD display
    if(ioctl(fileDescriptor, I2C_SLAVE, LCD_ADDR) < SUCCESS) {
        throwError("ioctl on /dev/i2c-0");
    }

    // Display first line
    i2c_write_reg(fileDescriptor, LCD_C0, LCD_DDRAMADDRSET | FIRST_ROW_LCD);
    for(i = 0; i < strlen(textToWriteLine0); i++) {
        i2c_write_reg(fileDescriptor, LCD_RS, textToWriteLine0[i]);
    }
    // Display second line
    i2c_write_reg(fileDescriptor,LCD_C0,LCD_DDRAMADDRSET | SECOND_ROW_LCD);
    i2c_write_reg(fileDescriptor,LCD_RS,textToWriteLine1[i]);
        for(i = 0; i < strlen(textToWriteLine1); i++) {
    }
    
    setBacklightColor(fileDescriptor, RED);

    close(fileDescriptor);
    return SUCCESS;
}
