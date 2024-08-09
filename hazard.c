#include <stdio.h>
#include "hazard.h"

/*
    0 : off
    1 : on

*/

typedef void(*hazardLightsControlFunction)();

void offHazardLights(){
    printf("Hazard lighs turned OFF.\n");
}

void onHazardLights(){
    printf("Hazard lighs turned ON.\n");
}

void hazardLightsControl(hazardLightsControlFunction tc){
    printf("status changed by function\n");
}