#include "strategy.h"
#include <stdio.h>

// 함수 포인터 정의
HandleHillDescentControlCommandFunction handleHillDescentControlCommand;

// 실제 함수 구현
void handleHillDescentControlCommandImpl() {
    HillDescentControlState state = getHillDescentControlState();
    if (state == OFF) {
        printf("내리막길 주행 제어 활성화\n");
        activateHillDescentControl();
    } else {
        printf("내리막길 주행 제어 비활성화\n");
        deactivateHillDescentControl();
    }
}

// 초기화 함수
void initHillDescentControl() {
    handleHillDescentControlCommand = handleHillDescentControlCommandImpl;
}
