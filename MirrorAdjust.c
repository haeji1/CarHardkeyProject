//
// Created by MinseokK on 24. 8. 5.
//
//MIRROR_ADJUST
// 0   // Mirror identifier (0 = Left, 1 = Right)
// 1   // Adjustment direction (0 = Up, 1 = Down, 2 = Left, 3 = Right)
#include "MirrorAdjust.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>

static int MirrorIdentifierState = 0;
static int  AdjustmentDirectionState = 1;
static int opt;


void AdjustDirection(int input){
    MirrorIdentifierState = input;
    if (MirrorIdentifierState == 0){
        printf("MirrorIdentifierLeft mode\n");
        printf("0 : UP\n");
        printf("1 : Down\n");
        printf("2 : Left\n");
        printf("3 : Rigt\n");

        scanf("%d", &opt);

        if (opt == 0){
            printf("UP\n");
            AdjustmentDirectionState = 0;

        }
        else if(opt == 1){
            printf("Down\n");
            AdjustmentDirectionState = 1;

        } else if(opt == 2){
            printf("Left\n");
            AdjustmentDirectionState = 2;

        } else if (opt == 3){
            printf("Right\n");
            AdjustmentDirectionState = 3;
        }
    }else if(MirrorIdentifierState == 1){
        printf("MirrorIdentifierRight mode\n");
        printf("0 : UP\n");
        printf("1 : Down\n");
        printf("2 : Left\n");
        printf("3 : Rigt\n");

        scanf("%d", &opt);

        if (opt == 0){
            printf("UP\n");
            AdjustmentDirectionState = 0;
        }
        else if(opt == 1){
            printf("Down\n");
            AdjustmentDirectionState = 1;

        } else if(opt == 2){
            printf("Left\n");
            AdjustmentDirectionState = 2;

        } else if (opt == 3){
            printf("Right\n");
            AdjustmentDirectionState = 3;
        }

    }
}
void MirrorIdentifierLeft(int input){
    AdjustDirection(opt);
}
void MirrorIdentifierRight(int input){
    AdjustDirection(opt);
}

void handleMirrorAdjust(MirrorAdjustControlFunction *ma){
    printf("Currently MirrorIdentifierState : %d \n",MirrorIdentifierState);
    printf("Currently AdjustmentDirectionState : %d \n",AdjustmentDirectionState);

    printf(" == PowerWindows options == \n");
    printf("0. MirrorIdentifierLeft \n");
    printf("1. MirrorIdentifierRight \n");
    printf("2. exit \n");

    scanf("%d", &opt);


    if (opt == 0) {
        *ma = MirrorIdentifierLeft;
    } else if (opt == 1) {
        *ma = MirrorIdentifierRight;
    } else if (opt == 3){
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown handleMirrorAdjust command.\n");
    }
}

