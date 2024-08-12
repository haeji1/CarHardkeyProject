//
// Created by MinseokK on 24. 8. 8.
//

//0   // Window identifier (0 = FrontLeft, 1 = FrontRight, 2 = RearLeft, 3 = RearRight)
//1   // Action (0 = Up, 1 = Down)
#include <stdio.h>
#include "observer.h"
#include "PowerWindows.h"
#include <stdlib.h>
#include <unistd.h>


typedef void(*handlePowerWindowsControlFunction)();

static int WindowIdentifierState = 0;
static int Action = 1;

void adjustPowerWindows(WindowState state) {
    globalWindowState.windowId = state.windowId;
    globalWindowState.Action = state.Action;
}


void handlePowerWindows(handlePowerWindowsControlFunction pwcf){
    printf("status changed by function\n");

}

void windowsjustHandlerWrapper(){
    const char* windowName;
    switch (globalWindowState.windowId) {
        case 0:
            windowName = "FrontLeft";
        break;
        case 1:
            windowName = "FrontRight";
        break;
        case 2:
            windowName = "RearLeft";
        break;
        case 3:
            windowName = "RearRight";
        break;
        default:
            windowName = "Unknown";
        break;
    }
    printf("window %s heat Action to %d\n", windowName, globalWindowState.Action);
}
