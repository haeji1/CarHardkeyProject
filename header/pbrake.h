#ifndef PBRAKE_H
#define PBRAKE_H

typedef void(*parkingBrakeControlFunction)();

void disengageBrake();
void engageBrake();
void parkingBrakeControl(parkingBrakeControlFunction);

#endif