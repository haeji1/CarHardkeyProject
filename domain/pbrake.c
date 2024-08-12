#include <stdio.h>
#include "pbrake.h"

/*
    0 : disengage
    1 : engage
*/

typedef void(*parkingBrakeControlFunction)();

void disengageBrake() {
    printf("Disengaged parking brake\n");
}

void engageBrake() {
    printf("Engaged parking brake\n");
}

void parkingBrakeControl(parkingBrakeControlFunction pc) {
    printf("status changed by function\n");
}