#include "strategy.h"
#include <stdio.h>
#include <string.h>

static LockState currentLockState = DISENGAGED;

// 잠금 기능을 활성화하는 함수
void engageLock() {
    currentLockState = ENGAGED;
    printf("Child lock engaged.\n");
}

// 잠금 기능을 비활성화하는 함수
void disengageLock() {
    currentLockState = DISENGAGED;
    printf("Child lock disengaged.\n");
}

// 현재 잠금 상태를 반환하는 함수
LockState getLockState() {
    return currentLockState;
}

// 사용자 입력을 처리하고 잠금 상태를 제어하는 함수
void handleLockCommand() {
    char input[10];

    printf("Enter command (ENGAGE/DISENGAGE) to control child lock or 'exit' to quit:\n");
    printf("Current state: %s\n", getLockState() == ENGAGED ? "Engaged" : "Disengaged");
    scanf("%s", input);

    if (strcmp(input, "ENGAGE") == 0) {
        engageLock();
    } else if (strcmp(input, "DISENGAGE") == 0) {
        disengageLock();
    }
}

