//
// Created by MinseokK on 24. 8. 2.
//


#ifndef RADIOSOURCE_H
#define RADIOSOURCE_H


typedef void(*radioSourceControlFunction)();

void AM();
void FM();
void Bluetooth();
void handleRadioSource(radioSourceControlFunction);

#endif // RADIOSOURCE_H