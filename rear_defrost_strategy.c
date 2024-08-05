#include "strategy.h"
#include <stdio.h>

static DefrostState currentDefrostState = OFF;


void activateDefrost() {
    currentDefrostState = ON;
    printf("Rear defrost activated.\n");
    sleep(3000);
}

void deactivateDefrost() {
    currentDefrostState = OFF;
    printf("Rear defrost deactivated.\n");
    sleep(3000);
}

DefrostState getDefrostState() {
    return currentDefrostState;
}

void handleDefrostCommand() {
    char input[10];
    printf("Enter command (ON/OFF) to control rear defrost or 'exit' to quit:\n");
        printf("Current state: %s\n", getDefrostState() == ON ? "Activated" : "Deactivated");
        scanf("%s", input);

        if (strcmp(input, "ON") == 0) {
            activateDefrost();
        } else if (strcmp(input, "OFF") == 0) {
            deactivateDefrost();
    }
}