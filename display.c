#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "RadioSource.h"
#include "ClimateTemp.h"
#include "ClimateFan.h"
#include "ClimateAirflow.h"
#include "Defrost.h"
#include "PowerWindows.h"


void displayMenu() {
    printf("\nAvailable features:\n");
    printf("1. HORN\n");
    printf("2. HEADLIGHTS\n");
    printf("10. RADIO_SOURCE\n");
    printf("11. ClimateTemp\n");
    printf("12. ClimateFan\n");
    printf("13. CLIMATE_AIRFLOW\n");
    printf("14. DEFROST\n");
    printf("15. POWER_WINDOWS\n");
    printf("16. WINDOW_LOCK\n");
    printf("17. DOOR_LOCKS\n");
    printf("18. MIRROR_ADJUST\n");
    printf("19. SEAT_ADJUST\n");


    printf("50. EXIT\n");
}

void handleHornCommands() {
    handlerEvent(HORN);
}


// 라디오
void handleRadioSourceCommands() {
    handlerEvent(RADIO_SOURCE);

}
// 기후 체인지
void handleClimateTempCommands() {
    handlerEvent(CLIMATE_TEMP);

}
// 펜 레벨 선택
void handleClimateFanCommands(){
    handlerEvent(CLIMATE_FAN);
}

// 공기 흐름
void handleClimateAirflowCommands(){
    handlerEvent(CLIMATE_AIRFLOW);
}

void handleDefrostCommands(){
    handlerEvent(DEFROST);
}

void handlePowerWindowsCommands(){
    handlerEvent(POWER_WINDOWS);
};

void initializeFeatureHandlers() {
    // Initialize handlers for various features
    initializeHornHandlers();
    initializeRadioSourceHandlers();
    initializeClimateTempHandlers();
    initializeClimateFanHandlers();
    initializeClimateAirflowHandlers();
    initializeDefrostlers();
    initializePowerWindowsHandlers();

}

void cleanupFeatureHandlers() {
    // Unregister handlers for various features
    unregisterHandler(HORN, handleHorn);
}
