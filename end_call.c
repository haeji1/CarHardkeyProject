#include "strategy.h"
#include <stdio.h>

// 함수 포인터 정의
EndCallFunction endCall;

// 실제 함수 구현
void endCallImpl() {
    printf("stop calling\n");
    // 실제 전화 종료 로직을 여기에 구현합니다.
}

// 초기화 함수
void initEndCall() {
    endCall = endCallImpl;
}
