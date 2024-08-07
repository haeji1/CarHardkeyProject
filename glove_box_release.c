#include "glove_box_release.h"
#include <stdio.h>

// Function pointer for glove box release
typedef void(*GloveBoxReleaseFunction)();

void releaseGloveBoxLatch() {
	printf("glove box released\n");
}

void setGloveBoxRelease(GloveBoxReleaseFunction func) {
    printf("current status changed\n");
}
