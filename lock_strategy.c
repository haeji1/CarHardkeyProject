#include "strategy.h"
#include <stdio.h>
#include <string.h>

// 초기 잠금 상태 설정
static LockState currentLockState = DISENGAGED;

// 실제 함수 구현
void engageLockImpl() {
    currentLockState = ENGAGED;
    printf("Child lock engaged.\n");
}

void disengageLockImpl() {
    currentLockState = DISENGAGED;
    printf("Child lock disengaged.\n");
}

LockState getLockStateImpl() {
    return currentLockState;
}

// 함수 포인터 변수 정의 및 초기화
EngageLockFunction engageLock = engageLockImpl;
DisengageLockFunction disengageLock = disengageLockImpl;
GetLockStateFunction getLockState = getLockStateImpl;

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
    } else if (strcmp(input, "exit") == 0) {
        printf("Exiting...\n");
    } else {
        printf("Invalid command.\n");
    }
}

