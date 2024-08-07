//
// Created by MinseokK on 24. 8. 3.
//
// 1   // Defrost state (0 = Off, 1 = On)

#include "Defrost.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>
static int deforstState = 1;

void WindshieldDefrostON(){
    deforstState = 1;
    printf("Defrost_ON\n");
}
void WindshieldDefrostOFF(){
    deforstState = 0;
    printf("Defrost_OFF\n");
}


void handleDefrost(DefrostControlFunction *dfc){
    printf("Currently deforstState : %d \n",deforstState);
    printf(" == WindshieldDefrostControl options == \n");
    printf("0. Defrost_OFF \n");
    printf("1. Defrost_ON \n");
    printf("2. exit \n");

    int opt;

    scanf("%d", &opt);


    if (opt == 0) {
        *dfc = WindshieldDefrostOFF;
    } else if (opt == 1) {
        *dfc = WindshieldDefrostON;
    } else if (opt == 2) {
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown WindshieldDefrostControl command.\n");
    }


}

