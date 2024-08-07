#ifndef HUD_ADJUST_H
#define HUD_ADJUST_H

typedef void(*HUDAdjustFunction)();

void adjustHUDSettings();
void setHUDAdjust(HUDAdjustFunction haf);

#endif // HUD_ADJUST_H
