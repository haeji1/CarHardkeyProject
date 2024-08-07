#include <stdio.h>
#include "trailer_control.h"


//1 control setting

typedef void(*trailerControlFunction)();

void controlTrailer() {
    printf("Trailer control setting\n");
}

void setupTrailerControl(trailerControlFunction tcf) {
    printf("Trailer control setup successful\n");
}
