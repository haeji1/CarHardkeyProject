//
// Created by MinseokK on 24. 8. 3.
//
#include <stdio.h>
#include "ClimateFan.h"
#include "observer.h"



void handleClimateFan(){
    printf("this is Fan Handler");
}

void initializeClimateFanHandlers() {
    registerHandler(CLIMATE_FAN, handleClimateFan);
}