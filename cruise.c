#include <stdio.h>
#include "cruise.h"

/*
    Cruise State
    0 : off
    1 : on
*/

void setCruiseControlState(CruiseControlState *cs, int state) {
    if(state == 1){
        cs->cruiseState = state;
        printf("Cruise control state set to %d\n", cs->cruiseState);
    }else{
        
        printf("Cruise control turned off\n");

    }
}

void setCruiseControlSpeed(CruiseControlState *cs, int speed) {
    if (cs->cruiseState == 1) {
        cs->speed = speed;
        printf("Cruise control speed set to %d\n", cs->speed);
    } else {
        printf("Cannot set speed. Cruise control is off.\n");
    }
}

void cruiseControlAction(cruiseControlFunction ccFunc, CruiseControlState *cs) {
    ccFunc(cs);
}

void activateCruiseControl(CruiseControlState *cs) {
    setCruiseControlState(cs, 1);
    printf("Cruise control turned ON.\n");
}

void deactivateCruiseControl(CruiseControlState *cs) {
    setCruiseControlState(cs, 0);
    printf("Cruise control turned OFF.\n");
}

void adjustCruiseControlSpeed(CruiseControlState *cs) {
    if (cs->cruiseState == 1) {
        int newSpeed;
        printf("Enter new cruise control speed: ");
        if (scanf("%d", &newSpeed) == 1) {
            setCruiseControlSpeed(cs, newSpeed);
        } else {
            printf("Invalid input.\n");
        }
    } else {
        printf("Cruise control is off. Cannot adjust speed.\n");
    }
}