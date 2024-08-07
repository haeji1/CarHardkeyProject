#ifndef TRAILER_CONTROL_H
#define TRAILER_CONTROL_H

typedef void (*trailerControlFunction)();

void controlTrailer();
void setupTrailerControl(trailerControlFunction tcf);

#endif // TRAILER_CONTROL_H
