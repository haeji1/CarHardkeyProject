#include "strategy.h"
#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일

void childLockToggleImpl(int lockState) {
    int values[] = { lockState };
    if (lockState == 1) {
        printf("\nChild Lock is now Engaged\n");
    } else if (lockState == 0) {
        printf("\nChild Lock is now Disengaged\n");
    } else {
        printf("\nInvalid Lock State\n");
        return;
    }
    writeOrUpdateValueToFile("CHILD_LOCK", values, 1);  // 배열의 주소를 전달
    sleep(3); // 3초 대기
}

// Define function pointer
typedef void (*ChildLockToggleFunction)(int);
ChildLockToggleFunction childLockToggle = childLockToggleImpl;

void childFunction() {
    int lockState;

    printf("Enter lock state (1 to Engage, 0 to Disengage): ");
    scanf("%d", &lockState);

    childLockToggle(lockState); // Set child lock based on user input
}

