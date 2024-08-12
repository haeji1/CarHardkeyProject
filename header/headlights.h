#ifndef HEADLIGHTS_H
#define HEADLIGHTS_H

typedef void(*headlightsControlFunction)();

void offHeadlights();
void lowHeadlights();
void highHeadlights();
void headlightsControl(headlightsControlFunction);

#endif