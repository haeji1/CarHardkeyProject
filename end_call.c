#include "strategy.h"
#include <stdio.h>

void endCallImpl() {
    currentCallState = 0; // Set call state to inactive
    printf("Ending phone call.\n");

}

// Initialize function pointers
EndCallFunction endCall = endCallImpl;
