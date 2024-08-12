#include <stdio.h>
#include "fuel.h"

/*
    1 : Activation Signal
*/

typedef void(*fuelCapReleaseControlFunction)();

void activateFuelCapRelease() {
    printf("Fuel cap released\n");
}

void fuelCapReleaseControl(fuelCapReleaseControlFunction fc) {
    printf("Status changed by function\n");
}