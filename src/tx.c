#include "../include/controller.h"

static struct pollfd pfd;

int sendBit(int value);

int sendBit(int value) {
  unsigned char c;

  pputs("/sys/class/gpio/gpio6/value", value == 0 ? "0" : "1");

  pputs("/sys/class/gpio/gpio13/value", "1");
  pputs("/sys/class/gpio/gpio13/value", "0");

  if(getClick(poll(&pfd, N_FD_POOLS, -1))) {
      lseek(pfd.fd, 0, SEEK_SET);
      read(pfd.fd, &c, 1);

      // Received ack
      printf("Received ACK!\n");
  }
}


int main(int argc,char *argv[]) {
    unsigned char c;
    int i, len;
    char* str;

    if(argc != 2) {
      return showError("Usage: ./tx <string>\n");
    }

    // TEST POLL
    if((pfd.fd=openAckTx()) < 0) {
        return showError("Error on Opening GPIO14\n");
    }
    read(pfd.fd, &c, INIT); // Clear old values
    pfd.events = POLLPRI; // There's some exceptional condition on the pfd.fd
    setPollEdgeTx("rising"); // Configure polling edge

    str = argv[1];
    len = strlen(str);
    // Main loop of the Galileo's controller
    for(i = 0; i < len; i++) {
      unsigned char c = str[i];

      int j;
      for(j = 0; j < 8; j++) {
        int value = 0;
        value = c & 1;
        c = c >> 1;

        sendBit(value);
      }
    }

    closeAckTx();
    close(pfd.fd); // Close interruption on the pushbutton (IO4)

    return SUCCESS;
}
