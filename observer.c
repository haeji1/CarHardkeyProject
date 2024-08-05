#include <stdio.h>
#include <stdlib.h>
#include "observer.h"

Observer *observer[NUM_KEYS];

const char* hardKeyNames[NUM_KEYS] = {
    "IGNITION", "HORN", "HEADLIGHTS", "TURN_SIGNALS", "WINDSHIELD_WIPERS", 
    "HAZARD_LIGHTS", "CRUISE_CONTROL", "RADIO_VOLUME", "RADIO_TUNING", "RADIO_SOURCE", 
    "CLIMATE_TEMP", "CLIMATE_FAN", "CLIMATE_AIRFLOW", "DEFROST", "POWER_WINDOWS", 
    "WINDOW_LOCK", "DOOR_LOCKS", "MIRROR_ADJUST", "SEAT_ADJUST", "SUNROOF_CONTROL", 
    "TRUNK_RELEASE", "FUEL_CAP_RELEASE", "PARKING_BRAKE", "DRIVE_MODE", "TRACTION_CONTROL", 
    "HEATED_SEATS", "COOLED_SEATS", "STEERING_ADJUST", "INTERIOR_LIGHT", "REAR_DEFROST", 
    "CHILD_LOCK", "MUTE_BUTTON", "VOICE_COMMAND", "PHONE_ANSWER", "PHONE_END_CALL", 
    "NAVIGATION", "LANE_ASSIST", "PARKING_ASSIST", "HILL_DESCENT", "HUD_ADJUST", 
    "GLOVE_BOX_RELEASE", "FOG_LIGHTS", "EMERGENCY_BRAKE", "TRAILER_CONTROL", 
    "AUTO_HOLD", "HANDS_FREE", "SEAT_HEATER", "SEAT_COOLER"
};

const char* getHardKeyName(HardKey key) {
    if (key >= 0 && key < NUM_KEYS) {
        return hardKeyNames[key];
    }
    return "UNKNOWN";
}

// Initializes an observer array of size NUM_KEY
void initializeObservers() {
    for (int i = 0; i < NUM_KEYS; i++) {
        observer[i] = NULL;
    }
    printf("initialize success");
}

void registerHandler(HardKey hardkey, Handler handler) {

    Observer *newObserver = (Observer*)malloc(sizeof(Observer));
    newObserver->handler = handler;
    newObserver->next = NULL;
    if (observer[hardkey] == NULL) {
        observer[hardkey] = newObserver;
    } else {
        Observer *temp = observer[hardkey];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newObserver;
    }

}

// If there is the same handler for the input hardkey, the current observer is removed.
void unregisterHandler(HardKey hardKey, Handler handler) {
    Observer **now = &observer[hardKey];
    while (*now) {
        if ((*now) -> handler == handler) {
            Observer* del = *now;
            *now = (*now) -> next;
            free(del);
            return; 
        }
        now = &(*now) -> next;
    }
}

// Calls all handlers registered with the input hardkey
void notifyHandlers(HardKey hardKey) {
    Observer *now = observer[hardKey];
    while (now) {
        now -> handler();
        now = now -> next;
    }
}

// It is executed first when an event for hardkey is registered and the handler is called through notifyhandler.
void handlerEvent(HardKey hardKey) {
    notifyHandlers(hardKey);
}