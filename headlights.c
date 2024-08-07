#include <stdio.h>
#include "headlights.h"

/*
    0 : off
    1 : low
    2 : high

*/

typedef void(*headlightsControlFunction)();

void offHeadlights(){
    printf("Headlights turned OFF.\n");
}

void lowHeadlights(){
    printf("Headlights turned LOW.\n");
}

void highHeadlights(){
    printf("Headlights turned HIGH.\n");
}

void headlightsControl(headlightsControlFunction hc){
    printf("status changed by function\n");
}