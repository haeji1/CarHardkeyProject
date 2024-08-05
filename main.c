#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"



// 30~39번 입니다
#include "VOICE_COMMAND.c"
#include "MUTE_BUTTON.c"
#include "NAVIGATION.c"
#include "lock_strategy.c"
#include "rear_defrost_strategy.c"
#include "ParkingAssistance.c"
#include "Lane_Support.c"


void initializeFeatureHandlers();
void cleanupFeatureHandlers();

int main() {

    char input[10];
    int ignitionStarted = 0; 
    int selection;

    initializeObservers();
    initializeFeatureHandlers();

    //등록30~39
    registerHandler(MUTE_BUTTON, muteButtonHandler);//
    registerHandler(VOICE_COMMAND, Voice_Command_toggle);//
    registerHandler(PARKING_ASSIST, handleParkingAssistCommand);//
    registerHandler(REAR_DEFROST, handleDefrostCommand);//
    registerHandler(CHILD_LOCK, handleLockCommand);//
    registerHandler(NAVIGATION,navigatehandle);//
    registerHandler(LANE_ASSIST,handleLaneSupportCommand);//




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
                handlerEvent(REAR_DEFROST); // 서리제거
            }
            else if(selection ==31){
                handlerEvent(CHILD_LOCK); // 어린이 보호
            }
            else if(selection ==32) {
                handlerEvent(MUTE_BUTTON); // 음소거 기능
           }
            else if(selection ==33) {
                handlerEvent(VOICE_COMMAND); // 보이스 커맨드
            }
            else if(selection ==34) {

            }
            else if(selection ==35) {

            }
            else if(selection ==36) {
                handlerEvent(NAVIGATION); // 네비게이션
            }
            else if(selection ==37) {
                handlerEvent(LANE_ASSIST); // 차선 지원
            }
            else if(selection ==38) {
                handlerEvent(PARKING_ASSIST);//
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