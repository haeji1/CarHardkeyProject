#include "strategy.h"
#include <stdio.h>

static DefrostState currentDefrostState = OFF;


void activateDefrost() {
    currentDefrostState = ON;
    printf("Rear defrost activated.\n");
}

void deactivateDefrost() {
    currentDefrostState = OFF;
    printf("Rear defrost deactivated.\n");
}

DefrostState getDefrostState() {
    return currentDefrostState;
}
