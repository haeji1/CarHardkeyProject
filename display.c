#include <stdio.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "RadioSource.h"
#include "ClimateTemp.h"
#include "ClimateFan.h"
#include "ClimateAirflow.h"
#include "Defrost.h"
#include "PowerWindows.h"
#include "WindowLock.h"
#include "DoorLock.h"
#include "MirrorAdjust.h"

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


void handleRadioSourceCommands() {
    int option, value;
    radioSourceControlFunction rs = NULL;  // Initialize rs to NULL

    printf("TRACTION Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Select RadioSource\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            break;
        case 2:
            handleRadioSource(&rs);
            // Register and handle event if needed
            registerHandler(RADIO_SOURCE, rs);
            printf("display.c rs adress is : %p\n", rs);
            handlerEvent(RADIO_SOURCE);


            unregisterHandler(RADIO_SOURCE, rs);
            break;

        case 3:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void handleClimateTempCommands() {
    handlerEvent(CLIMATE_TEMP);
}

void handleClimateFanCommands() {
    handlerEvent(CLIMATE_FAN);
}

void handleClimateAirflowCommands() {
    handlerEvent(CLIMATE_AIRFLOW);
}

void handleDefrostCommands() {
    handlerEvent(DEFROST);
}

void handlePowerWindowsCommands() {
    handlerEvent(POWER_WINDOWS);
}

void handleWindowLockCommands() {
    handlerEvent(WINDOW_LOCK);
}

void handleDoorLockCommands() {
    handlerEvent(DOOR_LOCKS);
}

void handleMirrorAdjustCommands() {
    handlerEvent(MIRROR_ADJUST);
}

void initializeFeatureHandlers() {
    //initializeHornHandlers();
    //initializeRadioSourceHandlers();
/*    initializeClimateTempHandlers();
    initializeClimateFanHandlers();
    initializeClimateAirflowHandlers();
    initializeDefrostHandlers();
    initializePowerWindowsHandlers();
    initializeWindowLockHandlers();
    initializeDoorLockHandlers();
    initializeMirrorAdjustHandlers();*/
}

void cleanupFeatureHandlers() {
    unregisterHandler(HORN, handleHornCommands);
    unregisterHandler(RADIO_SOURCE, handleRadioSourceCommands);
    unregisterHandler(CLIMATE_TEMP, handleClimateTempCommands);
    unregisterHandler(CLIMATE_FAN, handleClimateFanCommands);
    unregisterHandler(CLIMATE_AIRFLOW, handleClimateAirflowCommands);
    unregisterHandler(DEFROST, handleDefrostCommands);
    unregisterHandler(POWER_WINDOWS, handlePowerWindowsCommands);
    unregisterHandler(WINDOW_LOCK, handleWindowLockCommands);
    unregisterHandler(DOOR_LOCKS, handleDoorLockCommands);
    unregisterHandler(MIRROR_ADJUST, handleMirrorAdjustCommands);
}
