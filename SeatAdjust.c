//
// Created by MinseokK on 24. 8. 7.
//
// SEAT_ADJUST
// 0   // Seat identifier (0 = Driver, 1 = Passenger)
// 1   // Adjustment type (0 = Position, 1 = Recline, 2 = Lumbar)
// 3   // Adjustment value
#include "SeatAdjust.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>

static int SeatIdentifierState = 0;
static int AdjustmentTypeState = 1;
static int AdjustmentValueState = 3;
static int opt;


void AdjustmentValue(){
    printf("=== AdjustMnet Value ===\n");
    printf("=== Currently Type : %d ===\n", AdjustmentValueState);
    printf("0 \n");
    printf("1 \n");
    printf("2 \n");
    int op3;
    scanf("%d", &op3);

    if(op3 == 1){
        AdjustmentValueState = 1;
        printf("Change AdjustmentValue : %d\n",AdjustmentValueState);
    } else if(op3 == 2){
        AdjustmentValueState = 2;
        printf("Change AdjustmentValue : %d\n",AdjustmentValueState);
    } else if(op3 == 3){
        AdjustmentValueState = 3;
        printf("Change AdjustmentValue : %d\n",AdjustmentValueState);
    }

}

void AdjustmentPosition(){
    AdjustmentTypeState = 0;
    printf("Position mode State : %d \n", AdjustmentTypeState);
    AdjustmentValue();

}
void AdjustmentRecline(){
    AdjustmentTypeState = 1;
    printf("Recline mode State : %d \n", AdjustmentTypeState);
    AdjustmentValue();


}
void AdjustmentLumbar(){
    AdjustmentTypeState = 2;
    printf("Lumbar mode State : %d \n", AdjustmentTypeState);
    AdjustmentValue();

}

void AdjustType(){
    printf("=== AdjustType ===\n");
    printf("=== Currently Type : %d ===\n", AdjustmentTypeState);
    printf("0. Position \n");
    printf("1. Recline \n");
    printf("2. Lumbar \n");

    int op;
    scanf("%d", &op);

    if(op == 0){
        AdjustmentPosition();

    } else if(op == 1){
        AdjustmentRecline();


    } else if(op == 2){
        AdjustmentLumbar();
    }


}


void DriverSeat(){
    SeatIdentifierState = 0;
    printf("DriverSeat mode State : %d \n", SeatIdentifierState);
    AdjustType();

}
void PassengerSeat(){
    SeatIdentifierState = 1;
    printf("PassengerSeat mode State : %d \n", SeatIdentifierState);
    AdjustType();
}





void handleSeatAdjust(handleSeatAdjustControlFunction *sac){

    printf("Currently Seat State Seat mode : %d \n",SeatIdentifierState);
    printf("Currently Seat State AdjustmentTypeState : %d \n",AdjustmentTypeState);
    printf("Currently Seat State AdjustmentValueState : %d \n",AdjustmentValueState);
    printf(" == SeatAdjust options == \n");
    printf("0. DriverSeat \n");
    printf("1. PassengerSeat \n");
    printf("2. exit \n");

    scanf("%d", &opt);


    if (opt == 0) {
        *sac = DriverSeat;
    } else if (opt == 1) {
        *sac = PassengerSeat;
    } else if (opt == 2) {
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown SeatAdjust command.\n");
    }

}