// Header guard to prevent duplicate processing
#ifndef OBSERVER_H
#define OBSERVER_H

#define NUM_KEYS 48

typedef enum {
    IGNITION,            // Start/Stop engine
    HORN,                // Activate horn
    HEADLIGHTS,          // Toggle headlights
    TURN_SIGNALS,        // Activate turn signals
    WINDSHIELD_WIPERS,   // Operate windshield wipers
    HAZARD_LIGHTS,       // Toggle hazard lights
    CRUISE_CONTROL,      // Enable/Disable cruise control
    RADIO_VOLUME,        // Adjust radio volume
    RADIO_TUNING,        // Change radio station or track
    RADIO_SOURCE,        // Switch radio source (AM/FM/Bluetooth/etc.)
    CLIMATE_TEMP,        // Adjust climate control temperature
    CLIMATE_FAN,         // Adjust climate control fan speed
    CLIMATE_AIRFLOW,     // Set climate control airflow direction
    DEFROST,             // Activate defrost
    POWER_WINDOWS,       // Operate power windows
    WINDOW_LOCK,         // Lock/unlock power windows
    DOOR_LOCKS,          // Lock/unlock doors
    MIRROR_ADJUST,       // Adjust side mirrors
    SEAT_ADJUST,         // Adjust seat position and lumbar support
    SUNROOF_CONTROL,     // Open/close sunroof
    TRUNK_RELEASE,       // Release trunk
    FUEL_CAP_RELEASE,    // Release fuel cap
    PARKING_BRAKE,       // Engage/disengage parking brake
    DRIVE_MODE,          // Change drive mode (e.g., Eco, Sport)
    TRACTION_CONTROL,    // Enable/Disable traction control
    HEATED_SEATS,        // Activate heated seats
    COOLED_SEATS,        // Activate cooled seats
    STEERING_ADJUST,     // Adjust steering wheel position
    INTERIOR_LIGHT,      // Control interior lighting
    REAR_DEFROST,        // Activate rear window defrost
    CHILD_LOCK,          // Engage/disengage child lock
    MUTE_BUTTON,         // Mute/unmute audio
    VOICE_COMMAND,       // Activate voice command system
    PHONE_ANSWER,        // Answer incoming phone call
    PHONE_END_CALL,      // End phone call
    NAVIGATION,          // Activate navigation system
    LANE_ASSIST,         // Enable/Disable lane assist
    PARKING_ASSIST,      // Enable/Disable parking assist
    HILL_DESCENT,        // Enable/Disable hill descent control
    HUD_ADJUST,          // Adjust head-up display
    GLOVE_BOX_RELEASE,   // Open glove box
    FOG_LIGHTS,          // Toggle fog lights
    EMERGENCY_BRAKE,     // Activate emergency braking
    TRAILER_CONTROL,     // Control trailer (if equipped)
    AUTO_HOLD,           // Enable/Disable auto hold feature
    HANDS_FREE,          // Activate hands-free mode
    SEAT_HEATER,         // Activate seat heater (individual seat)
    SEAT_COOLER          // Activate seat cooler (individual seat)
} HardKey;

// Declaration of Handler, a function pointer with no return value and no parameters
typedef void (*Handler)(void);

// To connect observers, the address of the next observer must be declared together.
typedef struct Observer {
    Handler handler;
    struct Observer *next;
} Observer;

extern Observer *observer[NUM_KEYS];

void registerHandler(HardKey key, Handler handler);
void unregisterHandler(HardKey key, Handler handler);
void unregisterFunction(HardKey key, Handler handler);
void notifyHandlers(HardKey key);
void handlerEvent(HardKey key);

#endif
