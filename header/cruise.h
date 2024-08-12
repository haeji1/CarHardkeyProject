#ifndef CRUISE_CONTROL_H
#define CRUISE_CONTROL_H

typedef struct {
    int cruiseState; // 0 = Off, 1 = On
    int speed; // Speed setting
} CruiseControlState;

typedef void(*cruiseControlFunction)(CruiseControlState*);


void activateCruiseControl(CruiseControlState *cs);
void deactivateCruiseControl(CruiseControlState *cs);
void adjustCruiseControlSpeed(CruiseControlState *cs);

void setCruiseControlState(CruiseControlState *cs, int state);
void setCruiseControlSpeed(CruiseControlState *cs, int speed);

void cruiseControlAction(cruiseControlFunction cc);

#endif