#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"
#include "VOICE_COMMAND.c"
#include "MUTE_BUTTON.c"

void initializeFeatureHandlers();
void cleanupFeatureHandlers();

int main() {

    char input[10];
    int ignitionStarted = 0; 
    int selection;

    initializeObservers();
    initializeFeatureHandlers();

    registerHandler(MUTE_BUTTON, muteButtonHandler);
    registerHandler(VOICE_COMMAND, Voice_Command_toggle);


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
            }
            else if(selection ==30) {
                break;
            }
            else if(selection ==31){

                break;
            }
            else if(selection ==32) {
                handlerEvent(MUTE_BUTTON); // MUTE_BUTTON 이벤트를 처리하여 음성 상태 변경
           }
            else if(selection ==33) {
                handlerEvent(VOICE_COMMAND); // MUTE_BUTTON 이벤트를 처리하여 음성 상태 변경
            }
            else if(selection ==34) {

            }
            else if(selection ==35) {

            }
            else if(selection ==36) {

            }
            else if(selection ==37) {


            }
            else if(selection ==38) {

            }
            else if(selection ==39) {

            }else{
                printf("Invalid selection. Please try again.\n");
            }
        }
    }


    cleanupFeatureHandlers();

    return 0;
}