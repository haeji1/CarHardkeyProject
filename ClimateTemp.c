//
// Created by MinseokK on 24. 8. 2.
//
#include <stdio.h>
#include "observer.h"
#include "ClimateTemp.h"
#include <unistd.h>

static int ClimateTempState = 22;

void setTemp(){
    int input;
    printf("Ajust Temp:");
    scanf("%d", &input);
    if (ClimateTempState == 22){
        ClimateTempState = input;
        printf("setting %d degree\n", ClimateTempState);
    }
}

void handleClimateTemp(ClimateTempControlFunction *ct){
    int inputTemp;
    printf("Currently Temp : %d\n", ClimateTempState);
    *ct = setTemp;

}
