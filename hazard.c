#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "hazard.h"

static int hazardLightsState = 0; 

void offHazardLights();
void onHazardLights();

void handleHazardLights(void) {

    int opt;
    printf(" == HAZARD_LIGHTS options == \n");
    printf("1. Off \n");
    printf("2. ON \n");
    printf("4. EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
        offHazardLights();
    }else if(opt == 2){
        onHazardLights();
    }else{
        printf("Unknown HAZARD_LIGHTS command.\n");
    }

}

void offHazardLights(){
    if (hazardLightsState == 0) {
        printf("Hazard lights are already OFF.\n");
    } else {
        hazardLightsState = 0;
        printf("Hazard lights turned OFF.\n");
    }
}

void onHazardLights(){
    if (hazardLightsState == 1) {
        printf("Hazard lights are already ON.\n");
    } else {
        hazardLightsState = 1;
        printf("Hazard lights turned ON.\n");
    }
}


void initializeHazardLightsHandlers() {
    registerHandler(HAZARD_LIGHTS, handleHazardLights);
}