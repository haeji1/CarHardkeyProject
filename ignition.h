#ifndef IGNITION_H
#define IGNITION_H

typedef void(*ignitionFunction)();

int ignitionStarted;

void onIgnition();
void ignition(ignitionFunction igFunc);

#endif
