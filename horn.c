#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "observer.h"
#include "horn.h"

void handleHorn(void) {
    printf("Horn turned ON.\n");
    Sleep(1000);
}

void initializeHornHandlers() {
    registerHandler(HORN, handleHorn);
}