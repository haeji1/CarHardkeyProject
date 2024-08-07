#include "strategy.h"
#include <stdio.h>

// 함수 포인터 정의
AnswerCallFunction answerCall;
void initHillDescentControl();
void initAnswerCall();
void initEndCall();

// 실제 함수 구현
void answerCallImpl() {
    printf("answer the phone\n");
    // 실제 전화 응답 로직을 여기에 구현합니다.
}

// 초기화 함수
void initAnswerCall() {
    answerCall = answerCallImpl;
}
