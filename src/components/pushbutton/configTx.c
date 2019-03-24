#include  "../../../include/components/pushbutton/configTx.h"

int openAckTx() {
    return open("/sys/class/gpio/gpio14/value", O_RDONLY);
}

int setPollEdgeTx(const char* edge) {
    return pputs("/sys/class/gpio/gpio14/edge", edge);
}

int closeAckTx() {
    int status;
    status = setPollEdgeTx("none");

    return status;
}
