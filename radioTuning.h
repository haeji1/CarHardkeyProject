#ifndef RADIO_TUNING_H
#define RADIO_TUNING_H

typedef void(*radioTuningFunction)(int frequency);

void setRadioTuning(int frequency);
void increaseRadioTuning(int increment);
void decreaseRadioTuning(int decrement);
void radioTuningControl(radioTuningFunction rtFunc, int frequency);

#endif 