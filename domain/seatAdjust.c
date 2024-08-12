//
// Created by MinseokK on 24. 8. 8.
//
// SEAT_ADJUST
//0 Seat identifier (0 = Driver, 1 = Passenger)
//1 Adjustment type (0 = Position, 1 = Recline, 2 = Lumbar)
//3 Adjustment value
//
//
//
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>
#include <unistd.h>
#include "SeatAdjust.h"
typedef void(*SeatAdjustControlFunction)();


void adjustSeatSeat(SeatState state) {
    globalSeatState.seatId = state.seatId;
    globalSeatState.adjustType = state.adjustType;
    globalSeatState.adjustValue = state.adjustValue;
}


void handleSeatAdjust(SeatAdjustControlFunction sac){
    printf("status changed by function\n");
    sleep(3);
}

void seatadjustHandlerWrapper() {
    // Wrapper function to call
    const char *seatName = (globalSeatState.seatId == 0) ? "Driver" : "Passenger";
    printf("====== %s seat mode adjustType set to %d, Adjust Value is %d ======\n", seatName, globalSeatState.adjustType, globalSeatState.adjustValue);
    sleep(3);
    // seat Driver heat adjustType set to Position, Adjustment is 3\n
}
//0 Seat identifier (0 = Driver, 1 = Passenger)
//1 Adjustment type (0 = Position, 1 = Recline, 2 = Lumbar)
//3 Adjustment value