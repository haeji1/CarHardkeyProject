#include <stdio.h>
#include "fog_lights.h"


//0off 1on


typedef void(*fogLightFunction)();

void fogLightsOff() {
    printf("\n***** Fog lights turned off *****\n");
}

void fogLightsOn() {
    printf("\n***** Fog lights turned on *****\n");
}

void setFogLights(fogLightFunction flf) {
    printf("\n***** Change the current state successful *****\n");
}
