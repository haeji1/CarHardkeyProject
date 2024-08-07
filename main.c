#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "observer.h"
#include "horn.h"
#include "RadioSource.h"
#include "ClimateTemp.h"
#include "ClimateFan.h"
#include "ClimateAirflow.h"
#include "Defrost.h"
#include "PowerWindows.h"
#include "WindowLock.h"
#include "DoorLock.h"
#include "MirrorAdjust.h"


//void initializeFeatureHandlers();
//void cleanupFeatureHandlers();

int main() {
    char input[10];
    int ignitionStarted = 0;
    int selection;

    //initializeFeatureHandlers();                    handleRadioSourceCommands();

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
                printf("Unknown command. Please use ON or EXIT.\n");
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

            switch (selection) {
                case 1:
                    handleHornCommands();
                    break;
                case 10:
                    handleRadioSourceCommands();
                    break;
                case 11:
                    handleClimateTempCommands();
                    break;
                case 12:
                    handleClimateFanCommands();
                    break;
                case 13:
                    handleClimateAirflowCommands();
                    break;
                case 14:
                    handleDefrostCommands();
                    break;
                case 15:
                    handlePowerWindowsCommands();
                    break;
                case 16:
                    handleWindowLockCommands();
                    break;
                case 17:
                    handleDoorLockCommands();
                    break;
                case 18:
                    handleMirrorAdjustCommands();
                    break;
                case 19:
                    handleSeatAdjustCommands();
                    break;
                case 50:
                    break; // Exit the program
                default:
                    printf("Invalid selection. Please try again.\n");
                    break;
            }
            break;
        }
    }

    //cleanupFeatureHandlers();

    return 0;
}
