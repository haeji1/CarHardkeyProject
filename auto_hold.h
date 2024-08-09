#ifndef AUTO_HOLD_H
#define AUTO_HOLD_H

typedef void(*autoHoldFunction)();

void autoHoldOff();
void autoHoldOn();
void setAutoHold(autoHoldFunction af);

#endif //AUTO_HOLD_H