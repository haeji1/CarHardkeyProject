#ifndef STRATEGY_H
#define STRATEGY_H

typedef enum {
    OFF,
    ON
} DefrostState;

typedef enum {
    DISENGAGED,
    ENGAGED
} LockState;

void engageLock();
void disengageLock();
LockState getLockState();

void activateDefrost();
void deactivateDefrost();
DefrostState getDefrostState();

#endif // STRATEGY_H
