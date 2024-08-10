#include <stdio.h>
#include "horn.h"

/*
    1 : Actvation Signal
*/

void activateHorn() {
    printf("Horn sounds!\n");
}

// Function to execute the horn control function
void hornControl(hornControlFunction hc) {
    printf("Status changed by function\n");
}