#ifndef STEERING_H
#define STEERING_H

void initializeSteeringAdjustHandlers();
void executeSteeringAdjustOperation(int operation);

typedef void (*SteeringAdjustOperation)();

#endif