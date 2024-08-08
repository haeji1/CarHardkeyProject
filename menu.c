#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "observer.h"
#include "hud_adjust.h"
#include "glove_box_release.h"
#include "fog_lights.h"
#include "emergency_brake.h"
#include "trailer_control.h"
#include "auto_hold.h"
#include "hands_free.h"
#include "seat_heater.h"
#include "seat_cooler.h"
#include "file.c"

#define MAX_NUM 5

void autoHoldMenu(){
    int values[MAX_NUM];
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
            printf("Enter Auto Hold state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 && (value != 0)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }



            values[0] = value;
            writeOrUpdateValueToFile("AUTO_HOLD", values, 1);
            
            if (value == 0) {
                af = autoHoldOff;
            } else {
                af = autoHoldOn;
            } 
            setAutoHold(af);
            registerHandler(AUTO_HOLD, af);
            handlerEvent(AUTO_HOLD);
            unregisterHandler(AUTO_HOLD, af);
            printf("****************************************\n");
            break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("AUTO_HOLD", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    
    }
}

void hudAdjustMenu(){
    int option, value;
    int values[MAX_NUM];
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
            values[0] = 1;
            writeOrUpdateValueToFile("HUD_ADJUST", values, 1);
            printf("****************************************\n");
            
            haf = adjustHUDSettings;
            registerHandler(HUD_ADJUST, haf);
            handlerEvent(HUD_ADJUST);
            unregisterHandler(HUD_ADJUST, haf);
            printf("****************************************\n");
            break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("HUD_ADJUST", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

void gloveBoxReleaseMenu(){
    int option, value;
    int values[MAX_NUM];
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
            values[0] = 1;
            writeOrUpdateValueToFile("GLOVE_BOX_RELEASE", values, 1);
            printf("****************************************\n");
            
            gbr = releaseGloveBox;
            registerHandler(GLOVE_BOX_RELEASE, gbr);
            handlerEvent(GLOVE_BOX_RELEASE);
            unregisterHandler(GLOVE_BOX_RELEASE, gbr);
            printf("****************************************\n");
            break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("GLOVE_BOX_RELEASE", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

void fogLightsMenu(){
    int option, value;
    int values[MAX_NUM];
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

            values[0] = value;
            writeOrUpdateValueToFile("FOG_LIGHTS", values, 1);
            
            if (value == 0) {
                flf = fogLightsOff;
            } else {
                flf = fogLightsOn;
            } 

            setFogLights(flf);
            registerHandler(FOG_LIGHTS, flf);
            handlerEvent(FOG_LIGHTS);
            unregisterHandler(FOG_LIGHTS, flf);
            printf("****************************************\n");
            break;

        case 2:
            printf("Listening to events...\n");      
            printCurrentValues("FOG_LIGHTS", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void emergencyBrakeMenu(){
    int option, value;
    int values[MAX_NUM];
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
            values[0] = 1;
            writeOrUpdateValueToFile("EMERGENCY_BRAKE", values, 1);
            printf("****************************************\n");

            ebf = activateEmergencyBrake;
            registerHandler(EMERGENCY_BRAKE, ebf);
            handlerEvent(EMERGENCY_BRAKE);
            unregisterHandler(EMERGENCY_BRAKE, ebf);
            break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("EMERGENCY_BRAKE", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

void trailerControlMenu(){
    int option, value;
    int values[MAX_NUM];
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
            values[0] = 1;
            writeOrUpdateValueToFile("TRAILER_CONTROL", values, 1);
            printf("****************************************\n");

            tcf = controlTrailer;
            registerHandler(TRAILER_CONTROL, tcf);
            handlerEvent(TRAILER_CONTROL);
            unregisterHandler(TRAILER_CONTROL, tcf);
            break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("TRAILER_CONTROL", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

void handsFreeMenu(){
    int option, value;
    int values[MAX_NUM];
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
            values[0] = 1;
            writeOrUpdateValueToFile("HANDS_FREE", values, 1);
            printf("****************************************\n");
            
            hff = activateHandsFree;
            registerHandler(HANDS_FREE, hff);
            handlerEvent(HANDS_FREE);
            unregisterHandler(HANDS_FREE, hff);
            printf("****************************************\n");
            break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("HANDS_FREE", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

void seatHeaterMenu() {
    int option, seatId, heatLevel;
    int values[2];
    seatHeaterFunction shf;
    seatHeaterConfig config;

    printf("Seat Heater Menu:\n");
    printf("1. Set and Save Seat Heater Configuration\n");
    printf("2. Listen to Events\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    switch (option) {
        case 1:
            // Collect input for seat configuration
            printf("Enter seat identifier (0 = Driver, 1 = Passenger): ");
            if (scanf("%d", &seatId) != 1 || (seatId < 0 || seatId > 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            printf("Enter heat level (0-3): ");
            if (scanf("%d", &heatLevel) != 1 || (heatLevel < 0 || heatLevel > 3)) {
                printf("Invalid input. Enter a value between 0 and 3.\n");
                return;
            }

            // Set the seat heater configuration
            config.seatId = seatId;
            config.heatLevel = heatLevel;

            values[0] = seatId;
            values[1] = heatLevel;
            writeOrUpdateValueToFile("SEAT_HEATER", values, 2);
            
            // Choose the function pointer based on seat identifier
            if (seatId == 0) {
                shf = seatIdentifierDriver;
            } else {
                shf = seatIdentifierPassenger;
            }

            // Apply the seat heater configuration
            setSeatHeater(shf, &config);
            
            // Register event handler
            registerHandler(SEAT_HEATER, seatHeaterHandlerWrapper);

            // Notify the event
            handlerEvent(SEAT_HEATER);

            // Unregister the handler
            unregisterHandler(SEAT_HEATER, seatHeaterHandlerWrapper);

            printf("****************************************\n");
            break;

        case 2:
            printf("\n********** Listening to Events **********\n");
            // Print the current seat heater configuration from the file
            printCurrentValues("SEAT_HEATER", 2);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void seatCoolerMenu() {
    int option, seatId, coolLevel;
    int values[2];
    seatCoolerFunction scf;
    seatCoolerConfig config;

    printf("Seat Cooler Menu:\n");
    printf("1. Set and Save Seat Cooler Configuration\n");
    printf("2. Listen to Events\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    switch (option) {
        case 1:
            // Collect input for seat cooler configuration
            printf("Enter seat identifier (0 = Driver, 1 = Passenger): ");
            if (scanf("%d", &seatId) != 1 || (seatId < 0 || seatId > 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            printf("Enter cool level (0-3): ");
            if (scanf("%d", &coolLevel) != 1 || (coolLevel < 0 || coolLevel > 3)) {
                printf("Invalid input. Enter a value between 0 and 3.\n");
                return;
            }

            // Set the seat cooler configuration
            config.seatId = seatId;
            config.coolLevel = coolLevel;

            values[0] = seatId;
            values[1] = coolLevel;
            writeOrUpdateValueToFile("SEAT_COOLER", values, 2);
            
            // Choose the function pointer based on seat identifier
            if (seatId == 0) {
                scf = seatIdentifierDriverCooler;
            } else {
                scf = seatIdentifierPassengerCooler;
            }

            // Apply the seat cooler configuration
            setSeatCooler(scf, &config);
            
            // Register event handler
            registerHandler(SEAT_COOLER, seatCoolerHandlerWrapper);

            // Notify the event
            handlerEvent(SEAT_COOLER);

            // Unregister the handler
            unregisterHandler(SEAT_COOLER, seatCoolerHandlerWrapper);

            printf("****************************************\n");
            break;

        case 2:
            printf("********** Listening to Events **********\n");
            // Print the current seat cooler configuration from the file
            printCurrentValues("SEAT_COOLER", 2);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

