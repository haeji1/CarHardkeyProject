#include "strategy.h"
#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위한 헤더

// 전역 변수를 사용하여 차선 지원 상태를 저장합니다.
static LaneSupportState currentLaneSupportState = ON;

// 차선 지원 기능을 활성화하는 함수
void activateLaneSupportImpl() {
    currentLaneSupportState = ON;
    printf("Lane support activated.\n");
    int values[] = {};
    writeOrUpdateValueToFile("LANE_ASSIST", values, 1);  // 배열의 주소를 전달
    sleep(3); // 3초 대기
}

// 차선 지원 기능을 비활성화하는 함수
void deactivateLaneSupportImpl() {
    currentLaneSupportState = OFF;
    printf("Lane support deactivated.\n");
    int values[] = {0};
    writeOrUpdateValueToFile("LANE_ASSIST", values, 1);  // 배열의 주소를 전달
    sleep(3); // 3초 대기
}

// 현재 차선 지원 상태를 반환하는 함수
LaneSupportState getLaneSupportStateImpl() {
    return currentLaneSupportState;
}

// 함수 포인터 할당
ActivateLaneSupportFunction activateLaneSupport = activateLaneSupportImpl;
DeactivateLaneSupportFunction deactivateLaneSupport = deactivateLaneSupportImpl;
GetLaneSupportStateFunction getLaneSupportState = getLaneSupportStateImpl;

// 사용자 입력을 처리하고 차선 지원 상태를 제어하는 함수
void handleLaneSupportCommand() {
    char input[10];

    while (1) {
        printf("Enter command (ON/OFF) to control lane support or 'exit' to quit:\n");
        printf("Current state: %s\n", getLaneSupportState() == ON ? "Activated" : "Deactivated");
        scanf("%s", input);

        if (strcmp(input, "ON") == 0) {
            activateLaneSupport();
        } else if (strcmp(input, "OFF") == 0) {
            deactivateLaneSupport();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please enter 'ON', 'OFF', or 'exit'.\n");
        }
    }
}
