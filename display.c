#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "auto_hold.h"

void displayMenu() {
    printf("\nAvailable features:\n");
    printf("40. Hud Adjust\n");
    printf("41. Glove Box Release\n");
    printf("42. Fog Light\n");
    printf("43. Emergency Brake\n");
    printf("44. Trailer Control\n");
    printf("45. Auto Hold\n");
    printf("46. Hands Free\n");
    printf("47. Seat Heater\n");
    printf("48. Seat Cooler\n");
    printf("50. EXIT\n");
}

// void autoHoldMenu() {
//     int option, value;
//     autoHoldFunction af;

//     printf(" Menu:\n");
//     printf("1. Write value to file\n");
//     printf("2. Listen to event\n");
//     printf("Enter your choice: ");
//     if (scanf("%d", &option) != 1) {
//         printf("Invalid input. Returning to menu.\n");
//         return;
//     }


// }






void initializeFeatureHandlers() {
    // Initialize handlers for various features
    
    // initializeAutoHoldHandlers();
    // initializeSunroofHandlers();
    // initializeDriveModeHandlers();
    // initializeSteeringAdjustHandlers();
}

void cleanupFeatureHandlers() {
    // Unregister handlers 
    // unregisterHandler(HORN, handleHornOff);
}




