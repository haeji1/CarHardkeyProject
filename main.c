#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"

void initializeFeatureHandlers();
void cleanupFeatureHandlers();

void openSunroof() {
    printf("Sunroof opened.\n");
}

void closeSunroof() {
    printf("Sunroof closed.\n");
}

void trunkOpened() {
    printf("Trunk opened.\n");
}

void trunkClosed() {
    printf("Trunk closed.\n");
}

void printWelcomeMenu() {
    printf("=========Welcome to the Hardkey Project CLI===========\n");
    printf("Available hard keys:\n");
    printf("20. sunroof\n");
    printf("21. trunk\n");
    printf("3. exit\n");
}

void printOperationMenu() {
    printf("\n");
    printf("====================\n");
    printf("Choose an operation:\n");
    printf("1. register handler\n");
    printf("2. unregister handler\n");
    printf("3. notify\n");
    printf("4. back\n");
    printf("====================\n");
}

void printSunroofHandlerMenu() {
    printf("\n");
    printf("Choose a sunroof handler to register/unregister:\n");
    printf("1. openSunroof\n");
    printf("2. closeSunroof\n");
    printf("3. back\n");
}

void printTrunkHandlerMenu() {
    printf("\n");
    printf("Choose a trunk handler to register/unregister:\n");
    printf("1. trunkOpened\n");
    printf("2. trunkClosed\n");
    printf("3. back\n");
}

void handleSunroofOperations() {
    char input[10];
    int choice;
    while (1) {
        printOperationMenu();
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:  // register handler
                printSunroofHandlerMenu();
                printf("Enter your choice: ");
                fgets(input, sizeof(input), stdin);
                choice = atoi(input);
                if (choice == 1) {
                    registerHandler(SUNROOF_CONTROL, openSunroof);
                    printf("openSunroof handler registered.\n");
                } else if (choice == 2) {
                    registerHandler(SUNROOF_CONTROL, closeSunroof);
                    printf("closeSunroof handler registered.\n");
                }
                break;
            case 2:  // unregister handler
                printSunroofHandlerMenu();
                printf("Enter your choice: ");
                fgets(input, sizeof(input), stdin);
                choice = atoi(input);
                if (choice == 20) {
                    unregisterHandler(SUNROOF_CONTROL, openSunroof);
                    printf("openSunroof handler unregistered.\n");
                } else if (choice == 21) {
                    unregisterHandler(SUNROOF_CONTROL, closeSunroof);
                    printf("closeSunroof handler unregistered.\n");
                }
                break;
            case 3:  // notify
                if (observer[SUNROOF_CONTROL] == NULL) {
                    printf("No handlers registered.\n");
                } else {
                    printf("====================\n");
                    handlerEvent(SUNROOF_CONTROL);
                    printf("====================\n");
                }
                break;
            case 4:  // back
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void handleTrunkOperations() {
    char input[10];
    int choice;
    while (1) {
        printOperationMenu();
        printf("Please select and enter numbers ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:  // register handler
                printTrunkHandlerMenu();
                printf("Enter your choice: ");
                fgets(input, sizeof(input), stdin);
                choice = atoi(input);
                if (choice == 1) {
                    registerHandler(TRUNK_RELEASE, trunkOpened);
                    printf("trunkOpened handler registered.\n");
                } else if (choice == 2) {
                    registerHandler(TRUNK_RELEASE, trunkClosed);
                    printf("trunkClosed handler registered.\n");
                }
                break;
            case 2:  // unregister handler
                printTrunkHandlerMenu();
                printf("Enter your choice: ");
                fgets(input, sizeof(input), stdin);
                choice = atoi(input);
                if (choice == 1) {
                    unregisterHandler(TRUNK_RELEASE, trunkOpened);
                    printf("trunkOpened handler unregistered.\n");
                } else if (choice == 2) {
                    unregisterHandler(TRUNK_RELEASE, trunkClosed);
                    printf("trunkClosed handler unregistered.\n");
                }
                break;
            case 3:  // notify
                handlerEvent(TRUNK_RELEASE);
                break;
            case 4:  // back
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

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
            } else if (selection == 4) {
                break; // Exit the program
            } else {
                printf("Invalid selection. Please try again.\n");
            }
        }
    }

    cleanupFeatureHandlers();

    return 0;
}