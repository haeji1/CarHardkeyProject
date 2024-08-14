#include <stdio.h>
#include "traction.h"

/*
    0 : off
    1 : on
*/

// Interface for traction control
typedef void(*tractionControlFunction)();

void tractionOff() {
    printf("Off the traction\n");
}

void tractionOn() {
    printf("On the traction\n");
}

void tractionControl(tractionControlFunction tc) {
    printf("status changed by function\n");
}