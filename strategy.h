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

typedef enum {
    quickRoute,
ConvenientRoute,
MinimumFareRoute
} NavigationRoute;

void engageLock();
void disengageLock();
LockState getLockState();

void activateDefrost();
void deactivateDefrost();
DefrostState getDefrostState();

void Activatenavigation();
void Disablenavigation();
NavigationRoute getNavigationRoutetime();

#endif // STRATEGY_H
