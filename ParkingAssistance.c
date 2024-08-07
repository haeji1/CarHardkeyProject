#include "strategy.h"
#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위한 헤더

// 전역 변수를 사용하여 주차 지원 상태를 저장합니다.
static ParkingAssistState currentParkingAssistState = OFF;

// 주차 지원 기능을 활성화하는 함수
void activateParkingAssistImpl() {
    currentParkingAssistState = ON;
    printf("Parking assist activated.\n");
    sleep(3); // 3초 대기
}

// 주차 지원 기능을 비활성화하는 함수
void deactivateParkingAssistImpl() {
    currentParkingAssistState = OFF;
    printf("Parking assist deactivated.\n");
    sleep(3); // 3초 대기
}

// 현재 주차 지원 상태를 반환하는 함수
ParkingAssistState getParkingAssistStateImpl() {
    return currentParkingAssistState;
}

// 함수 포인터 할당
ActivateParkingAssistFunction activateParkingAssist = activateParkingAssistImpl;
DeactivateParkingAssistFunction deactivateParkingAssist = deactivateParkingAssistImpl;
GetParkingAssistStateFunction getParkingAssistState = getParkingAssistStateImpl;

// 사용자 입력을 처리하고 주차 지원 상태를 제어하는 함수
void handleParkingAssistCommand() {
    char input[10];

    while (1) {
        printf("Enter command (ON/OFF) to control parking assist or 'exit' to quit:\n");
        printf("Current state: %s\n", getParkingAssistState() == ON ? "Activated" : "Deactivated");
        scanf("%s", input);

        if (strcmp(input, "ON") == 0) {
            activateParkingAssist();
        } else if (strcmp(input, "OFF") == 0) {
            deactivateParkingAssist();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please enter 'ON', 'OFF', or 'exit'.\n");
        }
    }
}
