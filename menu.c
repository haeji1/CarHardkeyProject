#include <stdio.h>
#include "menu.h"
#include "observer.h"
#include "hud_adjust.h"
#include "glove_box_release.h"
#include "fog_lights.h"
#include "emergency_brake.h"
#include "trailer_control.h"
#include "auto_hold.h"
#include "hands_free.h"
// #include "seat_heater.h"
// #include "seat_cooler.h"




void autoHoldMenu() {
    
    int option, value;
    autoHoldFunction af;

    printf(" Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter autoHold state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 && (value != 0)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("TRACTION_CONTROL", value);

            // Set the traction control function
            if (value == 0) {
                af = autoHoldOff;
            } else {
                af = autoHoldOn;
            } 

            

            // Execute the traction control function
            setAutoHold(af);
            registerHandler(AUTO_HOLD, af);
            // Notify the event
            handlerEvent(AUTO_HOLD);
            unregisterHandler(AUTO_HOLD, af);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TRACTION_CONTROL");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    
    }
}

void hudAdjustMenu(){
    int option, value;
    HUDAdjustFunction haf;

    printf("Hud Adjust Menu: \n");
    printf("1. Activate Hud Adjust release\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;
    }
    
    switch (option) {
        case 1:

            haf = adjustHUDSettings;
            registerHandler(HUD_ADJUST, haf);
            handlerEvent(HUD_ADJUST);
            break;

        case 2:
            printf("Listening to events...\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }
















        








    