#include <stdio.h>
#include "cseat.h"

/*
    Seat Identifier : (0 ~ 1)
    Cooled Level : (0 ~ 3)
*/

typedef void(*coolSeatControlFunction)();

void adjustCooledSeat(CseatStatus state) {
    globalCseatStatus.seatId = state.seatId;
    globalCseatStatus.coolLevel = state.coolLevel;
}

void CooledSeatControl(coolSeatControlFunction cs) {
    printf("status changed by function\n");
}

void cooledSeatHandlerWrapper() {
   const char *seatName = (globalCseatStatus.seatId == 0) ? "Driver" : "Passenger";
    printf("Seat %s cool level set to %d\n", seatName, globalCseatStatus.coolLevel);
}