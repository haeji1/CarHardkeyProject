//
// Created by MinseokK on 24. 8. 8.
//

#include "DoorLock.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>

typedef void (*DoorLockControlFunction)();
static int DoorLockState = 1;

void DoorLock(){
    DoorLockState = 1;
    printf("DoorLock\n");
}
void DoorUnlock(){
    DoorLockState = 0;
    printf("DoorUnLock\n");
}
void handleDoorLock(DoorLockControlFunction dl){
    printf("status changed by function\n");
}