#ifndef STEERING_H
#define STEERING_H

typedef void(*steeringControlFunction)();

void upSteering();
void downSteering();
void inSteering();
void outSteering();
void steeringControl(steeringControlFunction);

#endif