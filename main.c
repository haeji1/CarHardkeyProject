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
#include "RadioSource.h"
#include "ClimateAirflow.h"
#include "ClimateFan.h"
#include "ClimateTemp.h"
#include "Defrost.h"
#include "DoorLock.h"
#include "MirrorAdjust.h"
#include "PowerWindows.h"
#include "WindowLock.h"
#include "SeatAdjust.h"
#include "lock_strategy.c"
#include "rear_defrost_strategy.c"
#include "MUTE_BUTTON.c"
#include "VOICE_COMMAND.c"
#include "NAVIGATION.c"
#include "Lane_Support.c"
#include "ParkingAssistance.c"
#include "auto_hold.h"
#include "fog_lights.h"
#include "seat_heater.h"
#include "seat_cooler.h"
#include "hands_free.h"
#include "trailer_control.h"
#include "hud_Adjust.h"
#include "glove_box_release.h"
#include "emergency_brake.h"


// void initializeFeatureHandlers();
// void cleanupFeatureHandlers();

int main() {
    char input[10];
    int ignitionStarted = 0; 
    int selection;

    //initializeObservers();
    // initializeFeatureHandlers();

    //등록30~39
    registerHandler(MUTE_BUTTON, muteButtonHandler);//
    registerHandler(VOICE_COMMAND,voiceCommandToggle);//
    registerHandler(PARKING_ASSIST, handleParkingAssistCommand);//
    registerHandler(REAR_DEFROST, handleDefrostCommand);//
    registerHandler(CHILD_LOCK, handleLockCommand);//
    registerHandler(NAVIGATION,navigatehandle);//
    registerHandler(LANE_ASSIST,handleLaneSupportCommand);//


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
                hornMenu();
            } else if (selection == 2) {
                headlightsMenu();
            } else if (selection == 3) {
                turnSignalsMenu();
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
            } else if (selection == 10) {
                radioSourceMenu();
			} else if (selection == 11) {
				ClimateTempMenu();
			} else if (selection == 12) {
				climateFanMenu();
			} else if (selection == 13) {
                climateAirflowMenu();
			} else if (selection == 14) {
                DefrostMenu();
			} else if (selection == 15) {
                powerwindowMenu();
			} else if (selection == 16) {
                WindowLockMenu();
            } else if (selection == 17) {
                DoorLockMenu();
            } else if (selection == 18){
                mirrorAdjustMenu();
            } else if (selection == 19){
                seatAdjustMenu();
            } else if (selection == 20) {
                sunroofMenu();
            } else if (selection == 21) {
                trunkReleaseMenu();
            } else if(selection == 22) {
                fuelCapReleaseMenu();
            } else if (selection == 23) {
                parkingBrakeMenu();
            }  else if (selection == 24) {
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
            } else if(selection ==30) {
                handlerEvent(REAR_DEFROST); // 서리제거
            } else if(selection ==31){
                handlerEvent(CHILD_LOCK); // 어린이 보호
            } else if(selection ==32) {
                handlerEvent(MUTE_BUTTON); // 음소거 기능
           } else if(selection ==33) {
                handlerEvent(VOICE_COMMAND); // 음소거 기능
            } else if(selection ==34) {

            } else if(selection ==35) {

            } else if(selection ==36) {
                handlerEvent(NAVIGATION); // 네비게이션
            } else if(selection ==37) {
               handlerEvent(LANE_ASSIST); // 차선 지원
            } else if(selection ==38) {
                handlerEvent(PARKING_ASSIST);// 주차 보조
            } else if(selection ==39) {

			} else if(selection ==40) {
				hudAdjustMenu();
			} else if(selection ==41) {
				gloveBoxReleaseMenu();
            } else if(selection ==42) {
				fogLightsMenu();
			}  else if(selection ==43) {
				emergencyBrakeMenu();
			} else if(selection == 44) {
                trailerControlMenu();
            } else if(selection == 45) {
                autoHoldMenu();
            } else if(selection == 46) {
                handsFreeMenu();
			} else if(selection == 47) {
                seatHeaterMenu();
			} else if(selection == 48) {
                seatCoolerMenu();
            } else if(selection == 50) {
                break;
            } else {
                printf("Invalid selection. Please try again.\n");
            }
        }
    }

    return 0;
}