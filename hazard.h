#ifndef HAZARD_LIGHTS_H
#define HAZARD_LIGHTS_H

typedef void(*hazardLightsControlFunction)();

void offHazardLights();
void onHazardLights();
void hazardLightsControl(hazardLightsControlFunction);

#endif