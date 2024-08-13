#ifndef DISPLAY_H
#define DISPLAY_H

#include "observer.h"

void displayMenu();
int displayHardkeyOption(HardKey key);
const char* getHardKeyName(HardKey key);

#endif