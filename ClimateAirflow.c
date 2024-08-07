//
// Created by MinseokK on 24. 8. 3.
//
#include <stdio.h>
#include "observer.h"
#include "ClimateAirflow.h"
#include <stdlib.h>

static int ClimateAirflowState = 2;

void AirflowFace(){
    if (ClimateAirflowState == 0) {
        printf("AirflowFace mode.\n");
    } else {
        ClimateAirflowState = 0;
        printf("AirflowFace Turned\n");
    }
}

void AirflowFoot(){
    if (ClimateAirflowState == 1) {
        printf("AirflowFoot mode.\n");
    } else {
        ClimateAirflowState = 1;
        printf("AirflowFoot Turned\n");
    }

}
void AirflowDefrost(){
    if (ClimateAirflowState == 2) {
        printf("AirflowDefrost mode.\n");
    } else {
        ClimateAirflowState = 2;
        printf("AirflowDefrost Turned\n");
    }
}

void handleClimateAirflow(ClimateAirflowControlFunction *cfcf){
    printf("Currently ClimateAirflowState : %d \n",ClimateAirflowState);


    printf(" == ClimateAirflowControl options == \n");
    printf("0. Face \n");
    printf("1. Foot \n");
    printf("2. Defrost \n");
    printf("3. exit \n");

    int opt;

    scanf("%d", &opt);


    if (opt == 0) {
        *cfcf = AirflowFace;
    } else if (opt == 1) {
        *cfcf = AirflowFoot;
    } else if (opt == 2) {
        *cfcf = AirflowDefrost;
    } else if (opt == 3) {
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown ClimateAirflowControl command.\n");
    }

}

