#include <stdio.h>
#include <windows.h>
#include "observer.h"
#include "steering.h"

/*
    0 : up
    1 : down
    2 : in
    3 : out
*/

// set the steering default 1
static int steeringState = 1;

// Variable to track the last executed state
static int lastExecutedState = -1;  // Initialize to an invalid state

// Function pointer for steering adjust
static SteeringAdjustOperation operations[4];

void executeSteeringAdjustOperation(int operation) {
    if (operation >= 0 && operation < 4) {
        operations[operation]();
    } else {
        printf("Invalid Steering Adjust.\n");
    }
}

void up() {
    if (steeringState == 0) {
        return;
    } else {
        steeringState = 0;
        printf("UP steering\n");
        handlerEvent(STEERING_ADJUST);
    }
}

void down() {
    if (steeringState == 1) {
        return;
    } else {
        steeringState = 1;
        printf("Down steering\n");
        handlerEvent(STEERING_ADJUST);
    }
}

void in() {
    if (steeringState == 2) {
        return;
    } else {
        steeringState = 2;
        printf("In steering\n");
        handlerEvent(STEERING_ADJUST);
    }
}

void out() {
    if (steeringState = 3) {
        return;
    } else {
        steeringState = 3;
        printf("Out steering\n");
        handlerEvent(STEERING_ADJUST);
    }
}

void steeringAdjustOperationHandler() {
    if (steeringState >= 0 && steeringState < 4) {
        if (steeringState != lastExecutedState) {
            lastExecutedState = steeringState;
            executeSteeringAdjustOperation(steeringState);
        }
    } else {
        printf("Invalid steering state\n");
    }
}

void initializeSteeringAdjustHandlers() {
    operations[0] = up;
    operations[1] = down;
    operations[2] = in;
    operations[3] = out;
}