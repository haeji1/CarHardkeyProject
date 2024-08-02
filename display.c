#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "headlights.h"

void displayMenu() {
    printf("\nAvailable features:\n");
    printf("1. HORN\n");
    printf("2. HEADLIGHTS\n");
    printf("3. TURN_SIGNALS\n");
    printf("4. WINDSHIELD_WIPERS\n");
    printf("5. HAZARD_LIGHTS\n");
    printf("6. CRUISE_CONTROL\n");
    printf("7. RADIO_VOLUME\n");
    printf("8. RADIO_TUNING\n");
    printf("50. EXIT\n");
}

void handleHornCommands() {
    handlerEvent(HORN);
}

void handleHeadlightsCommands() {

    handlerEvent(HEADLIGHTS);
    //unregisterHandler(HEADLIGHTS);

}

void initializeFeatureHandlers() {
    // Initialize handlers for various features
    initializeHornHandlers();
    initializeHeadlightsHandlers();
}

void cleanupFeatureHandlers() {
    // Unregister handlers for various features
    unregisterHandler(HORN, handleHorn);
}