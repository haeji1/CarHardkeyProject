//
// Created by MinseokK on 24. 8. 5.
//

#include "WindowLock.h"
#include <stdio.h>
#include "observer.h"
#include <stdlib.h>
static int WindowLockState = 0;

void WindowLock(){
    WindowLockState = 1;
    printf("WindowLock\n");
}
void WindowUnlock(){
    WindowLockState = 0;
    printf("WindowUnLock\n");
}
void handleWindowLock(WindowLockControlFunction *wl){
    int opt;
    printf("Currently WindowLockState : %d \n",WindowLockState);

    printf(" == WindowLock options == \n");
    printf("0. WindowUnLock \n");
    printf("1. WindowLock \n");
    printf("2. exit \n");

    scanf("%d", &opt);


    if (opt == 0) {
        *wl = WindowUnlock;
    } else if (opt == 1) {
        *wl = WindowLock;
    } else if (opt == 2) {
        exit(EXIT_FAILURE);
    } else {
        printf("Unknown handleWindowLock command.\n");
    }
}

