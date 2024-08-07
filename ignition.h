#ifndef IGNITION_H
#define IGNITION_H

typedef void(*ignitionFunction)();

void onIgnition();
void ignition(ignitionFunction igFunc);

#endif
