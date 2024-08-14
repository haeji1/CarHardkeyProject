#include <stdio.h>
#include "auto_hold.h"


//1on 0off

typedef void(*autoHoldFunction)();

void autoHoldOff() {
    printf("\n--Off the autohold--\n");
}

void autoHoldOn() {
    printf("on the autohold mod *****\n");
}

void setAutoHold(autoHoldFunction af) {
    printf("\n***** Change the current state successful *****\n");
}