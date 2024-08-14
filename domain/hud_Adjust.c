#include "hud_adjust.h"
#include <stdio.h>

//3 display setting

typedef void(*HUDAdjustFunction)();

void adjustHUDSettings() {
    printf("Hud Adjust released\n");
}

void setHUDAdjust(HUDAdjustFunction haf) {
    printf("\n***** Change the current state successful *****\n");
}
