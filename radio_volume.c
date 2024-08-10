#include <stdio.h>
#include "radio_volume.h"

static int currentVolume = 50;  // initial volume setting

void setRadioVolume(int volume) {
    currentVolume = volume;
    printf("Radio volume set to %d\n", currentVolume);
}

void increaseRadioVolume(int increment) {
    currentVolume += increment;
    if (currentVolume > 100) currentVolume = 100;
    printf("Radio volume increased to %d\n", currentVolume);
}

void decreaseRadioVolume(int decrement) {
    currentVolume -= decrement;
    if (currentVolume < 0) currentVolume = 0;
    printf("Radio volume decreased to %d\n", currentVolume);
}

void radioVolumeControl(radioVolumeFunction radioVolumeFunc, int volume) {
    radioVolumeFunc(volume);
    printf("Volume control executed.\n");
}
