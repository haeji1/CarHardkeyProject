#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"
#include "sunroof.h"
#include "drive.h"
#include "steering.h"
#include "interior.h"
#include "traction.c"

void initializeFeatureHandlers();
void cleanupFeatureHandlers();

int main() {
    char input[10];
    int ignitionStarted = 0;
    int selection;

    // initializeObservers();
    initializeFeatureHandlers();

    tractionControlFunction tc = tractionOn;
    tractionControl(tc);
    registerHandler(TRACTION_CONTROL, tc);
    handlerEvent(TRACTION_CONTROL);
    unregisterHandler(TRACTION_CONTROL, tc);

    while (1) {
        if(!ignitionStarted){
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
                //
            } else if (selection == 3) {
                //
            } else if (selection == 20) {
                // Execute sunroof operation based on strategy pattern
                printf("Select sunroof operation (0: Open, 1: Close, 2: Tilt): ");
                int sunroofOperation;
                if (scanf("%d", &sunroofOperation) != 1 || sunroofOperation < 0 || sunroofOperation > 2) {
                    printf("Invalid sunroof operation. Please enter 0, 1, or 2.\n");
                    continue;
                }
                executeSunroofOperation(sunroofOperation);
            } else if (selection == 21) {
                // trunk
            } else if (selection == 24) {
                printf("Select drivemode operation (0: Eco, 1: Sports, 2: Normal): ");
                int driveModeOperation;
                if (scanf("%d", &driveModeOperation) != 1 || driveModeOperation < 0 || driveModeOperation > 2) {
                    printf("Invalid drive mode. Please enter 0, 1, or 2.\n");
                    continue;
                }
                executeDriveModeOperation(driveModeOperation);
            } else if (selection == 28) {
                printf("Select steering adjust operation (0: Up, 1: Down, 2: In, 3: Out):");
                int steeringAjustOperation;
                if (scanf("%d", &steeringAjustOperation) != 1 || steeringAjustOperation < 0 || steeringAjustOperation > 2) {
                    printf("Invalid steering adjust. Please enter 0, 1, 2 or 3.\n");
                    continue;
                }
                executeSteeringAdjustOperation(steeringAjustOperation);
            } else if (selection == 29) {
                printf("Select interior light operation (0: Off, 1: On):");
                int interiorLightOperation;
                if (scanf("%d", &interiorLightOperation) != 1 || interiorLightOperation < 0 || interiorLightOperation > 2) {
                    printf("Invalid steering adjust. Please enter 0 or 1.\n");
                    continue;
                }
                executeInteriorLightOperation(interiorLightOperation);
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