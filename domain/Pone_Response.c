#include "strategy.h"
#include <stdio.h>

void respondSilently() {
    printf("Responding to call silently.\n");
}

// 전략 인터페이스를 위한 포인터
static PhoneResponseStrategy currentStrategy = respondSilently; // 기본값 설정

// 전략을 설정하는 함수
void setPhoneResponseStrategy(PhoneResponseStrategy strategy) {
    currentStrategy = strategy;
}

// 전화에 응답하는 함수
void respondToCall() {
    if (currentStrategy) {
        currentStrategy();
    } else {
        printf("No response strategy set.\n");
    }
}

