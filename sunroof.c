#include <stdio.h>
#include "sunroof.h"

/*
    0 : open
    1 : close
    2 : tilt
*/

typedef void (*sunroofControlFunction)();

void openSunroof() {
    printf("Open the sunroof\n");
}

void closeSunroof() {
    printf("Close the sunroof\n");
}

void tiltSunroof() {
    printf("Tilt the sunroof\n");
}

void sunroofControl(sunroofControlFunction sc) {
    printf("status changed by function\n");
}