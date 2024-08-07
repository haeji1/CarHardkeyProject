#ifndef CSEAT_H
#define CSEAT_H

typedef struct {
    int seatId;
    int coolLevel;
} CseatStatus;

CseatStatus globalCseatStatus;
typedef void(*coolSeatControlFunction)();

void adjustCooledSeat(CseatStatus state);
void cooledSeatHandlerWrapper();

#endif