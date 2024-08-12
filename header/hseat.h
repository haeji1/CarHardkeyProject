#ifndef HSEAT_H
#define HSEAT_H

typedef struct {
    int seatId;
    int heatLevel;
} HseatStatus;

HseatStatus globalHseatStatus;
typedef void(*heatSeatControlFunction)();

void adjustHeatedSeat(HseatStatus state);
void heatedSeatHandlerWrapper();

#endif