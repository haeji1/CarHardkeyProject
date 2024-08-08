#include "menuw.h"
#include <stdio.h>
#include "observer.h"

//30~39
#include "lock_strategy.c"
#include "rear_defrost_strategy.c"
#include "MUTE_BUTTON.c"
#include "VOICE_COMMAND.c"
#include "NAVIGATION.c"
#include "Lane_Support.c"
#include "ParkingAssistance.c"
#include "end_call.c"
#include "answer_call.c"
#include "HILL_DESCENT.c"

#define MAX_NUM 5
#define ONE 1
#define TWO 2



void MUTE_BUTTON_MENU(){
    int option, value;
    int values[MAX_NUM];

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

        registerHandler(MUTE_BUTTON, muteButtonHandler);
        handlerEvent(MUTE_BUTTON);3
        unregisterHandler(MUTE_BUTTON, muteButtonHandler);
        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("MUTE_BUTTON", 1);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}

void VOICE_COMMAND_MENU(){

    printf("Steering Adjust Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    int option, value;
    int values[MAX_NUM];

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }


    switch (option) {
        case 1:
        registerHandler(VOICE_COMMAND, voiceCommandToggle);
        handlerEvent(VOICE_COMMAND);
        unregisterHandler(VOICE_COMMAND, voiceCommandToggle);

        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("VOICE_COMMAND", 1);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void PARKING_ASSIST_MENU(){

    printf("Steering Adjust Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    int option, value;
    int values[MAX_NUM];

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter PARKING_ASSIST (0=ON, 1=OFF): ");

        registerHandler(PARKING_ASSIST, handleParkingAssistCommand);
        handlerEvent(PARKING_ASSIST);
        unregisterHandler(PARKING_ASSIST, handleParkingAssistCommand);

        break;

        case 2:
            printf("Listening to events...\n");
			printCurrentValues("PARKING_ASSIST", 1);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void REAR_DEFROST_MENU(){
    int option, value;
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
        registerHandler(REAR_DEFROST, handleDefrostCommand);
        handlerEvent(REAR_DEFROST);
        unregisterHandler(REAR_DEFROST, handleDefrostCommand);
        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("REAR_DEFROST", 1);
			sleep(3);

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void CHILD_LOCK_MENU(){


    int option, value;
    int values[MAX_NUM];

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
        registerHandler(CHILD_LOCK, childFunction);
        handlerEvent(CHILD_LOCK);
        unregisterHandler(CHILD_LOCK, childFunction);
        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("CHILD_LOCK", 1);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void NAVIGATION_MENU(){

    int option, value;
    int values[MAX_NUM];

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
        registerHandler(NAVIGATION, navigatehandle);
        handlerEvent(NAVIGATION);
        unregisterHandler(NAVIGATION, navigatehandle);
        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("NAVIGATION", 2);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void LANE_ASSIST_MENU(){

    int option, value;
    int values[MAX_NUM];

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

        registerHandler(LANE_ASSIST, handleLaneSupportCommand);
        handlerEvent(LANE_ASSIST);
        unregisterHandler(LANE_ASSIST, handleLaneSupportCommand);

        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("LANE_ASSIST", 1);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            printCurrentValues("LANE_ASSIST", 1);
        break;
    }

}

void Phone_End_Call_MENU(){ //34
    int option, value;
    int values[MAX_NUM];

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
        registerHandler(PHONE_ANSWER,answerPhone);
        handlerEvent(PHONE_ANSWER);
        unregisterHandler(PHONE_ANSWER,answerPhone);
        break;

        case 2:
         printf("Listening to events...\n");
         printCurrentValues("PHONE_ANSWER", 1);
		 sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}

void Phone_Answer_MENU(){
    int option, value;
    int values[MAX_NUM];

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

        registerHandler(PHONE_END_CALL,endCall);
        handlerEvent(PHONE_END_CALL);
        unregisterHandler(PHONE_END_CALL,endCall);

        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("PHONE_END_CALL", 1);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}

void HILL_DESCENT_MENU(){
    int option, value;
    int values[MAX_NUM];

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

        registerHandler(HILL_DESCENT,handleHillDescentCommand);
        handlerEvent(HILL_DESCENT);
        unregisterHandler(HILL_DESCENT,handleHillDescentCommand);
        break;

        case 2:
            printf("Listening to events...\n");
            printCurrentValues("HILL_DESCENT", 1);
			sleep(3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}