#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "radio.h"

static int radioVolume = 0; 
static int radioTuning = 0;

void setVolume();
void setTuning();

void handleRadioVolume(void) {

    int opt;
    printf(" == RADIO_VOLUME options == \n");
    printf("1. Set volume \n");
    printf("2. EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
        setVolume();
    }else if(opt == 2){
        exit(EXIT_FAILURE);
    }else{
        printf("Unknown RADIO_VOLUME command.\n");
    }

}

void handleRadioTuning(void) {

    int opt;
    printf(" == RADIO_TUNING options == \n");
    printf("1. Set Tuning \n");
    printf("2. EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
        setTuning();
    }else if(opt == 2){
        exit(EXIT_FAILURE);
    }else{
        printf("Unknown RADIO_TUNING command.\n");
    }

}

void setVolume(){

    int flag = 0;
    while(!flag){
        printf("Enter radio volume (1~100) : \n");
        int volume;
        scanf("%d", &volume);
        radioVolume = volume;

        if(radioVolume >= 1 && radioVolume <= 100) flag = 1;
        
        printf("Out of range.\n");
    }

}

void setTuning(){
    
    printf("Enter radio frequency : \n");
    int fre;
    scanf("%d", &fre);
    radioTuning = fre;

}

void initializeRadioHandlers() {
    registerHandler(RADIO_VOLUME, handleRadioVolume);
    registerHandler(RADIO_TUNING, handleRadioTuning);
}