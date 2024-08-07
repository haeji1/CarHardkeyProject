//
// Created by MinseokK on 24. 8. 2.
//
//
// Created by MinseokK on 24. 7. 31.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "RadioSource.h"
#include "observer.h"



//static int sourceState = 1; // 0 for AM, 1 for FM, 2 BT
typedef void (*radioSourceControlFunction)();

void AM(void) {
    printf("AM");
    sleep(3);
}

void FM(void) {
    printf("FM");
    sleep(3);
}

void Bluetooth(void) {
    printf("BT");
    sleep(3);
}

//context
void handleRadioSource(radioSourceControlFunction rs) {

    printf("status changed by function\n");
    //(*rs)();  // rs 넣은 전략 함수를 실행;

}

//void initializeRadioSourceHandlers() {
//    registerHandler(RADIO_SOURCE, handleRadioSource);
//}