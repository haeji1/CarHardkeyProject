//
// Created by MinseokK on 24. 8. 8.
//

#include "RadioSource.h"
#include <stdio.h>
#include <unistd.h>
/*
    0 : open
    1 : close
    2 : tilt
*/

typedef void (*RadioSouceControlFunction)();

void AM() {
    printf("AM mode\n");
    sleep(3);
}

void FM() {
    printf("FM mode\n");
    sleep(3);
}

void BT(){
    printf("Bluetooth mode\n");
    sleep(3);
}

void radioSouceControl(RadioSouceControlFunction rs) {
    printf("status changed by function\n");
    sleep(2);
}