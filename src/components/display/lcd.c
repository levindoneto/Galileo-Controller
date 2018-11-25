int writeDisplay(const char* textToWrite) {
    int i;

    // Open i2c pseudofile in a writing mode
    int fileDescriptor = open("/dev/i2c-0",O_WRONLY);

    // Init display and backlight of the LCD
    initDisplay(i2cFileDescriptor);
    prepareDisplay(i2cFileDescriptor);
    initBacklight(i2cFileDescriptor);

    // Write string on the LCD display
    if(ioctl(fileDescriptor,I2C_SLAVE,LCD_ADDR) < SUCCESS) {
        throwError("ioctl on /dev/i2c-0");
    }
    for(i = 0; i < strlen(textToWrite); i++) {
        i2c_write_reg(fileDescriptor, LCD_RS, textToWrite[i]);
    }

    close(fileDescriptor);
    return SUCCESS;
}
