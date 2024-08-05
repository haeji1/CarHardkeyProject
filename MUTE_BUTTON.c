
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일

void muteButtonHandler() {
    static int is = 0; // 초기 상태는 음소거 해제
    is = !is; // 음소거 상태 토글
    if (is) {
        printf("\nAudio system is now MUTED\n");

    } else {
        printf("\nAudio system is now UNMUTED\n");

    }
    sleep(3); // 3초 대기

}
