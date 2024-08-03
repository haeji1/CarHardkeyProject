//
// Created by MinseokK on 24. 8. 3.
//
#include <stdio.h>
#include "observer.h"
#include "PowerWindows.h"

void handlePowerWindows(){
    printf("PowerWindows");
}

void initializePowerWindowsHandlers() {
    registerHandler(POWER_WINDOWS, handlePowerWindows);

}