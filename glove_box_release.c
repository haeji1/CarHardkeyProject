#include "glove_box_release.h"
#include <stdio.h>

// Function pointer for glove box release
typedef void(*GloveBoxReleaseFunction)();

void releaseGloveBox() {
	printf("\n***** glove box latch opened *****\n");
}

void setGloveBoxRelease(GloveBoxReleaseFunction gbr) {
    printf("\n***** Change the current state successful *****\n");
}
