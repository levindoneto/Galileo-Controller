#include  "../../../include/components/pushbutton/pushbuttonconfig.h"

int initPushbutton() {
    int status;
    // gpio6 => IO4
    status = pputs("/sys/class/gpio/export","6");
    status = pputs("/sys/class/gpio/gpio6/direction","in");
    // gpio36 = 1 = in
    status = pputs("/sys/class/gpio/export","36");
    status = pputs("/sys/class/gpio/gpio36/direction","out");
    status = pputs("/sys/class/gpio/gpio36/value","1");
    // gpio37 = in = neither pull-up nor pull-down required
    status = pputs("/sys/class/gpio/export","37");
    status = pputs("/sys/class/gpio/gpio37/direction","in");

    return status;
}

int openPushbutton() {
    return open("/sys/class/gpio/gpio6/value", O_RDONLY);
}

int setPollEdge(const char* edge) {
    return pputs("/sys/class/gpio/gpio6/edge", edge);
}

int closePushButton() {
    int status;
    status = setPollEdge("none");
    status = pputs("/sys/class/gpio/unexport","37");
    status = pputs("/sys/class/gpio/unexport","36");
    status = pputs("/sys/class/gpio/unexport","6");

    return status;
}
