#include "strategy.h"
#include <stdio.h>
#include <unistd.h> // sleep 함수 사용을 위해 필요한 헤더 파일

// Placeholder for the actual audio state
static AudioState currentAudioState = UNMUTED;

// 실제 구현 함수
void toggleMuteImpl() {
    if (currentAudioState == UNMUTED) {
        currentAudioState = MUTED;
        printf("Audio system is muted.\n");
        sleep(3);
    } else {
        currentAudioState = UNMUTED;
        printf("Audio system is unmuted.\n");
        sleep(3);
    }
}

AudioState getAudioStateImpl() {
    return currentAudioState;
}

void muteButtonHandler() {
    // Toggle the mute state
    toggleMute(); // Mutes the audio system
    printf("Current audio state: %s\n", getAudioState() == MUTED ? "MUTED" : "UNMUTED");
}

// Define function pointers
ToggleMuteFunction toggleMute = toggleMuteImpl;
GetAudioStateFunction getAudioState = getAudioStateImpl;
