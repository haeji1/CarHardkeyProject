#include "strategy.h"
#include <stdio.h>
#include <string.h>

static DefrostState currentDefrostState = OFF;

void activateDefrostImpl() {
    currentDefrostState = ON;
    printf("Rear defrost activated.\n");
}

void deactivateDefrostImpl() {
    currentDefrostState = OFF;
    printf("Rear defrost deactivated.\n");
}

DefrostState getDefrostStateImpl() {
    return currentDefrostState;
}

ActivateDefrostFunction activateDefrost = activateDefrostImpl;
DeactivateDefrostFunction deactivateDefrost = deactivateDefrostImpl;
GetDefrostStateFunction getDefrostState = getDefrostStateImpl;

void handleDefrostCommand() {
    char input[10];
    int running = 1;

    while (running) {
        printf("Enter command (ON/OFF) to control rear defrost or 'exit' to quit:\n");
        printf("Current state: %s\n", getDefrostState() == ON ? "Activated" : "Deactivated");

        // 입력 읽기
        if (scanf("%9s", input) != 1) { // 버퍼 오버플로 방지
            printf("Input error.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        // 명령 처리
        if (strcmp(input, "ON") == 0) {
            activateDefrost();
        } else if (strcmp(input, "OFF") == 0) {
            deactivateDefrost();
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

