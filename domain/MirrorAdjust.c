//
// Created by MinseokK on 24. 8. 8.
//
// MIRROR_ADJUST
//0 Mirror identifier (0 = Left, 1 = Right)
//1 Adjustment direction (0 = Up, 1 = Down, 2 = Left, 3 = Right)
//
//

#include "MirrorAdjust.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>
#include <unistd.h>

typedef void(*MirrorAdjustControlFunction)();


static int MirrorIdentifierState = 0;
static int  AdjustmentDirectionState = 1;




void adjustMirrorSeat(MirrorState state) {
    globalMirrorState.mirrorId = state.mirrorId;
    globalMirrorState.ajustmentDirection = state.ajustmentDirection;
}


void handleMirrorAdjust(MirrorAdjustControlFunction ma){
    printf("status changed by function\n");
    sleep(1);
}

void mirroradjustHandlerWrapper() {
    // Wrapper function to call
    const char *mirrorName = (globalMirrorState.mirrorId == 0) ? "Left" : "Right";
    printf("====== %s mirror ajustment set to %d ====== \n", mirrorName, globalMirrorState.ajustmentDirection);
    sleep(1);
}
