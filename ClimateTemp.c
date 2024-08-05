//
// Created by MinseokK on 24. 8. 2.
//
#include <stdio.h>
#include "observer.h"
#include "ClimateTemp.h"
#include <unistd.h>

static int ClimateTempState = 22;

void handleClimateTemp(){
    int inputTemp;
    printf("Currently Temp : %d\n", ClimateTempState);
    printf("Ajust Temp:");
    scanf("%d", &inputTemp);
    if (ClimateTempState == 22){
        ClimateTempState = inputTemp;
        printf("setting %d degree", ClimateTempState);
    }
    else{ // 초기화 22도로

    }
    sleep(5);
}

void initializeClimateTempHandlers() {
    registerHandler(CLIMATE_TEMP, handleClimateTemp);

}
