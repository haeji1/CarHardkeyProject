#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"

void displayMenu() {
    printf("\nAvailable features:\n");
    printf("1. HORN\n");
    printf("2. HEADLIGHTS\n");
    printf("3. RADIO\n");
    printf("4. EXIT\n");
    printf("3O. \n");
    printf("31. \n");
    printf("32. \n");
    printf("33. \n");
    printf("34. \n");
    printf("35. \n");
    printf("36. \n");
    printf("37. \n");
    printf("38. \n");
    printf("39. \n");



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

void initializeFeatureHandlers() {
    // Initialize handlers for various features
    initializeHornHandlers();
}

void cleanupFeatureHandlers() {
    // Unregister handlers for various features
    unregisterHandler(HORN, handleHornOff);
}
