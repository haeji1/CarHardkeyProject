#include <stdio.h>
#include "trunk.h"

/*
    1 : Actvation Signal
*/

typedef void(*trunkReleaseControlFunction)();

void activateTrunkRelease() {
    printf("Trunk released\n");
}

// Function to execute the trunk release control function
void trunkReleaseControl(trunkReleaseControlFunction tr) {
    printf("Status changed by function\n");
}