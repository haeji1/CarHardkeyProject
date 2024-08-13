#include <stdio.h>
#include "hazard.h"

/*
    0 : off
    1 : on
*/

void offHazardLights(){
    printf("Hazard lights turned OFF.\n");
}

void onHazardLights(){
    printf("Hazard lights turned ON.\n");
}

void hazardLightsControl(hazardLightsControlFunction tc){
    printf("status changed by function\n");
}