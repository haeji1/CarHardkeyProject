#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"
#include "hud_adjust.h"
#include "glove_box_release.h"
#include "fog_lights.h"
#include "emergency_brake.h"
#include "trailer_control.h"
#include "auto_hold.h"
#include "hands_free.h"
// #include "seat_heater.h"
// #include "seat_cooler.h"
#include "menu.h"

// Function prototypes
void initializeFeatureHandlers();
void cleanupFeatureHandlers();

int main() {
    char input[10];
    int ignitionStarted = 0;
    int selection;

    // Initialize function pointers
    initializeFeatureHandlers();

    while (1) {
        if (!ignitionStarted) {
            printf("Enter command (ON/OFF/EXIT): ");
            if (scanf("%9s", input) != 1) {
                perror("scanf failed");
                exit(EXIT_FAILURE);
            }

            if (strcmp(input, "ON") == 0) {
                notifyHandlers(IGNITION);
                ignitionStarted = 1; // Set the ignition started flag
                printf("Engine started. Select a feature using the menu.\n");
            } else if (strcmp(input, "OFF") == 0) {
                printf("Shutting down...\n");
                break;
            } else if (strcmp(input, "EXIT") == 0) {
                break;
            } else {
                printf("Unknown command.\n");
            }
        } else {
            displayMenu();
            printf("Enter your choice (number): ");
            if (scanf("%d", &selection) != 1) {
                perror("scanf failed");
                exit(EXIT_FAILURE);
            }

            if (selection == 40) {
                hudAdjustMenu();
            } else if (selection == 41) {
                gloveBoxReleaseMenu();
            } else if (selection == 42) {
                fogLightsMenu();
            } else if (selection == 43) {
                emergencyBrakeMenu();
            } else if (selection == 44) {
                trailerControlMenu();
            } else if (selection == 45) {
                autoHoldMenu();
            } else if (selection == 46) {
                handsFreeMenu();
            } else if (selection == 47) {
                // seatHeaterMenu();
            } else if (selection == 48) {
                // seatCoolerMenu();
            } else if (selection == 50) {
                break; // Exit the program
            } else {
                printf("Invalid selection. Please try again.\n");
            }
        }
    }

    cleanupFeatureHandlers();

    return 0;
}

