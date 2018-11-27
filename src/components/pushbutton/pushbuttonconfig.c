#include  "../../../include/components/pushbutton/pushbuttonconfig.h"

void initPushbutton() {
    int fileDescriptor;

    /* IO4 = gpio6 */
    pputs("/sys/class/gpio/export","6");
    pputs("/sys/class/gpio/gpio6/direction","in");

    /* gpio36= 1 = in */
    pputs("/sys/class/gpio/export","36");
    pputs("/sys/class/gpio/gpio36/direction","out");
    pputs("/sys/class/gpio/gpio36/value","1");

    /* gpio37 = in = no pull-up nor pull-down*/
    pputs("/sys/class/gpio/export","37");
    pputs("/sys/class/gpio/gpio37/direction","in");

    pputs("/sys/class/gpio/gpio6/edge","falling");

}
