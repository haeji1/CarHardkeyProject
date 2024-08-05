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
    printf("3O. REAR_DEFROST \n");
    printf("31. CHILD_LOCK\n");
    printf("32. MUTE_BUTTON\n");
    printf("33. VOICE_COMMAND\n");
    printf("34. PHONE_ANSWER\n");
    printf("35. PHONE_END_CALL\n");
    printf("36. NAVIGATION\n");
    printf("37. LANE_ASSIST\n");
    printf("38. PARKING_ASSIST\n");
    printf("39. HILL_DESCENT\n");


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
