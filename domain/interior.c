#include <stdio.h>
#include <windows.h>
#include "observer.h"
#include "interior.h"

/*
    0 : Off
    1 : On
*/

typedef void (*interiorLightControlFunction)();

void offInteriorLight() {
    printf("Off the interior light\n");
}

void onInteriorLight() {
    printf("On the interior light\n");
}

void interiorLightControl(interiorLightControlFunction ic) {
    printf("status changed by function\n");
}