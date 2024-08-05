#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"

void initializeFeatureHandlers();
void cleanupFeatureHandlers();

int main() {
    char input[10];
    int ignitionStarted = 0;
    int selection;

    initializeObservers();
    initializeFeatureHandlers();

    while (1) {
        if(!ignitionStarted){
            printf("Enter command (ON/OFF/EXIT): ");
            if (scanf("%9s", input) != 1) {
                perror("scanf failed");
                exit(EXIT_FAILURE);
            }

            if (strcmp(input, "ON") == 0) {
                notifyHandlers(IGNITION);
                //notifyHandlers(HORN);
                handlerEvent(RADIO_SOURCE);
                // minseokK 9~19 NotifyHandler
                // notifyHandlers(RADIO_SOURCE);
                // notifyHandlers(CLIMATE_TEMP);
                // notifyHandlers(CLIMATE_FAN);
                // notifyHandlers(CLIMATE_AIRFLOW);
                // notifyHandlers(DEFROST);
                // notifyHandlers(POWER_WINDOWS);
                // notifyHandlers(WINDOW_LOCK);
                // notifyHandlers(DOOR_LOCKS);
                // notifyHandlers(MIRROR_ADJUST);
                // notifyHandlers(SEAT_ADJUST);
                //////////////////////////////
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
            } else if (selection == 10) {
                handleRadioSourceCommands();
            } else if(selection == 11) {
                handleClimateTempCommands();
            } else if (selection == 12) {
                handleClimateFanCommands();
            } else if(selection == 13) {
                handleClimateAirflowCommands();
            } else if (selection == 14) {
                handleDefrostCommands();
            } else if(selection == 15) {
                handlePowerWindowsCommands();
            } else if (selection == 16) {

            } else if(selection == 17) {

            } else if (selection == 18) {

            } else if(selection == 19) {

            }

            else if (selection == 50) {
                break; // Exit the program
            } else {
                printf("Invalid selection. Please try again.\n");
            }
        }
    }

    cleanupFeatureHandlers();

    return 0;
}