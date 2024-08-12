#include <stdio.h>
#include "steering.h"

/*
    0 : up
    1 : down
    2 : in
    3 : out
*/

typedef void(*steeringControlFunction)();

void upSteering() {
    printf("Adjust the steering up\n");
}

void downSteering() {
    printf("Adjust the steering down\n");
}

void inSteering() {
    printf("Adjust the steering in\n");
}

void outSteering() {
    printf("Adjust the steering out\n");
}

void steeringControl(steeringControlFunction sc) {
    printf("status changed by function\n");
}