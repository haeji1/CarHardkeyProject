#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observer.h"
#include "display.h"
#include "ignition.h"
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
#include "auto_hold.h"
#include "fog_lights.h"
#include "seat_heater.h"
#include "seat_cooler.h"
#include "hands_free.h"
#include "trailer_control.h"
#include "hud_Adjust.h"
#include "glove_box_release.h"
#include "emergency_brake.h"
#include "file.c"

int main() {
    char input[10];
    int ignitionStarted = 0; 
    int selection;

    ignitionStarted = 0;

    while (1) {
        if(ignitionStarted != 1){
            ignitionMenu();
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
                windshieldWipersMenu();
            } else if (selection == 5) {
                hazardLightsMenu();
            } else if (selection == 6) {
                cruiseControlMenu();
            } else if (selection == 7) {
                //handleRadioVolumeCommands();
            } else if (selection == 8) {
                //handleRadioTuningCommands();
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
                REAR_DEFROST_MENU(); // 후면 서리 제거
            } else if(selection ==31){
                CHILD_LOCK_MENU(); // 어린이 보호
            } else if(selection ==32) {
                MUTE_BUTTON_MENU(); // 음소거 기능
            } else if(selection ==33) {
                VOICE_COMMAND_MENU(); // 보이스 커맨드 기능
            } else if(selection ==34) {
                Phone_Answer_MENU(); // 됬네 전화끊기
            } else if(selection ==35) {
                Phone_End_Call_MENU();//전화걸기!
            } else if(selection ==36) {
                NAVIGATION_MENU(); // 네비게이션
            } else if(selection ==37) {
                LANE_ASSIST_MENU(); //차선 보조
            } else if(selection ==38) {
                PARKING_ASSIST_MENU();// 주차 보조
            } else if(selection ==39) { // HILL
                HILL_DESCENT_MENU(); // 아직 안함
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
            } else if(selection == 49) {
                break;
            } else {
                printf("Invalid selection. Please try again.\n");
            }
        }
    }

    return 0;
}