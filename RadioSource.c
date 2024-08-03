//
// Created by MinseokK on 24. 8. 2.
//
//
// Created by MinseokK on 24. 7. 31.
//
#include <stdio.h>
#include "observer.h"
#include "RadioSource.h"
#include "display.h"


// 인터페이스
//typedef void (*radio_source_function)();
// 전략
// 전역 변수로 전략 함수 포인터를 선언

static int sourceState = 1; // 0 for AM, 1 for FM 2 BT
// 전략
void AM(void){

    if (sourceState == 0){
        printf("AM mode.\n");
    }
    else{
        sourceState = 0;
        printf("RadioSource Turned AM");
    }
}

void FM(void){
    if (sourceState == 1){
        printf("FM mode.\n");
    }
    else{
        sourceState = 1;
        printf("RadioSource Turned FM");
    }
}


void Bluetooth(void){
    if (sourceState == 2){
        printf("BT mode.\n");
    }
    else{
        sourceState = 2;
        printf("RadioSource Turned Bt");
    }
}


// Context
void handleRadioSource(void){
    int opt;
    printf(" == RadioSouce options == \n");
    printf("0. AM \n");
    printf("1. FM \n");
    printf("2. Bluetooth \n");
    printf("3. exit \n");

    scanf("%d", &opt);

    if (opt == 0) {
        AM();
    }else if(opt == 1){
        FM();
    }else if(opt == 2){
        Bluetooth();
    }else if(opt == 3){
        //exit(EXIT_FAILURE);
    }else{
        printf("Unknown RadioSource command.\n");
    }

}

void showDisplay() {
    displayMenu();
}
void initializeRadioSourceHandlers() {
    registerHandler(RADIO_SOURCE, handleRadioSource);

}