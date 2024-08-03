#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "RadioSource.h"
#include "ClimateTemp.h"


void displayMenu() {
    printf("\nAvailable features:\n");
    printf("1. HORN\n");
    printf("2. HEADLIGHTS\n");
    printf("10. RADIO\n");
    printf("11. ClimateTemp\n");
    printf("50. EXIT\n");
}

void handleHornCommands() {
    handlerEvent(HORN);
}


// 라디오
void handleRadioSourceCommands() {
    handlerEvent(RADIO_SOURCE);

}
// 기후 체인지
void handleClimateTempCommands() {
    handlerEvent(CLIMATE_TEMP);

}


void initializeFeatureHandlers() {
    // Initialize handlers for various features
    initializeHornHandlers();
    initializeRadioSourceHandlers();
    initializeClimateTempHandlers();

}

void cleanupFeatureHandlers() {
    // Unregister handlers for various features
    unregisterHandler(HORN, handleHornOff);
}
