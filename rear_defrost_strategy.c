#include "strategy.h"
#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위해 필요

// LockStrategy가 함수 포인터 타입이라 가정
typedef void (*LockStrategy)(int);

// LockContext 구조체 정의
typedef struct {
    LockStrategy strategy; // 현재 전략
    int lockStatus; // 잠금 상태
} LockContext;

// LockContext를 초기화하는 함수
void initLockContext(LockContext *context, LockStrategy strategy) {
    context->strategy = strategy;
    context->lockStatus = 0; // 초기 잠금 상태를 0으로 설정
}

// 잠금 상태를 설정하고 전략을 실행하는 함수
void setLock(LockContext *context, int status) {
    // 잠금 상태를 설정
    context->lockStatus = status;

    // 설정된 전략이 있는 경우 전략을 실행
    if (context->strategy) {
        context->strategy(context->lockStatus);
    } else {
        printf("No strategy set.\n");
    }
}

// Strategy 함수 정의
void Strategy(int status) {
    if (status) {
        printf("It's locked\n");
        int values[] = {1};
        writeOrUpdateValueToFile("CHILD_LOCK", values, 1);
        sleep(3); // 3초 대기
    } else {
        printf("It's unlocked\n");
        int values[] = {0};
        writeOrUpdateValueToFile("CHILD_LOCK", values, 1);
        sleep(3); // 3초 대기
    }
}

// 사용자 입력을 처리하는 함수
void processCommand(LockContext *context) {
    int command;
    printf("Enter command (1 for ENGAGE, 2 for DISENGAGE): ");
    if (scanf("%d", &command) != 1) {
        printf("Invalid input. Please enter 1 or 2.\n");
        while (getchar() != '\n'); // 입력 버퍼 비우기
        return;
    }

    switch (command) {
        case 1: // ENGAGE
            setLock(context, 1);
            break;
        case 2: // DISENGAGE
            setLock(context, 0);
            break;
        default:
            printf("Invalid command. Please enter 1 or 2.\n");
            break;
    }
}

// 메인 함수에서 모든 작업을 수행하는 함수
void childFunction(void) {
    static LockContext context;
    static int initialized = 0;

    if (!initialized) {
        // LockContext 초기화 및 전략 설정
        initLockContext(&context, Strategy);
        initialized = 1;
    }

    // 사용자 명령을 처리하여 잠금 상태를 변경
    processCommand(&context);
}

