//
// Created by MinseokK on 24. 8. 8.
//

#ifndef MIRRORADJUST_H
#define MIRRORADJUST_H

typedef struct{
    int mirrorId;
    int ajustmentDirection;
} MirrorState;

MirrorState globalMirrorState;
typedef void(*MirrorAdjustControlFunction)();
void adjustMirrorSeat(MirrorState State);
void mirroradjustHandlerWrapper();
#endif //MIRRORADJUST_H
