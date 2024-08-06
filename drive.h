#ifndef DRIVE_H
#define DRIVE_H

typedef void(*driveModeControlFunction)();

void ecoMode();
void sportsMode();
void normalMode();
void driveModeControl(driveModeControlFunction);

#endif