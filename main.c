#include <stdio.h>
#include "observer.h"
#include "observer.c"
#include "MUTE_BUTTON.c"
#include "VOICE_COMMAND.c"
#include "strategy.h"
#include "lock_strategy.c"
#include "rear_defrost_strategy.c"

int main(){
    initializeObservers();
    registerHandler(MUTE_BUTTON, muteButtonHandler);
    registerHandler(VOICE_COMMAND, Voice_Command_toggle);
    handlerEvent(MUTE_BUTTON); // MUTE_BUTTON 이벤트를 처리하여 음성 상태 변경
    handlerEvent(MUTE_BUTTON); // MUTE_BUTTON 이벤트를 처리하여 음성 상태 변경
    handlerEvent(VOICE_COMMAND); // MUTE_BUTTON 이벤트를 처리하여 음성 상태 변경
    handlerEvent(VOICE_COMMAND); // MUTE_BUTTON 이벤트를 처리하여 음성 상태 변경
    engageLock();
    printf("Lock state after engaging: %s\n", getLockState() == ENGAGED ? "Engaged" : "Disengaged");
    disengageLock();
    printf("Lock state after disengaging: %s\n", getLockState() == ENGAGED ? "Engaged" : "Disengaged");
    activateDefrost();
    printf("Defrost state after activation: %s\n", getDefrostState() == ON ? "On" : "Off");
    deactivateDefrost();
    printf("Defrost state after deactivation: %s\n", getDefrostState() == ON ? "On" : "Off");

    return 0;


}