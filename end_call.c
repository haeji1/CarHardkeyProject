#include "strategy.h"
#include <stdio.h>

void endCallImpl() {
    currentCallState = 0; // Set call state to inactive
    printf("Ending phone call.\n");
	int values[]={1};
    writeOrUpdateValueToFile("PHONE_END_CALL", values, 1);  // 상태를 파일에 기록
}

// Initialize function pointers
EndCallFunction endCall = endCallImpl;
