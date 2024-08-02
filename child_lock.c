#include <stdio.h>
#include "strategy.h"

typedef struct {
    LockStrategy strategy; // 현재 전략
    int lockStatus; // 잠금 상태
} LockContext;

typedef struct{


}REARDEFROST;

// 전략을 설정하는 함수
void setLockStrategy(LockContext *context, LockStrategy strategy) {
    context->strategy = strategy;
}

// 잠금 상태를 변경하고 전략을 실행하는 함수
void applyLock(LockContext *context) {
    context->strategy(context->lockStatus);
}

// 잠금 상태를 설정하는 함수
void setLockStatus(LockContext *context, int status) {
    context->lockStatus = status;
}
