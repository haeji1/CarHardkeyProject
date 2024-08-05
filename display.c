#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "sunroof.h"

void displayMenu() {
    printf("\nAvailable features:\n");
    printf("1. HORN\n");
    printf("2. HEADLIGHTS\n");
    printf("3. RADIO\n");
    printf("20. SUNROOF\n");
    printf("21. TRUNK\n");
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

// void handleSunroofCommands() {
//     char input[10];

//     printf("Enter Sunroof command (OPEN/CLOSE/TILT): ");
//     if (scanf("%9s", input) != 1) {
//         perror("scanf failed");
//         exit(EXIT_FAILURE);
//     }

//     if (strcmp(input, "OPEN") == 0) {
//         notifyHandlers(SUNROOF_CONTROL); 
//     } else if (strcmp(input, "CLOSE") == 0) {
//         notifyHandlers(SUNROOF_CONTROL);
//     } else if (strcmp(input, "TILT") == 0) {
//         notifyHandlers(SUNROOF_CONTROL);
//     } else {
//         printf("Unknown Sunroof command.\n");
//     }
// }

void initializeFeatureHandlers() {
    // Initialize handlers for various features
    initializeHornHandlers();
    initializeSunroofHandlers();

}

void cleanupFeatureHandlers() {
    // Unregister handlers for various features
    unregisterHandler(HORN, handleHornOff);
}
