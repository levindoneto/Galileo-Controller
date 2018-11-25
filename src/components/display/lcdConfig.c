void initDisplay(int i2cFileDescriptor) {
    if(i2cFileDescriptor < SUCCESS) {
        throwError("on opening /dev/i2c-0");
    }
    usleep(30_MS);	// Await 30 ms after turning the lcd on

    // Initialization of the display LCD
    if(ioctl(i2cFileDescriptor, I2C_SLAVE,LCD_ADDR) < SUCCESS) {
        throwError("on ioctl on /dev/i2c-0");
    }
}

void prepareDisplay(int i2cFileDescriptor) {
    i2c_write_reg(i2cFileDescriptor, LCD_C0,LCD_FUNCTIONSET | LCD_2LINE);
    usleep(40_US);
    i2c_write_reg(i2cFileDescriptor, LCD_C0,LCD_DISPLAYSWITCH | LCD_DISPLAYON |
                  LCD_CURSOROFF | LCD_BLINKOFF);
    usleep(40_US);
    i2c_write_reg(i2cFileDescriptor, LCD_C0, LCD_SCREENCLEAR);
    usleep(1_6MS);
    i2c_write_reg(i2cFileDescriptor, LCD_C0, LCD_INPUTSET |
                  LCD_ENTRYLEFT | LCD_DECREMENT);
}
