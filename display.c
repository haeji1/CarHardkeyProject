#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "sunroof.h"
#include "drive.h"
#include "steering.h"
#include "traction.h"

void displayMenu() {
    printf("\nAvailable features:\n");
    printf("1. HORN\n");
    printf("2. HEADLIGHTS\n");
    printf("3. RADIO\n");
    printf("20. SUNROOF\n");
    printf("21. TRUNK\n");
    printf("24. DRIVEMODE\n");
    printf("25. TRACTION\n");
    printf("28. STEERINGADJUST\n");
    printf("29. INTERIORLIGHT\n");
    printf("4. EXIT\n");
}

void handleHornCommands() {
    char input[10];
    printf("Enter HORN command (HORN_ON/HORN_OFF): ");
    if (scanf("%9s", input) != 1) {
        perror("scanf failed");
        exit(EXIT_FAILURE);
    }

    if (strcmp(input, "HORN_ON") == 0) {
        notifyHandlers(HORN); // Handle the HORN ON event
    } else if (strcmp(input, "HORN_OFF") == 0) {
        handleHornOff(); // Handle the HORN OFF event
    } else {
        printf("Unknown HORN command.\n");
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

void initializeFeatureHandlers() {
    // Initialize handlers for various features
    initializeHornHandlers();
    initializeSunroofHandlers();
    initializeDriveModeHandlers();
    initializeSteeringAdjustHandlers();
}

void cleanupFeatureHandlers() {
    // Unregister handlers for various features
    unregisterHandler(HORN, handleHornOff);
}
