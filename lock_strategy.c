#include "strategy.h"
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일

// 현재 잠금 상태를 나타내는 변수
static LockState currentLockState = DISENGAGED;

// 실제 함수 구현
void engageLockImpl() {
    currentLockState = ENGAGED;
    printf("Child lock engaged.\n");
    sleep(3);
}

void disengageLockImpl() {
    currentLockState = DISENGAGED;
    printf("Child lock disengaged.\n");
    sleep(3);
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
    int command;
    while (1) {
        printf("Enter command (1 for ENGAGE, 2 for DISENGAGE)\n");
        scanf("%d", &command);
        if (command == 1) {
            int values[] = {1};
            engageLock();
            writeOrUpdateValueToFile("CHILD_LOCK", values, 1);
            break;
        } else if (command == 2) {
            int values[] = {0};
            disengageLock();
            writeOrUpdateValueToFile("CHILD_LOCK", values, 1);
            break;
        } else {
            printf("Invalid command. Please enter 1 or 2\n");
        }
    }
}
