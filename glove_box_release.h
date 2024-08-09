#ifndef GLOVE_BOX_RELEASE_H
#define GLOVE_BOX_RELEASE_H

typedef void(*GloveBoxReleaseFunction)();

void releaseGloveBox();
void setGloveBoxRelease(GloveBoxReleaseFunction gbr);

#endif // GLOVE_BOX_RELEASE_H
