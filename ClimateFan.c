//
// Created by MinseokK on 24. 8. 3.
//
#include <stdio.h>
#include "ClimateFan.h"
#include "observer.h"
#include <unistd.h>

static int ClimateFan = 3; // 0 - 5 level

void Level_One(){
    if(ClimateFan == 1){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 1;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(2);
}
void Level_Two(){
    if(ClimateFan == 2){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 2;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(2);
}
void Level_Three(){
    if(ClimateFan == 3){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 3;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(2);
}

void Level_Four(){
    if(ClimateFan == 4){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 4;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(2);
}
void Level_Five(){
    if(ClimateFan == 5){
        printf("ClimateFanLevel : %d\n", ClimateFan);
    }
    else{
        ClimateFan = 5;
    }
    printf("ClimateFanLevel : %d\n", ClimateFan);
    sleep(2);
}



// 버퍼를 비우는 함수
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void handleClimateFan(){
    int opt;
    while(1){

        printf("Select the Fan Level (0 to 5): \n");
        if (scanf("%d", &opt) != 1) {
            printf("Invalid selection. Please try again.\n");
            clearInputBuffer(); // 입력 버퍼 비우기

            continue;
        }
        switch(opt){
            case 1:
                Level_One();
            break;
            case 2:
                Level_Two();
            break;
            case 3:
                Level_Three();
            break;
            case 4:
                Level_Four();
            break;
            case 5:
                Level_Five();
            break;
            default:
                printf("error\n");
                continue;
        }
        break;
    }
}

void initializeClimateFanHandlers() {
    registerHandler(CLIMATE_FAN, handleClimateFan);
}