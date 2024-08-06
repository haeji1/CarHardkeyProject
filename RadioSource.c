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



static int sourceState = 1; // 0 for AM, 1 for FM, 2 BT

void AM(void) {
    if (sourceState == 0) {
        printf("AM mode.\n");
    } else {
        sourceState = 0;
        printf("RadioSource Turned AM\n");
    }
    sleep(3);
}

void FM(void) {
    if (sourceState == 1) {
        printf("FM mode.\n");
    } else {
        sourceState = 1;
        printf("RadioSource Turning FM\n");
    }
    sleep(3);
}

void Bluetooth(void) {
    if (sourceState == 2) {
        printf("BT mode.\n");
    } else {
        sourceState = 2;
        printf("RadioSource Turned BT\n");
    }
    sleep(3);
}

//context
void handleRadioSource(radioSourceControlFunction *rs) {
    int opt;

    printf(" == RadioSource options == \n");
    printf("0. AM \n");
    printf("1. FM \n");
    printf("2. Bluetooth \n");
    printf("3. exit \n");

    scanf("%d", &opt);


    if (opt == 0) {
        *rs = AM;
    } else if (opt == 1) {
        *rs = FM;
    } else if (opt == 2) {
        *rs = Bluetooth;
    } else if (opt == 3) {
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown RadioSource command.\n");
    }

    //(*rs)();  // rs 넣은 전략 함수를 실행;

}

//void initializeRadioSourceHandlers() {
//    registerHandler(RADIO_SOURCE, handleRadioSource);
//}