#include "strategy.h"
#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일

void voiceCommandToggleImpl() {
       int values[]={1};
        printf("\nVoice_Command system is now Active\n");
        writeOrUpdateValueToFile("VOICE_COMMAND", values, 1);  // 배열의 주소를 전달
    sleep(3); // 3초 대기
}

// Define function pointer
VoiceCommandToggleFunction voiceCommandToggle = voiceCommandToggleImpl;
