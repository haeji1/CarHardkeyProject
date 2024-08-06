#include <stdio.h>
#include "menu.h"
#include "sunroof.h"
#include "drive.h"
#include "traction.h"
#include "observer.h"
#include "steering.h"

void sunroofMenu() {
    int option, value;
    sunroofControlFunction sc;

    printf("SUNROOF Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter sunroof state (0=Open, 1=Close, 2=Tilt): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("SUNROOF_CONTROL", value);

            // Set the sunroof control function
            if (value == 0) {
                sc = openSunroof;
            } else if (value == 1) {
                sc = closeSunroof;
            } else {
                sc = tiltSunroof;
            }

            // Execute the traction control function
            sunroofControl(sc);
            registerHandler(SUNROOF_CONTROL, sc);
            // Notify the event
            handlerEvent(SUNROOF_CONTROL);
            unregisterHandler(SUNROOF_CONTROL, sc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("SUNROOF_CONTROL");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void driveModeMenu() {
    int option, value;
    driveModeControlFunction dc;

    printf("Drive mode Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter drive mode (0=Eco, 1=Sports, 2=Normal): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("DRIVE_MODE", value);

            // Set the drive mode control function
            if (value == 0) {
                dc = ecoMode;
            } else if (value == 1) {
                dc = sportsMode;
            } else {
                dc = normalMode;
            }

            // Execute the traction control function
            driveModeControl(dc);
            registerHandler(DRIVE_MODE, dc);
            // Notify the event
            handlerEvent(DRIVE_MODE);
            unregisterHandler(DRIVE_MODE, dc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("DRIVE_MODE");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void tractionMenu() {
    int option, value;
    tractionControlFunction tc;

    printf("TRACTION Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter traction state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("TRACTION_CONTROL", value);

            // Set the traction control function
            if (value == 0) {
                tc = tractionOff;
            } else {
                tc = tractionOn;
            }

            // Execute the traction control function
            tractionControl(tc);
            registerHandler(TRACTION_CONTROL, tc);
            // Notify the event
            handlerEvent(TRACTION_CONTROL);
            unregisterHandler(TRACTION_CONTROL, tc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void steeringMenu() {
    int option, value;
    steeringControlFunction sc;

    printf("Steering Adjust Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter Steering Adjust (0=Up, 1=Down, 2=In, 3=Out): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2 && value != 3)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("DRIVE_MODE", value);

            // Set the steering control function
            if (value == 0) {
                sc = upSteering;
            } else if (value == 1) {
                sc = downSteering;
            } else if (value == 2) {
                sc = inSteering;
            } else {
                sc = outSteering;
            }

            // Execute the traction control function
            steeringControl(sc);
            registerHandler(STEERING_ADJUST, sc);
            // Notify the event
            handlerEvent(STEERING_ADJUST);
            unregisterHandler(STEERING_ADJUST, sc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("STEERING_ADJUST");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }

}