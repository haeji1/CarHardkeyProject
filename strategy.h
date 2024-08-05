#ifndef STRATEGY_H
#define STRATEGY_H

typedef enum {
    OFF,
    ON
} DefrostState, ParkingAssistState, LaneSupportState, HillDescentControlState;

typedef enum {
    DISENGAGED,
    ENGAGED
} LockState;

typedef enum {
    SILENT,
    VIBRATE,
    RING
} ResponseMode;

typedef enum {
    QUICK_ROUTE,
    CONVENIENT_ROUTE,
    MINIMUM_FARE_ROUTE
} NavigationRoute;

typedef struct {
    double latitude;
    double longitude;
} Coordinates;

void engageLock();
void disengageLock();
LockState getLockState();

void activateDefrost();
void deactivateDefrost();
DefrostState getDefrostState();

void activateParkingAssist();
void deactivateParkingAssist();
ParkingAssistState getParkingAssistState();

void activateLaneSupport();
void deactivateLaneSupport();
LaneSupportState getLaneSupportState();

void activateHillDescentControl();
void deactivateHillDescentControl();
HillDescentControlState getHillDescentControlState();

typedef void (*PhoneResponseStrategy)();
void setPhoneResponseStrategy(PhoneResponseStrategy strategy);
void respondToCall();

typedef void (*NavigationStrategy)(Coordinates destination);
void setNavigationStrategy(NavigationStrategy strategy);
void navigateTo(Coordinates destination);

void quickRouteStrategy(Coordinates destination);
void convenientRouteStrategy(Coordinates destination);
void minimumFareRouteStrategy(Coordinates destination);

#endif // STRATEGY_H
