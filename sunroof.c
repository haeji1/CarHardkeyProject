#include <stdio.h>
#include "observer.h"
#include "sunroof.h"

/*
    0 : open
    1 : close
    2 : tilt
*/

// Set the sunroof default value to 1.
static int sunroofState = 1;

// Variable to track the last executed state
static int lastExecutedState = -1;  // Initialize to an invalid state

// Function pointer for sunroof operation
static SunroofOperation operations[3];

void executeSunroofOperation(int operation) {
    if (operation >= 0 && operation < 3) {
        operations[operation]();
    } else {
        printf("Invalid sunroof operation.\n");
    }
}

void closeSunroof() {
    if (sunroofState == 1) {
        return;
    } else {
        sunroofState = 1;
        printf("Sunroof is closing.\n");
        handlerEvent(SUNROOF_CONTROL);
    }
}

void openSunroof() {
    if (sunroofState == 0) {
        return;
    } else {
        sunroofState = 0;
        printf("Sunroof is opening.\n");
        handlerEvent(SUNROOF_CONTROL);
    }
}

void tiltSunroof() {
    if (sunroofState == 2) {
        return;
    } else {
        sunroofState = 2;
        printf("Sunroof is tilting.\n");
        handlerEvent(SUNROOF_CONTROL);
    }
}

void sunroofOperationHandler() {
    if (sunroofState >= 0 && sunroofState < 3) {
        if (sunroofState != lastExecutedState) {
            lastExecutedState = sunroofState;
            executeSunroofOperation(sunroofState);
            unregisterFunction(SUNROOF_CONTROL, sunroofOperationHandler);
        }
    } else {
        printf("Invalid sunroof state: %d\n", sunroofState);
    }
}

// Register sunroof handler
void initializeSunroofHandlers() {
    operations[0] = openSunroof;
    operations[1] = closeSunroof;
    operations[2] = tiltSunroof;

    registerHandler(SUNROOF_CONTROL, sunroofOperationHandler);
}
