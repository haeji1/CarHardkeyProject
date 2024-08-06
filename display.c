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

    printf("RadioSouce Menu:\n");
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
    int option, value;
    ClimateTempControlFunction ct = NULL;  // Initialize rs to NULL

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
            handleClimateTemp(&ct);
            // Register and handle event if needed
            registerHandler(CLIMATE_TEMP, ct);
            printf("display.c rs adress is : %p\n", ct);
            handlerEvent(CLIMATE_TEMP);
            unregisterHandler(CLIMATE_TEMP, ct);
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

void handleClimateFanCommands() {
    int option, value;
    ClimateFanControlFunction cf = NULL;  // Initialize rs to NULL

    printf("RadioSouce Menu:\n");
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
            handleClimateFan(&cf);
            // Register and handle event if needed
            registerHandler(CLIMATE_FAN, cf);
            printf("display.c rs adress is : %p\n", cf);
            handlerEvent(CLIMATE_FAN);


            unregisterHandler(CLIMATE_FAN, cf);
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

void handleClimateAirflowCommands() {
    int option, value;
    ClimateAirflowControlFunction cfcf = NULL;  // Initialize rs to NULL

    printf("CLIMATE_AIRFLOW Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            handleClimateAirflow(&cfcf);
            // Register and handle event if needed
            registerHandler(CLIMATE_AIRFLOW, cfcf);
            printf("display.c rs adress is : %p\n", cfcf);
            handlerEvent(CLIMATE_AIRFLOW);


            unregisterHandler(CLIMATE_AIRFLOW, cfcf);
            break;
        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void handleDefrostCommands() {
    int option, value;
    DefrostControlFunction dfc = NULL;  // Initialize rs to NULL

    printf("DEFROST Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            handleDefrost(&dfc);
            // Register and handle event if needed
            registerHandler(DEFROST, dfc);
            printf("display.c rs adress is : %p\n", dfc);
            handlerEvent(DEFROST);
            unregisterHandler(DEFROST, dfc);
            break;
        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void handlePowerWindowsCommands() {
        int option, value;
    handlePowerWindowsControlFunction pwcf = NULL;  // Initialize rs to NULL

    printf("PowerWindows Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            handlePowerWindows(&pwcf);
            // Register and handle event if needed
            registerHandler(POWER_WINDOWS, pwcf);
            printf("display.c rs adress is : %p\n", pwcf);
            handlerEvent(POWER_WINDOWS);
            unregisterHandler(POWER_WINDOWS, pwcf);
            break;
        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void handleWindowLockCommands() {
    int option, value;
    WindowLockControlFunction wl = NULL;  // Initialize rs to NULL

    printf("PowerWindows Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            handleWindowLock(&wl);
            // Register and handle event if needed
            registerHandler(WINDOW_LOCK, wl);
            printf("display.c rs adress is : %p\n", wl);
            handlerEvent(WINDOW_LOCK);
            unregisterHandler(WINDOW_LOCK, wl);
            break;
        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void handleDoorLockCommands() {
    int option, value;
    DoorLockControlFunction dl = NULL;  // Initialize rs to NULL

    printf("PowerWindows Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            handleDoorLock(&dl);
            // Register and handle event if needed
            registerHandler(DOOR_LOCKS, dl);
            printf("display.c rs adress is : %p\n", dl);
            handlerEvent(DOOR_LOCKS);
            unregisterHandler(DOOR_LOCKS, dl);
            break;
        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void handleMirrorAdjustCommands() {
        int option, value;
    MirrorAdjustControlFunction ma = NULL;  // Initialize rs to NULL

    printf("PowerWindows Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            handleMirrorAdjust(&ma);
            // Register and handle event if needed
            registerHandler(MIRROR_ADJUST, ma);
            printf("display.c rs adress is : %p\n", ma);
            handlerEvent(MIRROR_ADJUST);
            unregisterHandler(MIRROR_ADJUST, ma);
            break;
        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}
void handleSeatAdjustCommands(){ // 파일 만들어애됨

}

/*
void initializeFeatureHandlers() {
    initializeHornHandlers();
    initializeRadioSourceHandlers();
    initializeClimateTempHandlers();
    initializeClimateFanHandlers();
    initializeClimateAirflowHandlers();
    initializeDefrostHandlers();
    initializePowerWindowsHandlers();
    initializeWindowLockHandlers();
    initializeDoorLockHandlers();
    initializeMirrorAdjustHandlers();
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
*/