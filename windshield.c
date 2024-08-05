#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "windshield.h"

static int wipersState = 0; // 0 for OFF, 1 for LOW, 2 for HIGH

void offWipers();
void lowWipers();
void highWipers();

void handleWindshieldWipers(void) {

    int opt;
    printf(" == WINDSHIELD_WIPERS options == \n");
    printf("1. Off \n");
    printf("2. Low \n");
    printf("3. High \n");
    printf("4. EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
        offWipers();
    }else if(opt == 2){
        lowWipers();
    }else if(opt == 3){
        highWipers();
    }else if(opt == 4){
        exit(EXIT_FAILURE);
    }else{
        printf("Unknown WINDSHIELD_WIPERS command.\n");
    }

}

void offWipers(){
    if (wipersState == 0) {
        printf("Windshield wipers are OFF.\n");
    } else {
        wipersState = 0;
        printf("Windshield wipers turned OFF.\n");
    }
}

void lowWipers(){
    if (wipersState == 1) {
        printf("Windshield wipers are already LOW.\n");
    } else {
        wipersState = 1;
        printf("Windshield wipers turned LOW.\n");
    }
}

void highWipers(){
    if (wipersState == 2) {
        printf("Windshield wipers are already HIGH.\n");
    } else {
        wipersState = 2;
        printf("Windshield wipers turned HIGH.\n");
    }
}

void initializeWindshieldWipersHandlers() {
    registerHandler(WINDSHIELD_WIPERS, handleWindshieldWipers);
}