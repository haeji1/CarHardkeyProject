#ifndef TURNSIGNALS_H
#define TURNSIGNALS_H

typedef void(*turnSignalsControlFunction)();

void leftTurnSignal();
void rightTurnSignal();
void turnSignalsControl(turnSignalsControlFunction);

#endif