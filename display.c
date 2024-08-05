#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "headlights.h"
#include "turnsignals.h"
#include "windshield.h"
#include "hazard.h"
#include "cruise.h"
#include "radio.h"

void displayMenu() {
    printf("\nAvailable features:\n");
    for(int i=1; i<NUM_KEYS; i++){
        printf("%d. %s \n", i, getHardKeyName(i));
    }
}

void handleCommands(int num){
    switch (num) {
        case 1:
            handlerEvent(HORN);
            printf("HORN command executed.\n");
        case 2:
            handlerEvent(HEADLIGHTS);
            printf("HEADLIGHTS command executed.\n");
        case 3:
            handlerEvent(TURN_SIGNALS);
            printf("TURN_SIGNALS command executed.\n");
        case 4:
            handlerEvent(WINDSHIELD_WIPERS);
            printf("WINDSHIELD_WIPERS command executed.\n");
        case 5:
            handlerEvent(HAZARD_LIGHTS);
            printf("HAZARD_LIGHTS command executed.\n");
        case 6:
            handlerEvent(CRUISE_CONTROL);
            printf("CRUISE_CONTROL command executed.\n");
        case 7:
            handlerEvent(RADIO_VOLUME);
            printf("RADIO_VOLUME command executed.\n");
        case 8:
            handlerEvent(RADIO_TUNING);
            printf("RADIO_TUNING command executed.\n");
        case 50:
            break; // Exit the program
        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }
}

void initializeFeatureHandlers() {
    // Initialize handlers for various features
    initializeHornHandlers();
    initializeHeadlightsHandlers();
    initializeTurnSignalsHandlers();
    initializeWindshieldWipersHandlers();
    initializeHazardLightsHandlers();
    initializeCruiseControlHandlers();
    initializeRadioHandlers();
}

void cleanupFeatureHandlers() {
    // Unregister handlers for various features
    unregisterHandler(HORN, handleHorn);
}
