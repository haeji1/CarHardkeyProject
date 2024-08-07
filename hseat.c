#include <stdio.h>
#include "hseat.h"

/*
    Seat Identifier : (0 ~ 1)
    Seat Level : (0 ~ 3)
*/

typedef void(*heatSeatControlFunction)();

void adjustHeatedSeat(HseatStatus state) {
    globalHseatStatus.seatId = state.seatId;
    globalHseatStatus.heatLevel = state.heatLevel;
}

void HeatedSeatControl(heatSeatControlFunction hc) {
    printf("status changed by function\n");
}

void heatedSeatHandlerWrapper() {
    // Wrapper function to call 
    const char *seatName = (globalHseatStatus.seatId == 0) ? "Driver" : "Passenger";
    printf("Seat %s heat level set to %d\n", seatName, globalHseatStatus.heatLevel);
}

