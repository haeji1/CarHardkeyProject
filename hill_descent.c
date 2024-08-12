#include "strategy.h"
#include <stdio.h>
#include <string.h>

// 내부 상태 변수
static int currentHillDescentState = 0; // 0: OFF, 1: ON

// 실제 구현 함수
void activateHillDescentImpl() {
    currentHillDescentState = 1;
    printf("Hill descent control activated.\n");
    int values[] = {1};
    writeOrUpdateValueToFile("HILL_DESCENT", values, 1);  // 상태를 파일에 기록
}

void deactivateHillDescentImpl() {
    currentHillDescentState = 0;
    printf("Hill descent control deactivated.\n");
    int values[] = {0};
    writeOrUpdateValueToFile("HILL_DESCENT", values, 1);  // 상태를 파일에 기록
}

int getHillDescentStateImpl() {
    return currentHillDescentState;
}

// 함수 포인터 정의 및 초기화
ActivateHillDescentFunction activateHillDescent = activateHillDescentImpl;
DeactivateHillDescentFunction deactivateHillDescent = deactivateHillDescentImpl;
GetHillDescentStateFunction getHillDescentState = getHillDescentStateImpl;

// 명령 처리 함수
void handleHillDescentCommand() {
    char input[10];
    int running = 1;

    while (running) {
        printf("Enter command (ON/OFF) to control hill descent or 'exit' to quit:\n");
        printf("Current state: %s\n", getHillDescentState() == 1 ? "Activated" : "Deactivated");

        if (scanf("%9s", input) != 1) { // 버퍼 오버플로 방지
            printf("Input error.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        // 명령 처리
        if (strcmp(input, "ON") == 0) {
            activateHillDescent();
        } else if (strcmp(input, "OFF") == 0) {
            deactivateHillDescent();
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            running = 0; // 루프 종료
        } else {
            printf("Invalid command.\n");
        }

        // 입력 버퍼 비우기
        while (getchar() != '\n');
    }
}
 