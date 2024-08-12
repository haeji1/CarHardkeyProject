#include <stdio.h>
#include <windows.h>
#include "observer.h"
#include "drive.h"

/*
    0 : Eco
    1 : Sport
    2 : Normal
*/

typedef void(*driveModeControlFunction)();

void ecoMode() {
    printf("Change to eco mode\n");
}

void sportsMode() {
    printf("Change to sports mode\n");
}

void normalMode() {
    printf("Change to normal mode\n");
}

void changeSunroofControl() {
    printf("Change sunroof control\n");
}

void driveModeControl(driveModeControlFunction dc) {
     printf("status changed by function\n");
}