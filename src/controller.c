#include "../include/controller.h"

static volatile int run = 1;

void quit(int signal) {
    run = 0;
}

int main(int argc,char *argv[]) {
    // Polling variables (used on IO4 - Pushbutton)
    unsigned char c;
    static struct pollfd pfd;
    int i;
    struct sigaction act;

    // Other needed variables
    int ledFD = initLed();

    // TEST DISPLAY LCD - I2C
    // Init display and backlight of the LCD
    int fileDescriptor = initDisplay();
    prepareDisplay(fileDescriptor);
    initBacklight(fileDescriptor);
    setBacklightColor(fileDescriptor, GREEN);
    const char* textToWrite0 = "asasdasd\0";
    const char* textToWrite1 = "GREMIO\0";
    writeDisplay(fileDescriptor, textToWrite0, textToWrite1);

    // TEST POLL
    initPushbutton(); // Configure GPIOs
    if((pfd.fd=openPushbutton()) < 0) {
        return showError("Error on Opening GPIO6\n");
    }
    read(pfd.fd, &c, INIT); // Clear old values
    pfd.events = POLLPRI; // There's some exceptional condition on the pfd.fd
    act.sa_handler = quit; // Action to be executed by the handler at the end
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGTERM, &act,NULL);
    setPollEdge("falling"); // Configure polling edge
    disablePWM();
    // Main loop of the Galileo's controller
    while (run) {
        if(getClick(poll(&pfd, N_FD_POOLS, MIN_TIMEOUT_MS))) {
            lseek(pfd.fd, 0, SEEK_SET);
            read(pfd.fd, &c, 1);
            turnOnLed(ledFD);
            sleep(1);
        }
        turnOffLed(ledFD);
        // TEST SERVOMOTOR-PWM - IO3
        // PWM CONFIG
        setupBuzzer(25);
        sleep(1);
        // disablePWM();
        // printf("\n\n\n\ndefault period set: %d\n\n\n", PWM_DEFAULT_PERIOD);
        // setPeriodPWM(PWM_DEFAULT_PERIOD);
        // setDutycyclePercent(0); // init pwm with 0 duty cycle
        // enablePWM();
        // turnOnServomotorDegrees(45);
        // sleep(1);
        // disablePWM();
        //
        // setPeriodPWM(PWM_DEFAULT_PERIOD);
        // setDutycyclePercent(0); // init pwm with 0 duty cycle
        // enablePWM();
        // turnOnServomotorDegrees(-45);
        // sleep(1);
        // disablePWM();
    }
    disablePWM();
    closeLed(ledFD);
    closePushButton();
    close(pfd.fd);

    // // TEST DATETIME
    // getCurrentTimeTimestamp();
    // printf("TIME ISO: %s\n", getCurrentTimeISO());
    // getCurrentDateISO();
    //

    return SUCCESS;
}
