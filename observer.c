#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "observer.h"

Observer *observer[NUM_KEYS];

// Initializes an observer array of size NUM_KEY
void initializeObservers() {
    for (int i = 0; i < NUM_KEYS; i++) {
        observer[i] = NULL;
    }
    printf("initialize success\n");
}

void registerHandler(HardKey hardkey, Handler handler) {

    Observer *newObserver = (Observer*)malloc(sizeof(Observer));
    newObserver->handler = handler;
    newObserver->next = NULL;
    if (observer[hardkey] == NULL) {
        observer[hardkey] = newObserver;
    } else {
        Observer *temp = observer[hardkey];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newObserver;
    }   
    // printf("Registered handler at %p\n", (void*)handler);
}

// If there is the same handler for the input hardkey, the current observer is removed.
void unregisterHandler(HardKey hardKey, Handler handler) {
    Observer **now = &observer[hardKey];
    while (*now) {
        printf("=====");
        printf("Checking handler at %p against %p\n", (void*)((*now)->handler), (void*)handler);
        if ((*now) -> handler == handler) {
            printf("free[[[]]]");
            Observer* del = *now;
            *now = (*now) -> next;
            free(del);
            del = NULL;
            printf("success unregister\n");
            return; 
        }
        now = &(*now) -> next;
    }
    
}

// Calls all handlers registered with the input hardkey
void notifyHandlers(HardKey hardKey) {
    Observer *now = observer[hardKey];
    while (now) {
        now -> handler();
        now = now -> next;
    }
}

// It is executed first when an event for hardkey is registered and the handler is called through notifyhandler.
void handlerEvent(HardKey hardKey) {
    printf("status changed\n");
    notifyHandlers(hardKey);
}

void unregisterFunction(HardKey hardKey, Handler handler) {
    Sleep(10000);
    printf("10 seconds\n");
    printf("unregister\n");
    unregisterHandler(hardKey, handler);
    printf("menu\n");
}