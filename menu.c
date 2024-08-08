#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "sunroof.h"
#include "trunk.h"
#include "fuel.h"
#include "drive.h"
#include "traction.h"
#include "observer.h"
#include "steering.h"
#include "interior.h"
#include "pbrake.h"
#include "hseat.h"
#include "cseat.h"
#include "file.c"

#define MAX_NUM 5
#define ONE 1
#define TWO 2

void sunroofMenu() {
    int option, value;
    int values[MAX_NUM];
    sunroofControlFunction sc;

    printf("SUNROOF Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter sunroof state (0=Open, 1=Close, 2=Tilt): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("SUNROOF_CONTROL", values, ONE);

            // Set the sunroof control function
            if (value == 0) {
                sc = openSunroof;
            } else if (value == 1) {
                sc = closeSunroof;
            } else {
                sc = tiltSunroof;
            }

            // Execute the traction control function
            printf("****************************\n");
            sunroofControl(sc);
            registerHandler(SUNROOF_CONTROL, sc);
            // Notify the event
            handlerEvent(SUNROOF_CONTROL);
            unregisterHandler(SUNROOF_CONTROL, sc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("SUNROOF_CONTROL", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void trunkReleaseMenu() {
    int option, value;
    int values[MAX_NUM];
    trunkReleaseControlFunction tr;

    printf("TRUNK RELEASE Menu:\n");
    printf("1. Activate trunk release\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("TRUNK_RELEASE", values, ONE);
            // Register the handler
            printf("****************************\n");
            tr = activateTrunkRelease;
            registerHandler(TRUNK_RELEASE, tr);
            // Notify the event
            handlerEvent(TRUNK_RELEASE);
            unregisterHandler(TRUNK_RELEASE, tr);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("Trunk_RELEASE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void fuelCapReleaseMenu() {
    int option, value;
    int values[MAX_NUM];
    fuelCapReleaseControlFunction fr;

    printf("FUEL CAP RELEASE Menu:\n");
    printf("1. Activate fuel cap release\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("FUEL_CAP_RELEASE", values, ONE);
            // Register the handler
            printf("****************************\n");
            fr = activateFuelCapRelease;
            registerHandler(FUEL_CAP_RELEASE, fr);
            // Notify the event
            handlerEvent(FUEL_CAP_RELEASE);
            unregisterHandler(FUEL_CAP_RELEASE, fr);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("FUEL_CAP_RELEASE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void parkingBrakeMenu() {
    int option, value;
    int values[MAX_NUM];
    parkingBrakeControlFunction pc;

    printf("Parking Brake Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter brake state (0=Disengage, 1=Engage): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("PARKING_BRAKE", values, ONE);

            // Set the brake control function
            if (value == 0) {
                pc = disengageBrake;
            } else {
                pc = engageBrake;
            }

            // Execute the brake control function
            printf("****************************\n");
            parkingBrakeControl(pc);
            registerHandler(PARKING_BRAKE, pc);
            // Notify the event
            handlerEvent(PARKING_BRAKE);
            unregisterHandler(PARKING_BRAKE, pc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("PARKING_BRAKE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void driveModeMenu() {
    int option, value;
    int values[MAX_NUM];
    driveModeControlFunction dc;

    printf("Drive mode Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter drive mode (0=Eco, 1=Sports, 2=Normal): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("DRIVE_MODE", values, ONE);

            // Set the drive mode control function
            if (value == 0) {
                dc = ecoMode;
            } else if (value == 1) {
                dc = sportsMode;
            } else {
                dc = normalMode;
            }

            // Execute the drive mode function
            printf("****************************\n");
            driveModeControl(dc);
            registerHandler(DRIVE_MODE, dc);
            // Notify the event
            handlerEvent(DRIVE_MODE);
            unregisterHandler(DRIVE_MODE, dc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("DRIVE_MODE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void tractionMenu() {
    int option, value;
    int values[MAX_NUM];
    tractionControlFunction tc;

    printf("TRACTION Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter traction state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("TRACTION_CONTROL", values, ONE);

            // Set the traction control function
            if (value == 0) {
                tc = tractionOff;
            } else {
                tc = tractionOn;
            }

            // Execute the traction control function
            printf("****************************\n");
            tractionControl(tc);
            registerHandler(TRACTION_CONTROL, tc);
            // Notify the event
            handlerEvent(TRACTION_CONTROL);
            unregisterHandler(TRACTION_CONTROL, tc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("TRACTION_CONTROL",ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void heatedSeatMenu() {
    int option, seatId, heatLevel;
    int values[MAX_NUM];
    heatSeatControlFunction hc;
    HseatStatus status;

    printf("HEATED SEATS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
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

            // Set the heated seat status
            status.seatId = seatId;
            status.heatLevel = heatLevel;

            values[0] = seatId;
            values[1] = heatLevel;
            writeOrUpdateValueToFile("HEATED_SEATS", values, 2);
            
            // Use a wrapper to pass the changed value of the structure
            adjustHeatedSeat(status);
            printf("****************************\n");
            hc = heatedSeatHandlerWrapper;

            // register handler
            registerHandler(HEATED_SEATS, hc);

            // Notify the event
            handlerEvent(HEATED_SEATS);

            // Unregister the handler
            unregisterHandler(HEATED_SEATS, hc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("HEATED_SEATS",2);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void cooledSeatMenu() {
    int option, seatId, coolLevel;
    int values[MAX_NUM];
    coolSeatControlFunction cc;
    CseatStatus status;

    printf("COOLED SEATS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
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

            // Set the heated seat status
            status.seatId = seatId;
            status.coolLevel = coolLevel;

            values[0] = seatId;
            values[1] = coolLevel;
            writeOrUpdateValueToFile("COOLED_SEATS", values, 2);
            
            // Use a wrapper to pass the changed value of the structure
            adjustCooledSeat(status);
            printf("****************************\n");
            cc = cooledSeatHandlerWrapper;

            // register handler
            registerHandler(COOLED_SEATS, cc);

            // Notify the event
            handlerEvent(COOLED_SEATS);

            // Unregister the handler
            unregisterHandler(COOLED_SEATS, cc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("COOLED_SEATS",TWO);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void steeringMenu() {
    int option, value;
    int values[MAX_NUM];

    steeringControlFunction sc;

    printf("Steering Adjust Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter Steering Adjust (0=Up, 1=Down, 2=In, 3=Out): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2 && value != 3)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            values[0] = value;
            // Perform write operation to file if needed
            writeOrUpdateValueToFile("STEERING_ADJUST", values, ONE);

            // Set the steering control function
            if (value == 0) {
                sc = upSteering;
            } else if (value == 1) {
                sc = downSteering;
            } else if (value == 2) {
                sc = inSteering;
            } else {
                sc = outSteering;
            }

            // Execute the traction control function
            printf("****************************\n");
            steeringControl(sc);
            registerHandler(STEERING_ADJUST, sc);
            // Notify the event
            handlerEvent(STEERING_ADJUST);
            unregisterHandler(STEERING_ADJUST, sc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("STEERING_ADJUST", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }

}

void interiorLightMenu() {
    int option, value;
    int values[MAX_NUM];
    interiorLightControlFunction ic;

    printf("Interior Light Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter interior light state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            values[0] = value;
            writeOrUpdateValueToFile("INTERIOR_LIGHT", values, ONE);

            // Set the traction control function
            if (value == 0) {
                ic = offInteriorLight;
            } else {
                ic = onInteriorLight;
            }

            // Execute the interior light function
            printf("****************************\n");
            interiorLightControl(ic);
            registerHandler(INTERIOR_LIGHT, ic);
            // Notify the event
            handlerEvent(INTERIOR_LIGHT);
            unregisterHandler(INTERIOR_LIGHT, ic);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            printCurrentValues("INTERIOR_LIGHT", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}