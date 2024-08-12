//
// Created by MinseokK on 24. 8. 8.
//

#ifndef DEFROST_H
#define DEFROST_H
typedef void(*DefrostControlFunction)();


void WindshieldDefrostON();
void WindshieldDefrostOFF();
void handleDefrost(DefrostControlFunction);
#endif //DEFROST_H
