#include <stdio.h>
#include <stdlib.h>
#include "observer.h"

Observer *observer[NUM_KEYS];

// Initializes an observer array of size NUM_KEY
void initializeObservers() {
    for (int i = 0; i < NUM_KEYS; i++) {
        observer[i] = NULL;
    }
}

void registerHandler(HardKey hardkey, Handler handler) {

    // Dynamic space allocation for new observer processing
    Observer *newObserver = (Observer*)malloc(sizeof(Observer));
    newObserver -> Handler = handler;
    newObserver -> next = observer[hardkey];
    observer[hardkey] = newObserver;

}

// If there is the same handler for the input hardkey, the current observer is removed.
void unregisterHandler(HardKey hardKey, Handler handler) {
    Observer **now = &observer[hardKey];
    while (*now) {
        if ((*now) -> Handler == handler) {
            Observer* del = *now;
            *now = (*now) -> next;
            free(del);
            return; 
        }
        now = &(*now) -> next;
    }
}

// Calls all handlers registered with the input hardkey
void notifyHandlers(HardKey hardKey) {
    Observer *now = observer[hardKey];
    while (now) {
        now -> Handler();
        now = now -> next;
    }
}

// It is executed first when an event for hardkey is registered and the handler is called through notifyhandler.
void handlerEvent(HardKey hardKey) {
    notifyHandlers(hardKey);
}


