//
// Created by MinseokK on 24. 8. 8.
//

#include "ClimateAirflow.h"
#include <stdio.h>
#include "observer.h"
#include "ClimateAirflow.h"
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

typedef void(*ClimateAirflowControlFunction)();

static int ClimateAirflowState = 2;


void AirflowFace(){
    if (ClimateAirflowState == 0) {
        printf("====== AirflowFace mode. ======\n");

    } else {
        ClimateAirflowState = 0;
        printf("====== AirflowFace Turned ======\n");
    }
    sleep(3);
}

void AirflowFoot(){
    if (ClimateAirflowState == 1) {
        printf("====== AirflowFoot mode. ======\n");
    } else {
        ClimateAirflowState = 1;
        printf("====== AirflowFoot Turned ======\n");
    }
    sleep(3);

}
void AirflowDefrost(){
    if (ClimateAirflowState == 2) {
        printf("====== AirflowDefrost mode. ======\n");
    } else {
        ClimateAirflowState = 2;
        printf("====== AirflowDefrost Turned ======\n");
    }
    sleep(3);
}

void handleClimateAirflow(ClimateAirflowControlFunction cfcf){
    printf("====== status changed by function ======\n");
    sleep(1);
}