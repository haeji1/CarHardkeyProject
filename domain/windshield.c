#include <stdio.h>
#include "windshield.h"

/*
    0 : off
    1 : low
    2 : high
*/

void offWindshieldWipers(){
    printf("Windshield wipers turned OFF.\n");
}

void lowWindshieldWipers(){
    printf("Windshield wipers turned LOW.\n");
}

void highWindshieldWipers(){
    printf("Windshield wipers turned HIGH.\n");
}

void windshieldWipersControl(windshieldWipersControlFunction wc){
    printf("status changed by function\n");
}