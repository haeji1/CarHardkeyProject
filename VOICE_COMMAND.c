#include "strategy.h"
#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일

void voiceCommandToggleImpl() {
    static int isActive = 0; // 초기 상태는 비활성화
    isActive = !isActive; // 음성 명령 토글
    if (isActive) {
        printf("\nVoice_Command system is now Active\n");
    } else {
        printf("\nVoice_Command system is now UnActive\n");
    }
    sleep(3); // 3초 대기
}

// Define function pointer
VoiceCommandToggleFunction voiceCommandToggle = voiceCommandToggleImpl;
