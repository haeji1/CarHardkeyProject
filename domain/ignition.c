#include <stdio.h>
#include "ignition.h"

/*
    1 : on
*/

void onIgnition() {
    printf("Engine starts with ignition!\n");
}

void ignition(ignitionFunction igFunc) {
    printf("status changed by function\n");
}