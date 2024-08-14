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

        if (scanf("%9s", input) != 1) { // 버퍼 오버플로 방지
            printf("Input error.\n");
            while (getchar() != '\n'); // 입력 1버퍼 비우기
            continue;
        }
        // 명령 처리
        if (strcmp(input, "1") == 0) {
            int values[]={1};
            activateDefrost();
            writeOrUpdateValueToFile("REAR_DEFROST", values, 1);  // 배열의 주소를 전달
        } else if (strcmp(input, "2") == 0) {
            deactivateDefrost();
            int values[]={0};
            writeOrUpdateValueToFile("REAR_DEFROST", values, 1);  // 배열의 주소를 전달
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
