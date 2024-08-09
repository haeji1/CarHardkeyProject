#ifndef EMERGENCY_BRAKE_H
#define EMERGENCY_BRAKE_H

typedef void (*emergencyBrakeFunction)();

void activateEmergencyBrake(void);
void setEmergencyBrake(emergencyBrakeFunction ebf);

#endif // EMERGENCY_BRAKE_H
