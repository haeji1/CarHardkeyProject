//
// Created by MinseokK on 24. 8. 8.
//

#ifndef SEATADJUST_H
#define SEATADJUST_H
typedef struct{
    int seatId;
    int adjustType;
    int adjustValue;
} SeatState;

SeatState globalSeatState;

typedef void(*SeatAdjustControlFunction)();
void adjustSeatSeat(SeatState State);
void seatadjustHandlerWrapper();

void handleSeatAdjust(SeatAdjustControlFunction);

#endif //SEATADJUST_H
