//
// Created by MinseokK on 24. 8. 5.
//

#include "DoorLock.h"
#include <stdio.h>
#include "observer.h"

void handleDoorLock(){
    printf("Door LOCK");
}

void initializeDoorLockHandlers() {
    registerHandler(DOOR_LOCKS, handleDoorLock);
}