#include "../include/components/display/lcd.h"

int main(int argc,char *argv[]) {
    const char* textToWrite = "TEST";
    return writeDisplay(textToWrite);

}
