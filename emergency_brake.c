#include <stdio.h>
#include "emergency_brake.h"

//activate signal 1

typedef void(*emergencyBrakeFunction)();

void activateEmergencyBrake() {
    printf("Emergency brake activated\n");
}

void setEmergencyBrake(emergencyBrakeFunction ebf) { 
    printf("Emergency brake setup successful\n");
}
