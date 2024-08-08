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

typedef void (*ActivateHillFunction)();
typedef void (*DeactivateHillFunction)();
typedef DefrostState (*GetHillStateFunction)();

// 함수 포인터 타입
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


typedef void (*ToggleMuteFunction)();
typedef AudioState (*GetAudioStateFunction)();

typedef void (*VoiceCommandToggleFunction)();
typedef void (*NavigationStrategy)(Coordinates destination);

// 추가된 함수 포인터 타입
typedef void (*HandleHillDescentControlCommandFunction)();
typedef void (*AnswerCallFunction)();
typedef void (*EndCallFunction)();



// 함수 포인터 선언
extern EngageLockFunction engageLock;
extern DisengageLockFunction disengageLock;
extern GetLockStateFunction getLockState;

extern ActivateDefrostFunction activateDefrost;
extern DeactivateDefrostFunction deactivateDefrost;
extern GetDefrostStateFunction getDefrostState;

// hill
extern ActivateHillFunction activateHill;
extern DeactivateHillFunction deactivateHill;
extern GetHillStateFunction getHillState;

extern ActivateParkingAssistFunction activateParkingAssist;
extern DeactivateParkingAssistFunction deactivateParkingAssist;
extern GetParkingAssistStateFunction getParkingAssistState;

extern ActivateLaneSupportFunction activateLaneSupport;
extern DeactivateLaneSupportFunction deactivateLaneSupport;
extern GetLaneSupportStateFunction getLaneSupportState;

extern ToggleMuteFunction toggleMute;
extern GetAudioStateFunction getAudioState;

extern VoiceCommandToggleFunction voiceCommandToggle;

// 새로운 함수 포인터 선언
extern HandleHillDescentControlCommandFunction handleHillDescentControlCommand;
extern AnswerCallFunction answerCall;
extern EndCallFunction endCall;

void quickRouteStrategy(Coordinates destination);
void convenientRouteStrategy(Coordinates destination);
void minimumFareRouteStrategy(Coordinates destination);

void setNavigationStrategy(NavigationStrategy strategy);
void navigateTo(Coordinates destination);
void navigatehandle();

// 차선 유지 지원 기능
void handleLaneSupportCommand();

// 주차 보조 기능
void handleParkingAssistCommand();

#endif // STRATEGY_H

