#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "cruise.h"

static int cruiseState = 1; 
static int speed = 60;

void onCruise();
void setSpeed();

void handleCruiseControl(void) {

    int opt;
    printf(" == CRUISE_CONTROL options == \n");
    printf("1. On \n");
    printf("2. EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
        onCruise();
    } else{
        printf("Unknown CRUISE_CONTROL command.\n");
    }

}

void onCruise(){
    if (cruiseState == 1) {
        printf("Cruise control is already ON.\n");
    } else {
        cruiseState = 1;
        printf("Cruise control turned ON.\n");
        setSpeed();
    }
}

void setSpeed(){
    printf("Enter the setting speed : ");
    int speed;
    scanf("%d", &speed);
    printf("Now speed is $d.\n", speed);
}

void initializeCruiseControlHandlers() {
    registerHandler(CRUISE_CONTROL, handleCruiseControl);
}