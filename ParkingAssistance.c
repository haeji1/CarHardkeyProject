#include "strategy.h"
#include <stdio.h>

static ParkingAssistState currentParkingAssistState = OFF;

// 주차 지원 기능을 활성화하는 함수
void activateParkingAssist() {
    currentParkingAssistState = ON;
    printf("Parking assist activated.\n");
    sleep(3);
}

// 주차 지원 기능을 비활성화하는 함수
void deactivateParkingAssist() {
    currentParkingAssistState = OFF;
    printf("Parking assist deactivated.\n");
    sleep(3);
}

// 현재 주차 지원 상태를 반환하는 함수
ParkingAssistState getParkingAssistState() {
    return currentParkingAssistState;
}

// 사용자 입력을 처리하고 주차 지원 상태를 제어하는 함수
void handleParkingAssistCommand() {
    char input[10];

    printf("Enter command (ON/OFF) to control parking assist or 'exit' to quit:\n");

        printf("Current state: %s\n", getParkingAssistState() == ON ? "Activated" : "Deactivated");
        scanf("%s", input);

        if (strcmp(input, "ON") == 0) {
            activateParkingAssist();
        } else if (strcmp(input, "OFF") == 0) {
            deactivateParkingAssist();
        } else {
            printf("Invalid command. Please enter 'ON', 'OFF', or 'exit'.\n");
        }
    }

