#include "strategy.h"
#include <stdio.h>

int currentCallState = 0; // 0: No Call, 1: Call Active

void answerPhoneImpl() {
    currentCallState = 1; // Set call state to active
    printf("Answering phone call.\n");
}

int getCallStateImpl() {
    return currentCallState;
}

// Initialize function pointers
AnswerPhoneFunction answerPhone = answerPhoneImpl;
GetCallStateFunction getCallState = getCallStateImpl;
