#ifndef RADIO_VOLUME_H
#define RADIO_VOLUME_H

typedef void(*radioVolumeFunction)(int volume);

void setRadioVolume(int volume);
void increaseRadioVolume(int increment);
void decreaseRadioVolume(int decrement);
void radioVolumeControl(radioVolumeFunction rcFunc, int volume);

#endif 