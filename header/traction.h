// traction.h
#ifndef TRACTION_H
#define TRACTION_H

typedef void(*tractionControlFunction)();

void tractionOff();
void tractionOn();
void tractionControl(tractionControlFunction tc);

#endif // TRACTION_H
