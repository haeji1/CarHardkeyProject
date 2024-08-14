#ifndef SUNROOF_H
#define SUNROOF_H

typedef void(*sunroofControlFunction)();

void openSunroof();
void closeSunroof();
void tiltSunroof();
void sunroofControl(sunroofControlFunction);

#endif