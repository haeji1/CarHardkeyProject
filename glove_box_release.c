#include "glove_box_release.h"
#include <stdio.h>

// Function pointer for glove box release
typedef void(*GloveBoxReleaseFunction)();

void releaseGloveBox() {
	printf("glove box opened\n");
}

void setGloveBoxRelease(GloveBoxReleaseFunction gbr) {
    printf("current status changed\n");
}
