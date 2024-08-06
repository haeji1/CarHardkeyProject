//
// Created by MinseokK on 24. 8. 5.
//

#include "WindowLock.h"
#include <stdio.h>
#include "observer.h"

void handleWindowLock(){
    printf("Window LOCK");
}

void initializeWindowsLockHandlers() {
    registerHandler(WINDOW_LOCK, handleWindowLock);
}