#include  "../../../include/components/led/ledconfig.h"

int initLed() {
    int ledFileDescriptor;
    ledFileDescriptor = open("/sys/class/gpio/gpio62/value", O_WRONLY);
    return ledFileDescriptor;
}

int closeLed(int ledFileDescriptor) {
    return close(ledFileDescriptor);
}
