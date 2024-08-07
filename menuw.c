#include "menuw.h"
#include <stdio.h>
#include "observer.h"

//30~39
#include "MUTE_BUTTON.c"
#include "lock_strategy.c"
#include "rear_defrost_strategy.c"
#include "VOICE_COMMAND.c"
#include "NAVIGATION.c"
#include "Lane_Support.c"
#include "ParkingAssistance.c"

void MUTE_BUTTON_MENU(){
    int option, value;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

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
            printf("Enter MUTE_BUTTON (0=ON, 1=OFF: ");

        registerHandler(MUTE_BUTTON, muteButtonHandler);
        handlerEvent(MUTE_BUTTON);
        unregisterHandler(MUTE_BUTTON, muteButtonHandler);

        break;

        case 2:
            printf("Listening to events...\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}

void VOICE_COMMAND_MENU(){


    int option, value;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

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
            printf("Enter VOICE_COMMAND (0=ON, 1=OFF): ");

        registerHandler(VOICE_COMMAND, voiceCommandToggle);
        handlerEvent(VOICE_COMMAND);
        unregisterHandler(VOICE_COMMAND, voiceCommandToggle);

        break;

        case 2:
            printf("Listening to events...\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void PARKING_ASSIST_MENU(){


    int option, value;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

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
            printf("Enter VOICE_COMMAND (0=ON, 1=OFF): ");

        registerHandler(PARKING_ASSIST, handleParkingAssistCommand);
        handlerEvent(PARKING_ASSIST);
        unregisterHandler(PARKING_ASSIST, handleParkingAssistCommand);

        break;

        case 2:
            printf("Listening to events...\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void REAR_DEFROST_MENU(){


    int option, value;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

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
            printf("Enter VOICE_COMMAND (0=ON, 1=OFF): ");

        registerHandler(REAR_DEFROST, handleDefrostCommand);
        handlerEvent(REAR_DEFROST);
        unregisterHandler(REAR_DEFROST, handleDefrostCommand);

        break;

        case 2:
            printf("Listening to events...\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void CHILD_LOCK_MENU(){


    int option, value;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

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
            printf("Enter VOICE_COMMAND (0=ON, 1=OFF): ");

        registerHandler(CHILD_LOCK, handleLockCommand);
        handlerEvent(CHILD_LOCK);
        unregisterHandler(CHILD_LOCK, handleLockCommand);

        break;

        case 2:
            printf("Listening to events...\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void NAVIGATION_MENU(){


    int option, value;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

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
            printf("Enter VOICE_COMMAND (0=ON, 1=OFF): ");

        registerHandler(NAVIGATION, navigatehandle);
        handlerEvent(NAVIGATION);
        unregisterHandler(NAVIGATION, navigatehandle);

        break;

        case 2:
            printf("Listening to events...\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void LANE_ASSIST_MENU(){


    int option, value;
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

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
            printf("Enter VOICE_COMMAND (0=ON, 1=OFF): ");

        registerHandler(LANE_ASSIST, handleLaneSupportCommand);
        handlerEvent(LANE_ASSIST);
        unregisterHandler(LANE_ASSIST, handleLaneSupportCommand);

        break;

        case 2:
            printf("Listening to events...\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}