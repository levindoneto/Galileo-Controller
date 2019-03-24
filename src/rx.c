#include "../include/controller.h"

static struct pollfd pfd;

static volatile int run = 1;

void quit(int signal) {
    run = 0;
}

unsigned char receiveBit();

unsigned char receiveBit() {
  unsigned char c;
  unsigned char bit;

  if(getClick(poll(&pfd, N_FD_POOLS, -1))) {
      lseek(pfd.fd, 0, SEEK_SET);
      read(pfd.fd, &c, 1);

      // Clock
      printf("Received CLK!\n");

      pgets(&bit, sizeof(bit), "/sys/class/gpio/gpio38/value");

      //ACK
      pputs("/sys/class/gpio/gpio1/value", "0");
      pputs("/sys/class/gpio/gpio1/value", "1");
  }

  return bit;
}

int main(int argc,char *argv[]) {
    unsigned char c;
    int i, len;
    char str[512];

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = quit; // Action to be executed by the handler at the end
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGTERM, &act,NULL);

    // TEST POLL
    if((pfd.fd=openClkRx()) < 0) {
        return showError("Error on Opening GPIO0\n");
    }
    read(pfd.fd, &c, INIT); // Clear old values
    pfd.events = POLLPRI; // There's some exceptional condition on the pfd.fd
    setPollEdgeTx("falling"); // Configure polling edge

    while(run) {
      int i;
      int j = 0;
      unsigned char byte = 0;

      for(i = 0; i < 8; i++)
      {
        int value = receiveBit() == '0' ? 0 : 1;
        byte = byte | value;
        byte = byte << 1;
      }

      str[j] = byte;
      j++;
      int fileDescriptorDisplay = initDisplay();
      prepareDisplay(fileDescriptorDisplay);
      initBacklight(fileDescriptorDisplay);
      setBacklightColor(fileDescriptorDisplay, GREEN);
      const char* textToWrite0 = str;
      const char* textToWrite1 = "\0";
      writeDisplay(fileDescriptorDisplay, textToWrite0, textToWrite1);
    }

    closeClkRx();
    close(pfd.fd); // Close interruption on the pushbutton (IO4)

    return SUCCESS;
}
