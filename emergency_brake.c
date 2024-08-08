#include <stdio.h>
#include "emergency_brake.h"

//activate signal 1

typedef void(*emergencyBrakeFunction)();

void activateEmergencyBrake() {
    printf("\n***** Emergency brake activated *****\n");
}

void setEmergencyBrake(emergencyBrakeFunction ebf) { 
    printf("\n***** Change the current state successful *****\n");
}
