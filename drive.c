#include <stdio.h>
#include <windows.h>
#include "observer.h"
#include "drive.h"

/*
    0 : Eco
    1 : Sport
    2 : Normal
*/

// Set the drivemode default value to 2
static int driveState = 2;

// Variable to track the last executed state
static int lastExecutedState = -1;  // Initialize to an invalid state

// Function pointer for drive operation
static DriveModeOperation operations[3];

void executeDriveModeOperation(int operation) {
    if (operation >= 0 && operation < 3) {
        operations[operation]();
    } else {
        printf("Invalid DriveMode.\n");
    }
}

void ecoMode() {
    if (driveState == 0) {
        return; 
    } else {
        driveState = 0;
        printf("Setting eco mode.\n");
        handlerEvent(DRIVE_MODE);
        // unregisterFunction(DRIVE_MODE, ecoMode);
        unregisterHandler(DRIVE_MODE, ecoMode);
    }
}

void sportsMode() {
    if (driveState == 1) {
        return;
    } else {
        driveState = 1;
        printf("Setting sports mode.\n");
        handlerEvent(DRIVE_MODE);
        // unregisterFunction(DRIVE_MODE, sportsMode);
        unregisterHandler(DRIVE_MODE, sportsMode);
    }
}

void normalMode() {
    if (driveState == 2) {
        return;
    } else {
        driveState = 2;
        printf("Setting normal mode.\n");
        handlerEvent(DRIVE_MODE);
        // unregisterFunction(DRIVE_MODE, normalMode);
        unregisterHandler(DRIVE_MODE, normalMode);
    }
}

void driveModeOperationHandler() {
    if (driveState >= 0 && driveState < 3) {
        if (driveState != lastExecutedState) {
            lastExecutedState = driveState;
            executeDriveModeOperation(driveState);
            // unregisterFunction(DRIVE_MODE, driveModeOperationHandler);
        }
    } else {
        printf("Invalid sunroof state: %d\n", driveState);
    }
}

// Register drivemode handler
void initializeDriveModeHandlers() {
    operations[0] = ecoMode;
    operations[1] = sportsMode;
    operations[2] = normalMode;

    registerHandler(DRIVE_MODE, driveModeOperationHandler);
}