#include <stdio.h>
#include "observer.h"
#include "ignition.h"

static int ignitionState = 0; // 0 for OFF, 1 for ON

void handleIgnition(void) {
    if (ignitionState == 1) {
        printf("Safety check: Engine is already ON.\n");
    } else {
        ignitionState = 1;
        printf("Engine started.\n");
    }
}

void handleShutdownEvent(void) {
    if (ignitionState == 0) {
        printf("Safety check: Engine is already OFF.\n");
    } else {
        ignitionState = 0;
        printf("Engine stopped.\n");
    }
}

void initializeIgnitionHandlers() {
    registerHandler(IGNITION, handleIgnition);
}
