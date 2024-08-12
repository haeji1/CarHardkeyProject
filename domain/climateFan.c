//
// Created by MinseokK on 24. 8. 8.
//

#include <stdio.h>
#include "ClimateFan.h"
#include "observer.h"
#include <unistd.h>
#include <stdlib.h>

typedef void(*ClimateFanControlFunction)();
static int ClimateFan = 3; // 0 - 5 level

void Level_One(){
    if(ClimateFan == 1){
        printf("====== ClimateFanLevel : %d ======\n", ClimateFan);
    }
    else{
        ClimateFan = 1;
        printf("====== ClimateFanLevel : %d ======\n", ClimateFan);
    }

    sleep(3);
}
void Level_Two(){
    if(ClimateFan == 2){
        printf("====== ClimateFanLevel : %d ======\n", ClimateFan);
    }
    else{
        ClimateFan = 2;
        printf("====== ClimateFanLevel : %d ======\n", ClimateFan);
    }

    sleep(3);
}
void Level_Three(){
    if(ClimateFan == 3){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 3;
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }

    sleep(3);
}

void Level_Four(){
    if(ClimateFan == 4){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 4;
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }

    sleep(3);
}
void Level_Five(){
    if(ClimateFan == 5){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 5;
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }

    sleep(3);
}



void handleClimateFan(ClimateFanControlFunction cf){
    printf("status changed by function\n");
    sleep(1);
    //(*cf)();
}

