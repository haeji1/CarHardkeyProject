#ifndef INTERIOR_H
#define INTERIOR_H

typedef void(*interiorLightControlFunction)();

void offInteriorLight();
void onInteriorLight();
void interiorLightControl(interiorLightControlFunction);

#endif