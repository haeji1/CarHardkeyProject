//
// Created by MinseokK on 24. 8. 8.
//

#include <stdio.h>
#include "observer.h"
#include "ClimateTemp.h"
#include <unistd.h>
#include <stdlib.h>

static int ClimateTempState = 22;

void adjustTemp(TempState state){
    globalTempState.setting = state.setting;

}
// context
void handleClimateTemp(ClimateTempControlFunction ct){
    printf("status changed by function\n");
    sleep(1);

}
void ClimateTempHandlerWrapper() {
    // Wrapper function to call
    printf("====== Climate Temp is = %d ======\n",globalTempState.setting);
    sleep(3);
}
