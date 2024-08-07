//
// Created by MinseokK on 24. 8. 8.
//

#include "RadioSource.h"
#include <stdio.h>

/*
    0 : open
    1 : close
    2 : tilt
*/

typedef void (*RadioSouceControlFunction)();

void AM() {
    printf("AM\n");
}

void FM() {
    printf("FM\n");
}

void BT(){
    printf("BTT");
}

void radioSouceControl(RadioSouceControlFunction rs) {
    printf("status changed by function\n");
}