#ifndef FOG_LIGHTS_H
#define FOG_LIGHTS_H

typedef void(*fogLightFunction)();

void fogLightsOff();
void fogLightsOn();
void setFogLights(fogLightFunction flf);

#endif // FOG_LIGHTS_H
