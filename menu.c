#include <stdio.h>
#include "menu.h"
#include "observer.h"
#include "hud_adjust.h"
#include "glove_box_release.h"
#include "fog_lights.h"
#include "emergency_brake.h"
#include "trailer_control.h"
#include "auto_hold.h"
#include "hands_free.h"
// #include "seat_heater.h"
// #include "seat_cooler.h"




void autoHoldMenu() {
    
    int option, value;
    autoHoldFunction af;

    printf(" Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter autoHold state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 && (value != 0)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            if (value == 0) {
                af = autoHoldOff;
            } else {
                af = autoHoldOn;
            } 

            

            setAutoHold(af);
            registerHandler(AUTO_HOLD, af);
            handlerEvent(AUTO_HOLD);
            unregisterHandler(AUTO_HOLD, af);
            break;

        case 2:
            printf("Listening to events...\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    
    }
}

void hudAdjustMenu(){
    int option, value;
    HUDAdjustFunction haf;

    printf("Hud Adjust Menu: \n");
    printf("1. Activate Hud Adjust release\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;
    }
    
    switch (option) {
        case 1:

            haf = adjustHUDSettings;
            registerHandler(HUD_ADJUST, haf);
            handlerEvent(HUD_ADJUST);
            unregisterHandler(HUD_ADJUST, haf);
            break;

        case 2:
            printf("Listening to events...\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }
void gloveBoxReleaseMenu(){
    int option, value;
    GloveBoxReleaseFunction gbr;

    printf("Glove Box Release Menu: \n");
    printf("1. Open The Glove Box Latch \n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:

            gbr = releaseGloveBox;
            registerHandler(GLOVE_BOX_RELEASE, gbr);
            handlerEvent(GLOVE_BOX_RELEASE);
            unregisterHandler(GLOVE_BOX_RELEASE, gbr);
            break;

        case 2:
            printf("Listening to events...\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }
void fogLightsMenu(){
    int option, value;
    fogLightFunction flf;

    printf("Ac: \n");
    printf("1. Fog Light mode\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }
    
    switch (option) {
        case 1:
            printf("Enter Fog Light State (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 && (value != 0)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            if (value == 0) {
                flf = fogLightsOff;
            } else {
                flf = fogLightsOn;
            } 

            setFogLights(flf);
            registerHandler(FOG_LIGHTS, flf);
            handlerEvent(FOG_LIGHTS);
            unregisterHandler(FOG_LIGHTS, flf);
            break;

        case 2:
            printf("Listening to events...\n");      
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}
void emergencyBrakeMenu(){
    int option, value;
    emergencyBrakeFunction ebf;

    printf("Emergency Brake Menu: \n");
    printf("1. Enter '1' to Emergency Brake\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:

            ebf = activateEmergencyBrake;
            registerHandler(EMERGENCY_BRAKE, ebf);
            handlerEvent(EMERGENCY_BRAKE);
            unregisterHandler(EMERGENCY_BRAKE, ebf);
            break;

        case 2:
            printf("Listening to events...\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }
void trailerControlMenu(){
    int option, value;
    trailerControlFunction tcf;

    printf("Trailer Control Menu: \n");
    printf("1. Activate Trailer Control\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:

            tcf = setTrailerControl;
            registerHandler(TRAILER_CONTROL, tcf);
            handlerEvent(TRAILER_CONTROL);
            unregisterHandler(TRAILER_CONTROL, tcf);
            break;

        case 2:
            printf("Listening to events...\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

void handsFreeMenu(){
    int option, value;
    handsFreeFunction hff;

    printf("Hands Free Menu: \n");
    printf("1. Enter '1' to Hands Free mode \n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:

            hff = activateHandsFree;
            registerHandler(HANDS_FREE, hff);
            handlerEvent(HANDS_FREE);
            unregisterHandler(HANDS_FREE, hff);
            break;

        case 2:
            printf("Listening to events...\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

// typedef void (*Handler)();

// void seatHeaterMenu() {
//     int option, seatId, heatLevel;

//     printf("Seat Heater Menu:\n");
//     printf("1. Set seat heater state\n");
//     printf("2. Listen to events\n");
//     printf("Enter your choice: ");
//     if (scanf("%d", &option) != 1) {
//         printf("Invalid input. Returning to menu.\n");
//         return;
//     }

//     switch (option) {
//         case 1:
//             printf("Enter seat identifier (0 = Driver, 1 = Passenger): ");
//             if (scanf("%d", &seatId) != 1 || (seatId != 0 && seatId != 1)) {
//                 printf("Invalid seat identifier. Enter 0 or 1.\n");
//                 return;
//             }
//             printf("Enter heat level (0-3): ");
//             if (scanf("%d", &heatLevel) != 1 || (heatLevel < 0 || heatLevel > 3)) {
//                 printf("Invalid heat level. Enter a value between 0 and 3.\n");
//                 return;
//             }

//             // Set the seat heater
//             setSeatHeater(seatId, heatLevel);

//             // Register, handle, and unregister events
//             registerHandler(SEAT_HEATER, seatHeaterHandler);
//             handlerEvent(SEAT_HEATER);
//             unregisterHandler(SEAT_HEATER, seatHeaterHandler);
//             break;

//         case 2:
//             printf("Listening to events...\n");
//             break;

//         default:
//             printf("Invalid choice. Returning to menu.\n");
//             break;
//     }
// }


















        








    