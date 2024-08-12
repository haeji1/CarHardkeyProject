//
// Created by MinseokK on 24. 8. 8.
//

#ifndef CLIMATETEMP_H
#define CLIMATETEMP_H

typedef struct {
    int setting;
} TempState;

TempState globalTempState;

typedef void(*ClimateTempControlFunction)();

void adjustTemp(TempState state);
void handleClimateTemp(ClimateTempControlFunction);
void ClimateTempHandlerWrapper();
#endif //CLIMATETEMP_H
