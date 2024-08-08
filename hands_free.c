#include <stdio.h>
#include "hands_free.h"


typedef void(*handsFreeFunction)();

void activateHandsFree() {
    printf("\n***** Hands-free mode activated *****\n");
}

void setHandsFree(handsFreeFunction hff) {
    hff(); 
    printf("\n***** Change the current state successful *****\n");
}
