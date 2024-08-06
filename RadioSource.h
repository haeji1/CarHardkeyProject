//
// Created by MinseokK on 24. 8. 2.
//


#ifndef RADIOSOURCE_H
#define RADIOSOURCE_H

#include <stdio.h>

typedef void(*radioSourceControlFunction)(void);

void AM(void);
void FM(void);
void Bluetooth(void);
void handleRadioSource(radioSourceControlFunction rs);

#endif // RADIOSOURCE_H