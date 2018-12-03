#include "galileo/eeprom.h"

int writeToEeprom(char* text) {
    if(pputs("/sys/bus/i2c/devices/0-0054/eeprom", text) < 0){
        return showError("Problem on wrting into the EEPROM\n");
    }
    return SUCCESS;
}

char* readFromEeprom() {
    char stringOnEeprom[1024];
    // Verify if there is something to read
    if(pgets(stringOnEeprom, sizeof stringOnEeprom,
             "/sys/bus/i2c/devices/0-0054/eeprom") < 0) {
        return showError("Problem on reading EEPROM\n");
    }
    return (char*) stringOnEeprom;
}
