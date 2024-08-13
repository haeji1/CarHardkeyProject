#include <stdio.h>
#include "display.h"

void displayMenu() {
    printf("****************************************\n");
    printf("\n        Available features:\n");
    for(int i=1; i<NUM_KEYS; i++){
        printf("       %d. %s \n", i, getHardKeyName(i));
    }
    printf("       49. EXIT\n");
    printf("****************************************\n");
}

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