#include "../../../include/components/display/backlightconfig.h"

void setBacklightColor(int i2cFileDescriptor, int color) {
    if (color == RED) {
        i2c_write_reg(i2cFileDescriptor, BL_RED, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_GREEN, DATA_0);
        i2c_write_reg(i2cFileDescriptor, BL_BLUE, DATA_0);
    } else if(color == BLUE) {
        i2c_write_reg(i2cFileDescriptor, BL_RED, DATA_0);
        i2c_write_reg(i2cFileDescriptor, BL_GREEN, DATA_0);
        i2c_write_reg(i2cFileDescriptor, BL_BLUE, DATA_255);
    } else if(color == GREEN) {
        i2c_write_reg(i2cFileDescriptor, BL_RED, DATA_0);
        i2c_write_reg(i2cFileDescriptor, BL_GREEN, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_BLUE, DATA_0);
    } else if(color == YELLOW) {
        i2c_write_reg(i2cFileDescriptor, BL_RED, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_GREEN, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_BLUE, DATA_0);
    } else if(color == WHITE) {
        i2c_write_reg(i2cFileDescriptor, BL_RED, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_GREEN, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_BLUE, DATA_255);
    } else {
        i2c_write_reg(i2cFileDescriptor, BL_RED, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_GREEN, DATA_255);
        i2c_write_reg(i2cFileDescriptor, BL_BLUE, DATA_255);
    }
}

void initBacklight(int i2cFileDescriptor) {
    if(ioctl(i2cFileDescriptor, I2C_SLAVE,BL_ADDR) < SUCCESS) {
        throwError("ioctl on /dev/i2c-0");
    }
    i2c_write_reg(i2cFileDescriptor, BL_MODE1, DATA_0);
    i2c_write_reg(i2cFileDescriptor, BL_LEDOUT,BL_RED_GRPPWM | BL_GREEN_GRPPWM |
                  BL_BLUE_GRPPWM);
    i2c_write_reg(i2cFileDescriptor, BL_MODE2, BL_DMBLNK);

    // Init color (white)
    setBacklightColor(i2cFileDescriptor, WHITE);

}
