//
// Created by MinseokK on 24. 8. 8.
//

#include "WindowLock.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>

typedef void (*WindowLockControlFunction)();
static int WindowLockState = 1;

void WindowLock(){
    WindowLockState = 1;
    printf("DoorLock\n");
}
void WindowUnlock(){
    WindowLockState = 0;
    printf("DoorUnLock\n");
}
void handleWindowLock(WindowLockControlFunction wl){
    printf("status changed by function\n");
}