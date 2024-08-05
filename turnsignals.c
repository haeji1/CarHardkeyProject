#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "turnsignals.h"

static int turnsignalsState = 0; 

void leftTurn();
void rightTurn();

void handleTurnSignals(void) {

    int opt;
    printf(" == TURN_SIGNALS options == \n");
    printf("1. Left \n");
    printf("2. Right \n");
    printf("3. EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
        leftTurn();
    }else if(opt == 2){
        rightTurn();
    }else if(opt == 3){
        exit(EXIT_FAILURE);
    }else{
        printf("Unknown TURN_SIGNALS command.\n");
    }

}

void leftTurn(){
    if (turnsignalsState == 1) {
        printf("Turn signal is already LEFT.\n");
    } else {
        turnsignalsState = 1;
        printf("Turn signal turned LEFT.\n");
    }
}

void rightTurn(){
    if (turnsignalsState == 2) {
        printf("Turn signal is already RIGHT.\n");
    } else {
        turnsignalsState = 2;
        printf("Turn signal turned RIGHT.\n");
    }
}

void initializeTurnSignalsHandlers() {
    registerHandler(TURN_SIGNALS, handleTurnSignals);
}