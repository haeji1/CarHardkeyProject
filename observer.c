#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "observer.h"

Observer *observer[NUM_KEYS];

void registerHandler(HardKey hardkey, Handler handler) {
    Observer *newObserver = (Observer *)malloc(sizeof(Observer));
    newObserver -> handler = handler;
    newObserver -> next = observer[hardkey];
    observer[hardkey] = newObserver;
    // printf("Registered handler at %p\n", (void*)handler);
}

// If there is the same handler for the input hardkey, the current observer is removed.
void unregisterHandler(HardKey hardKey, Handler handler) {
    Observer **now = &observer[hardKey];
    while (*now) {
        // printf("=====");
        // printf("Checking handler at %p against %p\n", (void*)((*now)->handler), (void*)handler);
        if ((*now) -> handler == handler) {
            Observer* del = *now;
            *now = (*now) -> next;
            free(del);
            printf(">>success unregister\n");
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
    printf(">> An event occures\n");
    notifyHandlers(hardKey);
}

void unregisterFunction(HardKey hardKey, Handler handler) {
    // Sleep(10000);
    unregisterHandler(hardKey, handler);
}