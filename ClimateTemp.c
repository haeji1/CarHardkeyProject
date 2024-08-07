//
// Created by MinseokK on 24. 8. 2.
//
#include <stdio.h>
#include "observer.h"
#include "ClimateTemp.h"
#include <unistd.h>
#include <stdlib.h>

static int ClimateTempState = 22;

void setTemp(){
    printf("Currently Temp : %d\n", ClimateTempState);
    printf("Ajust Temp: \n");

    int input;
    scanf("%d", &input);
    if (input > -100 && input < 100){
        ClimateTempState = input;
    } else{
        printf("out of limit\n");
        setTemp();
    }

    printf("setting %d degree\n", ClimateTempState);
    sleep(3);
}
// context
void handleClimateTemp(ClimateTempControlFunction *ct){
    printf("Currently ClimateTempState : %d \n",ClimateTempState);
    *ct = setTemp;

}
