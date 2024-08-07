//
// Created by MinseokK on 24. 8. 5.
//

#include "DoorLock.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>
static int DoorLockState = 1;

void DoorLock(){
    DoorLockState = 1;
    printf("DoorLock\n");
}
void DoorUnlock(){
    DoorLockState = 0;
    printf("DoorUnLock\n");
}
void handleDoorLock(DoorLockControlFunction *dl){
    int opt;
    printf("Currently DoorLockState : %d \n",DoorLockState);
    printf(" == DoorLock options == \n");
    printf("0. DoorUnLock \n");
    printf("1. Doorlock \n");
    printf("2. exit \n");

    scanf("%d", &opt);


    if (opt == 0) {
        *dl = DoorUnlock;
    } else if (opt == 1) {
        *dl = DoorLock;
    } else if (opt == 2) {
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown handleDoorLock command.\n");
    }
}

