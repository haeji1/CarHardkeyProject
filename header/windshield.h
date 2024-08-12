#ifndef WINDSHIELD_WIPERS_H
#define WINDSHIELD_WIPERS_H

typedef void(*windshieldWipersControlFunction)();

void offWindshieldWipers();
void lowWindshieldWipers();
void highWindshieldWipers();
void windshieldWipersControl(windshieldWipersControlFunction);

#endif