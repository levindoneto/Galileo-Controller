#include  "components/pushbutton/pushbutton.h"

int getClick(int pollResult) {
    if (pollResult != -1 && pollResult != 0) {
        return CLICKED;
    } else {
        return NOT_CLICKED;
    }
}
