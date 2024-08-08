//
// Created by MinseokK on 24. 8. 8.
//

#ifndef CLIMATETEMP_H
#define CLIMATETEMP_H

typedef void(*ClimateTempControlFunction)();

void setTemp();
void handleClimateTemp(ClimateTempControlFunction);

#endif //CLIMATETEMP_H
