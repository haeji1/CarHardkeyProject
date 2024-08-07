//
// Created by MinseokK on 24. 8. 3.
//
#include <stdio.h>
#include "ClimateFan.h"
#include "observer.h"
#include <unistd.h>
#include <stdlib.h>

static int ClimateFan = 3; // 0 - 5 level

void Level_One(){
    if(ClimateFan == 1){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 1;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(3);
}
void Level_Two(){
    if(ClimateFan == 2){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 2;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(3);
}
void Level_Three(){
    if(ClimateFan == 3){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 3;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(3);
}

void Level_Four(){
    if(ClimateFan == 4){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 4;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(3);
}
void Level_Five(){
    if(ClimateFan == 5){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 5;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(3);
}



void handleClimateFan(ClimateFanControlFunction *cf){
    int opt;
    printf("Currently ClimateFan : %d \n",ClimateFan);
    while(1){

        printf("Select the Fan Level (0 to 5): \n");
        if (scanf("%d", &opt) != 1) {
            printf("Invalid selection. Please try again.\n");
        //    clearInputBuffer(); // 입력 버퍼 비우기

            continue;
        }
        switch(opt){
            case 1:
                *cf = Level_One;
            break;
            case 2:
                *cf = Level_Two;
            break;
            case 3:
                *cf = Level_Three;
            break;
            case 4:
                *cf = Level_Four;
            break;
            case 5:
                *cf = Level_Five;
            break;
            default:
                printf("error\n");
                continue;
        }
        break;
    }
    //(*cf)();
}

