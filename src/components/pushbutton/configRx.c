#include  "../../../include/components/pushbutton/configRx.h"

int openClkRx() {
    return open("/sys/class/gpio/gpio0/value", O_RDONLY);
}

int setPollEdgeRx(const char* edge) {
    return pputs("/sys/class/gpio/gpio0/edge", edge);
}

int closeClkRx() {
    int status;
    status = setPollEdgeRx("none");

    return status;
}
