#include "hud_adjust.h"
#include <stdio.h>

//3 display setting

typedef void(*HUDAdjustFunction)();

void adjustHUDSettings() {
    printf("Jud Adjust setting.\n");
}

void setHUDAdjustFunction(HUDAdjustFunction haf) {
    printf("current status changed\n");
}
