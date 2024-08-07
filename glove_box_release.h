#ifndef GLOVE_BOX_RELEASE_H
#define GLOVE_BOX_RELEASE_H

typedef void(*GloveBoxReleaseFunction)();

void releaseGloveBoxLatch();
void setGloveBoxRelease(GloveBoxReleaseFunction func);

#endif // GLOVE_BOX_RELEASE_H
