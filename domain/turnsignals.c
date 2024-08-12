#include <stdio.h>
#include "turnsignals.h"

/*
    0 : left
    1 : right
*/

void leftTurnSignal(){
    printf("Turn signal turned LEFT.\n");
}

void rightTurnSignal(){
    printf("Turn signal turned RIGHT.\n");
}

void turnSignalsControl(turnSignalsControlFunction tc){
    printf("status changed by function\n");
}