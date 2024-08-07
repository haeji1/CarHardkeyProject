#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"
#include "sunroof.h"
#include "drive.h"
#include "steering.h"
#include "hseat.h"
#include "interior.h"
#include "traction.h"
#include "menu.h"

void initializeFeatureHandlers();
void cleanupFeatureHandlers();

int main() {
    char input[10];
    int ignitionStarted = 0; 
    int selection;

    // initializeObservers();
    initializeFeatureHandlers();

    while (1) {
        if(!ignitionStarted){
            printf("\nEnter command for IGNITION (ON/OFF/EXIT): ");
            if (scanf("%9s", input) != 1) {
                perror("scanf failed");
                exit(EXIT_FAILURE);
            }

            if (strcmp(input, "ON") == 0) {
                handlerEvent(HORN);// -> notify 다른 기능들
                handlerEvent(HEADLIGHTS);
                ignitionStarted = 1; // Set the ignition started flag
                printf("Engine started. Select a feature using the menu.\n");
            } else if (strcmp(input, "OFF") == 0) {
                //handleShutdownEvent();
                printf("Unknown command. Please use START or EXIT.\n");
                break;
            } else if (strcmp(input, "EXIT") == 0) {
                break;
            } else {
                printf("Unknown command.\n");
            }
        }else{
            displayMenu();
            printf("Enter your choice (number): ");
            if (scanf("%d", &selection) != 1) {
                perror("scanf failed");
                exit(EXIT_FAILURE);
            }
            
            if (selection == 1) {
                handleHornCommands();
            } else if (selection == 2) {
                handleHeadlightsCommands();
            } else if (selection == 3) {
                handleTurnSignalsCommands();
            } else if (selection == 4) {
                handleWindshieldWipersCommands();
            } else if (selection == 5) {
                handleHazardLightsCommands();
            } else if (selection == 6) {
                handleCruiseControlCommands();
            } else if (selection == 7) {
                handleRadioVolumeCommands();
            } else if (selection == 8) {
                handleRadioTuningCommands();
            } else if (selection == 50) {
                //
            } else if (selection == 20) {
                sunroofMenu();
            } else if (selection == 21) {
                trunkReleaseMenu();
            } else if(selection == 22) {
                fuelCapReleaseMenu();
            } else if (selection == 23) {
                parkingBrakeMenu();
            }
            else if (selection == 24) {
                driveModeMenu();
            } else if (selection == 25) {
                tractionMenu();
            } else if (selection == 26) {
                heatedSeatMenu();
            } else if (selection == 27) {
                cooledSeatMenu();
            } else if (selection == 28) {
                steeringMenu();
            } else if (selection == 29) {
                interiorLightMenu();
            }
            else if (selection == 4) {
                break; // Exit the program
            } else {
                printf("Invalid selection. Please try again.\n");
            }
        }
    }

    cleanupFeatureHandlers();

    return 0;
}