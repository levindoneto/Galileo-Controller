#include  "../../../include/components/led/led.h"

void turnOnLed(int ledFileDescriptor) {
    char led_on = LED_ON;
    lseek(ledFileDescriptor, 0, SEEK_SET);
    write(ledFileDescriptor, &led_on, sizeof led_on);
}

void turnOffLed(int ledFileDescriptor) {
    char led_off = LED_OFF;
    lseek(ledFileDescriptor, 0, SEEK_SET);
    write(ledFileDescriptor, &led_off, sizeof led_off);
}

int getLedStatus(int ledFileDescriptor) {
    char status;
    lseek(ledFileDescriptor, 0, SEEK_SET);
	read(ledFileDescriptor, &status, sizeof status);
    return (int) status;
}
