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
    memset(&act, 0, sizeof(act));

    // Other needed variables
    int ledFD = initLed();

    // TEST DISPLAY LCD - I2C
    // Init display and backlight of the LCD
    int fileDescriptorDisplay = initDisplay();
    prepareDisplay(fileDescriptorDisplay);
    initBacklight(fileDescriptorDisplay);
    setBacklightColor(fileDescriptorDisplay, GREEN);
    const char* textToWrite0 = "AAAA\0";
    const char* textToWrite1 = "GREMIO\0";
    writeDisplay(fileDescriptorDisplay, textToWrite0, textToWrite1);

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

    SENSORS_DATA rawData[DATA_POINTS];
    ADC_DATA finalData[DATA_POINTS];

    int statusInitAdc = initAdcContinuous();
    printf("funfou: %d\n", statusInitAdc);

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
        //setupBuzzer(25);
        captureAdcContinuous(rawData, finalData);
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

    endAdc();
    //disablePWM();
    closeLed(ledFD);
    closePushButton();
    close(fileDescriptorDisplay);
    close(pfd.fd); // Close interruption on the pushbutton (IO4)

    // // TEST DATETIME
    // getCurrentTimeTimestamp();
    // printf("TIME ISO: %s\n", getCurrentTimeISO());
    // getCurrentDateISO();
    //
    return SUCCESS;
}
