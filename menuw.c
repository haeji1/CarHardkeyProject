#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일


// 자식 잠금 상태를 토글하는 함수
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

// 함수 포인터 정의
typedef void (*ChildLockToggleFunction)(int);
ChildLockToggleFunction childLockToggle = childLockToggleImpl;

// 메인 함수
void childFunction() {
    int lockState;

    printf("Enter lock state (1 to Engage, 0 to Disengage): ");
    while (scanf("%d", &lockState) != 1 || (lockState != 0 && lockState != 1)) {
        printf("Invalid input. Please enter 1 to Engage or 0 to Disengage: ");
        while (getchar() != '\n'); // 입력 버퍼 비우기
    }

    childLockToggle(lockState); // 자식 잠금 상태 설정
}

