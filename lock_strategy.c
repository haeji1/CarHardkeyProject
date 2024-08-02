#include "strategy.h"
#include <stdio.h>

static LockState currentLockState = DISENGAGED;

void engageLock() {
    currentLockState = ENGAGED;
    printf("Child lock engaged.\n");
}

void disengageLock() {
    currentLockState = DISENGAGED;
    printf("Child lock disengaged.\n");
}

LockState getLockState() {
    return currentLockState;
}





