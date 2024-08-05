#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일

void Voice_Command_toggle() {
    static int is = 0; // 초기 상태는
    is = !is; // 음성 명령 토클
    if (is) {
        printf("\nVoice_Command system is now Active\n");

    } else {
        printf("\nVoice_Command system is now UnActive\n");

    }
    sleep(3); // 3초 대기
}
