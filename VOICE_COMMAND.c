

void Voice_Command_toggle() {
    static int is = 0; // 초기 상태는
    is = !is; // 음성 명령 토클
    if (is) {
        printf("\nVoice_Command system is now Active\n");

    } else {
        printf("\nVoice_Command system is now UnActive\n");

    }

}
