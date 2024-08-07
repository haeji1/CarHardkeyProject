#include <stdio.h>
#include "hands_free.h"


typedef void(*handsFreeFunction)();

void activateHandsFree() {
    printf("Hands-fre emode activated\n");
}

void setHandsFree(handsFreeFunction hff) {
    hff(); 
    printf("Hands-free setup successful\n");
}
