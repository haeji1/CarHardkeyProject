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

typedef enum {
    UNMUTED,
    MUTED
} AudioState;

// Function pointer types
typedef void (*EngageLockFunction)();
typedef void (*DisengageLockFunction)();
typedef LockState (*GetLockStateFunction)();

typedef void (*ActivateDefrostFunction)();
typedef void (*DeactivateDefrostFunction)();
typedef DefrostState (*GetDefrostStateFunction)();

typedef void (*ActivateParkingAssistFunction)();
typedef void (*DeactivateParkingAssistFunction)();
typedef ParkingAssistState (*GetParkingAssistStateFunction)();

typedef void (*ActivateLaneSupportFunction)();
typedef void (*DeactivateLaneSupportFunction)();
typedef LaneSupportState (*GetLaneSupportStateFunction)();

typedef void (*ActivateHillDescentControlFunction)();
typedef void (*DeactivateHillDescentControlFunction)();
typedef HillDescentControlState (*GetHillDescentControlStateFunction)();

typedef void (*ToggleMuteFunction)();
typedef AudioState (*GetAudioStateFunction)();

typedef void (*VoiceCommandToggleFunction)();
typedef void (*NavigationStrategy)(Coordinates destination);

// Declare function pointers
extern EngageLockFunction engageLock;
extern DisengageLockFunction disengageLock;
extern GetLockStateFunction getLockState;

extern ActivateDefrostFunction activateDefrost;
extern DeactivateDefrostFunction deactivateDefrost;
extern GetDefrostStateFunction getDefrostState;

extern ActivateParkingAssistFunction activateParkingAssist;
extern DeactivateParkingAssistFunction deactivateParkingAssist;
extern GetParkingAssistStateFunction getParkingAssistState;

extern ActivateLaneSupportFunction activateLaneSupport;
extern DeactivateLaneSupportFunction deactivateLaneSupport;
extern GetLaneSupportStateFunction getLaneSupportState;

extern ActivateHillDescentControlFunction activateHillDescentControl;
extern DeactivateHillDescentControlFunction deactivateHillDescentControl;
extern GetHillDescentControlStateFunction getHillDescentControlState;

extern ToggleMuteFunction toggleMute;
extern GetAudioStateFunction getAudioState;

extern VoiceCommandToggleFunction voiceCommandToggle;

void quickRouteStrategy(Coordinates destination);
void convenientRouteStrategy(Coordinates destination);
void minimumFareRouteStrategy(Coordinates destination);

void setNavigationStrategy(NavigationStrategy strategy);
void navigateTo(Coordinates destination);
void navigatehandle();

// Lane Support Functions
void handleLaneSupportCommand();

// Parking Assist Functions
void handleParkingAssistCommand();

#endif // STRATEGY_H
