

void muteButtonHandler() {
    static int is = 0; // 초기 상태는 음소거 해제
    is = !is; // 음소거 상태 토글
    if (is) {
        printf("\nAudio system is now MUTED\n");

    } else {
        printf("\nAudio system is now UNMUTED\n");

    }

}
