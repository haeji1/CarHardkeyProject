#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "headlights.h"

static int headlightsState = 0; 

void offHeadlights();
void lowHeadlights();
void highHeadlights();

void handleHeadlights(void) {

    int opt;
    printf(" == HEADLIGHTS options == \n");
    printf("1. Off \n");
    printf("2. Low \n");
    printf("3. High \n");
    printf("4. EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
        offHeadlights();
    }else if(opt == 2){
        lowHeadlights();
    }else if(opt == 3){
        highHeadlights();
    }else if(opt == 4){
        exit(EXIT_FAILURE);
    }else{
        printf("Unknown HEADLIGHTS command.\n");
    }

}

void lowHeadlights(){
    if (headlightsState == 1) {
        printf("Headlights is already LOW.\n");
    } else {
        headlightsState = 1;
        printf("Headlights turned LOW.\n");
    }
}

void highHeadlights(){
    if (headlightsState == 2) {
        printf("Headlights is already HIGH.\n");
    } else {
        headlightsState = 2;
        printf("Headlights turned HIGH.\n");
    }
}

void offHeadlights(){
    if (headlightsState == 0) {
        printf("Headlights is already OFF.\n");
    } else {
        headlightsState = 0;
        printf("Headlights turned OFF.\n");
    }
}

void initializeHeadlightsHandlers() {
    registerHandler(HEADLIGHTS, handleHeadlights);
}