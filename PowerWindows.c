//
// Created by MinseokK on 24. 8. 3.
//
// POWER_WINDOWS
//0   // Window identifier (0 = FrontLeft, 1 = FrontRight, 2 = RearLeft, 3 = RearRight)
//1   // Action (0 = Up, 1 = Down)
#include <stdio.h>
#include "observer.h"
#include "PowerWindows.h"
#include <stdlib.h>
#include <unistd.h>


static int WindowIdentifierState = 0;
static int Action = 1;
int opt;

// 창 식별자
void ControlWindow(int input){
    WindowIdentifierState = input;
    if (WindowIdentifierState==0){
        WindowIdentifierState = 0;
        printf("you choose WindowFrontLeft\n");
        sleep(3);
        printf("0 : UP\n");
        printf("1 : Down\n");
        scanf("%d", &opt);

        if (opt == 1){
            printf("Down\n");
            Action = 1;
        }
        else{
            printf("UP\n");
            Action = 0;
        }

    }
    else if(WindowIdentifierState==1){
        WindowIdentifierState = 1;
        printf("you choose WindowFrontRight\n");
        sleep(3);
        printf("0 : UP\n");
        printf("1 : Down\n");
        scanf("%d", &opt);

        if (opt == 1){
            printf("Down\n");
            Action = 1;
        }
        else{
            printf("UP\n");
            Action = 0;
        }
    } else if(WindowIdentifierState == 2){
        WindowIdentifierState = 2;
        printf("you choose WindowRearLeft\n");
        sleep(3);
        printf("0 : UP\n");
        printf("1 : Down\n");
        scanf("%d", &opt);

        if (opt == 1){
            printf("Down\n");
            Action = 1;
        }
        else{
            printf("UP\n");
            Action = 0;
        }
    } else if(WindowIdentifierState == 3){
        WindowIdentifierState = 3;
        printf("you choose WindowRearRight\n");
        sleep(3);
        printf("0 : UP\n");
        printf("1 : Down\n");

        scanf("%d", &opt);

        if (opt == 1){
            printf("Down\n");
            Action = 1;
        }
        else{
            printf("UP\n");
            Action = 0;
        }
    }
    sleep(3);
}

void WindowFrontLeft(int input){
    ControlWindow(opt);
}
void WindowFrontRight(int input){
    ControlWindow(opt);

}
void WindowRearLeft(int input){
    ControlWindow(opt);
}
void WindowRearRight(int input){
    ControlWindow(opt);
}

//up down



void handlePowerWindows(handlePowerWindowsControlFunction *pwcf){
    printf("Currently WindowIdentifierState : %d \n",WindowIdentifierState);
    printf("Currently Action : %d \n",Action);

    printf(" == PowerWindows options == \n");
    printf("0. WindowFrontLeft \n");
    printf("1. WindowFrontRight \n");
    printf("2. WindowRearLeft \n");
    printf("3. WindowRearRight \n");
    printf("4. exit \n");

    scanf("%d", &opt);


    if (opt == 0) {
        *pwcf = WindowFrontLeft;
    } else if (opt == 1) {
        *pwcf = WindowFrontRight;
    } else if (opt == 2) {
        *pwcf = WindowRearLeft;
    } else if (opt == 3){
        *pwcf = WindowRearRight;
    } else if (opt == 4) {
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown PowerWindows command.\n");
    }

}

