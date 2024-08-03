//
// Created by MinseokK on 24. 8. 3.
//
#include <stdio.h>
#include "observer.h"
#include "ClimateAirflow.h"


void handleClimateAirflow(){
    printf("Airflow");
}

void initializeClimateAirflowHandlers(){
    registerHandler(CLIMATE_AIRFLOW,handleClimateAirflow);
}