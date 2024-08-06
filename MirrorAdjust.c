//
// Created by MinseokK on 24. 8. 5.
//

#include "MirrorAdjust.h"
#include <stdio.h>
#include "observer.h"

void handleMirrorAdjust(){
    printf("MirrorAdjust");
}

void initializeMirrorAdjustHandlers() {
    registerHandler(MIRROR_ADJUST, handleMirrorAdjust);
}