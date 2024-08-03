//
// Created by MinseokK on 24. 8. 3.
//

#include "Defrost.h"
#include <stdio.h>
#include "observer.h"

void handleDefrost(){
    printf("Defrost");
}

void initializeDefrostlers() {
    registerHandler(DEFROST, handleDefrost);
}
