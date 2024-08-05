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
            
            handleCommands(selection);

        }
    }

    cleanupFeatureHandlers();

    return 0;
}