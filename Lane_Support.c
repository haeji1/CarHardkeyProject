#include "strategy.h"
#include <stdio.h>
#include <string.h>

// 전역 변수를 사용하여 차선 유지 지원 상태를 저장합니다.
static LaneSupportState currentLaneSupportState = OFF;

void activateLaneSupport() {
    currentLaneSupportState = ON;
    printf("Lane support activated.\n");
}

void deactivateLaneSupport() {
    currentLaneSupportState = OFF;
    printf("Lane support deactivated.\n");
}

LaneSupportState getLaneSupportState() {
    return currentLaneSupportState;
}

// 사용자 입력을 처리하고 차선 유지 지원 상태를 제어하는 함수
void handleLaneSupportCommand() {
    char input[10];

    printf("Enter command (ACTIVATE/DEACTIVATE) to control lane support or 'exit' to quit:\n");
    printf("Current state: %s\n", getLaneSupportState() == ON ? "Activated" : "Deactivated");
    scanf("%s", input);

    if (strcmp(input, "ACTIVATE") == 0) {
        activateLaneSupport();
    } else if (strcmp(input, "DEACTIVATE") == 0) {
        deactivateLaneSupport();
    } else if (strcmp(input, "exit") == 0) {
        return;
    } else {
        printf("Invalid command. Please enter ACTIVATE, DEACTIVATE, or exit.\n");
    }
}
