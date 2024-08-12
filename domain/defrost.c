//
// Created by MinseokK on 24. 8. 8.
//

#include "Defrost.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>
#include <unistd.h>

typedef void (*DefrostControlFunction)();
static int deforstState = 1;

void WindshieldDefrostON(){
    deforstState = 1;
    printf("====== Defrost_ON ======\n");
    sleep(3);
}
void WindshieldDefrostOFF(){
    deforstState = 0;
    printf("====== Defrost_OFF ======\n");
    sleep(3);
}


void handleDefrost(DefrostControlFunction dfc){
    printf("status changed by function\n");
    sleep(1);

}