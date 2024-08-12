#include "strategy.h"
#include <stdio.h>

int currentCallState = 0; // 0: No Call, 1: Call Active

void answerPhoneImpl() {
    currentCallState = 1; // Set call state to active
    printf("Answering phone call.\n");
	int values[]={1};
    writeOrUpdateValueToFile("PHONE_ANSWER", values, 1);  // 상태를 파일에 기록

}

int getCallStateImpl() {
    return currentCallState;
}

// Initialize function pointers
AnswerPhoneFunction answerPhone = answerPhoneImpl;
GetCallStateFunction getCallState = getCallStateImpl;
