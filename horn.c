#include <stdio.h>
#include "observer.h"
#include "horn.h"

static int hornState = 0; // 0 for OFF, 1 for ON

void handleHornOn(void) {
    if (hornState == 1) {
        printf("Horn is already ON.\n");
    } else {
        hornState = 1;
        printf("Horn turned ON.\n");
    }
}

void handleHornOff(void) {
    if (hornState == 0) {
        printf("Horn is already OFF.\n");
    } else {
        hornState = 0;
        printf("Horn turned OFF.\n");
    }
}

void initializeHornHandlers() {
    registerHandler(HORN, handleHornOn);
}