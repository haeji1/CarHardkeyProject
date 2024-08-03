//
// Created by MinseokK on 24. 8. 2.
//
#include <stdio.h>
#include "observer.h"
#include "ClimateTemp.h"


static int ClimateTempState = 22;

void handleClimateTemp(){
    printf("%d", ClimateTempState);
}

void initializeClimateTempHandlers() {
    registerHandler(CLIMATE_TEMP, handleClimateTemp);

}
