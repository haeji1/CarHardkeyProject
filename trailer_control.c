#include <stdio.h>
#include "trailer_control.h"


//1 control setting

typedef void(*trailerControlFunction)();

void controlTrailer() {
    printf("\n***** Trailer control setting *****\n");
}

void setTrailerControl(trailerControlFunction tcf) {
    printf("\n***** Change the current state successful *****\n");
}
