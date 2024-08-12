#include <stdio.h>
#include "fog_lights.h"


//0off 1on


typedef void(*fogLightFunction)();

void fogLightsOff() {
    printf("Fog lights turned off\n");
}

void fogLightsOn() {
    printf("Fog lights turned on \n");
}

void setFogLights(fogLightFunction flf) {
    printf("Change the current state successful \n");
}
