#include <stdio.h>
#include "hands_free.h"


typedef void(*handsFreeFunction)();

void activateHandsFree() {
    printf("Hands-free system activated\n");
}

void setupHandsFree(handsFreeFunction hff) {
    hff(); 
    printf("Hands-free setup successful\n");
}
