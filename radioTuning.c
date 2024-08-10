#include <stdio.h>
#include "radioTuning.h"

static int currentFrequency = 1010;  // initial frequency setting

void setRadioTuning(int frequency) {
    currentFrequency = frequency;
    printf("Radio frequency tuned to %d\n", currentFrequency);
}

void increaseRadioTuning(int increment) {
    currentFrequency += increment;
    if (currentFrequency > 1605) currentFrequency = 1605;
    printf("Radio frequency increased to %d\n", currentFrequency);
}

void decreaseRadioTuning(int decrement) {
    currentFrequency -= decrement;
    if (currentFrequency < 3) currentFrequency = 3;
    printf("Radio frequency decreased to %d\n", currentFrequency);
}

void radioTuningControl(radioTuningFunction rtFunc, int frequency) {
    rtFunc(frequency);
    printf("Frequency tuning executed.\n");
}
