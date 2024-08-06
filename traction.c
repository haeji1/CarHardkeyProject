#include <stdio.h>

// Interface for traction control
typedef void(*tractionControlFunction)();

void tractionOff() {
    printf("Off the traction\n");
}

void tractionOn() {
    printf("On the traction\n");
}

void tractionControl(tractionControlFunction tc) {
    // tc();
    printf("Change status successful\n");
}