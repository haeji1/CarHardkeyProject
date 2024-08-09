#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "horn.h"
#include "headlights.h"
#include "turnsignals.h"
#include "sunroof.h"
#include "trunk.h"
#include "fuel.h"
#include "drive.h"
#include "traction.h"
#include "observer.h"
#include "steering.h"
#include "interior.h"
#include "auto_hold.h"
#include "pbrake.h"
#include "hseat.h"
#include "cseat.h"
#include "file.c"
#include "RadioSource.h"
#include "ClimateAirflow.h"
#include "ClimateFan.h"
#include "ClimateTemp.h"
#include "Defrost.h"
#include "DoorLock.h"
#include "MirrorAdjust.h"
#include "PowerWindows.h"
#include "WindowLock.h"
#include "SeatAdjust.h"

#define MAX_NUM 5
#define ONE 1
#define TWO 2

void autoHoldMenu(){
    int values[MAX_NUM];
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
            printf("Enter Auto Hold state (0=Off, 1=On): ");
        if (scanf("%d", &value) != 1 && (value != 0)) {
            printf("Invalid input. Enter 0 or 1.\n");
            return;
        }



        values[0] = value;
        writeOrUpdateValueToFile("AUTO_HOLD", values, 1);

        if (value == 0) {
            af = autoHoldOff;
        } else {
            af = autoHoldOn;
        }
        setAutoHold(af);
        registerHandler(AUTO_HOLD, af);
        handlerEvent(AUTO_HOLD);
        unregisterHandler(AUTO_HOLD, af);
        printf("****************************************\n");
        break;

        case 2:
            printf("Listening to events...\n");
        printCurrentValues("AUTO_HOLD", 1);
        printf("****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;

    }
}

void hornMenu() {
    int option, value;
    hornControlFunction hc;

    printf("Horn Menu:\n");
    printf("1. Activate horn\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            // Register the handler
            hc = activateHorn;
            registerHandler(HORN, hc);
            // Notify the event
            handlerEvent(HORN);
            unregisterHandler(HORN, hc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("HORN");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void radioSourceMenu() {
    int option, value;
    int values[MAX_NUM];
    RadioSouceControlFunction rc;

    printf("****************************************\n");
    printf("            RADIO_SOURCE Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter RADIO_SOURCE state (0 = AM, 1 = FM, 2 = Bluetooth)\n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
        if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
            printf("Invalid input. Enter 0 or 1.\n");
            return;
        }
        printf("****************************************\n");
        // Perform write operation to file if needed
        values[0] = value;
        writeOrUpdateValueToFile("RADIO_SOURCE", values, ONE);

        // Set the sunroof control function
        if (value == 0) {
            rc = AM;
        } else if (value == 1) {
            rc = FM;
        } else if(value == 2){
            rc = BT;
        }

        // Execute the traction control function
        radioSouceControl(rc);
        registerHandler(RADIO_SOURCE, rc);
        // Notify the event
        handlerEvent(RADIO_SOURCE);
        unregisterHandler(RADIO_SOURCE, rc);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("RADIO_SOURCE", ONE);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}
void climateAirflowMenu() {
    int option, value;
    int values[MAX_NUM];
    ClimateAirflowControlFunction cac;
    printf("****************************************\n");
    printf("            CLIMATE_AIRFLOW Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter climateAirflow state (0= Face, 1= Foot, 2= Defrost): \n");  // 교체 airflow로
            printf("            Enter your choice: \n");
            printf("****************************************\n");
        if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
            printf("Invalid input. Enter 0 or 1.\n");
            return;
        }

        // Perform write operation to file if needed
        values[0] = value;
        writeOrUpdateValueToFile("CLIMATE_AIRFLOW", values, ONE);

        // Set the sunroof control function
        if (value == 0) {
            cac = AirflowFace;
        } else if (value == 1) {
            cac = AirflowFoot;
        } else if(value == 2){
            cac = AirflowDefrost;
        }

        // Execute the traction control function
        handleClimateAirflow(cac);
        registerHandler(CLIMATE_AIRFLOW, cac);
        // Notify the event
        handlerEvent(CLIMATE_AIRFLOW);
        unregisterHandler(CLIMATE_AIRFLOW, cac);
        break;

        case 2:
            printf("Listening to events...\n");
        // Implement event listening functionality if needed
        printCurrentValues("CLIMATE_AIRFLOW", ONE);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}

void climateFanMenu() {
    int option, value;
    int values[MAX_NUM];
    ClimateFanControlFunction cf;

    printf("****************************************\n");
    printf("            CLIMATE_FAN Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
        printf("****************************************\n");
        printf("Enter CLIMATE_FAN level (1 = level_1, 2 = level_2, 3 = level_3, 4 = level_4, 5 = level_5):\n");
        printf("            Enter your choice: \n");
        printf("****************************************\n");
        if (scanf("%d", &value) != 1 || value < 1 || value > 5) {
            printf("Invalid input. Enter a value between 1 and 5.\n");
        return;
        }

        // Perform write operation to file if needed
        values[0] = value;
        writeOrUpdateValueToFile("CLIMATE_FAN", values, ONE);

        // Set the sunroof control function
        if (value == 1) {
            cf = Level_One;
        } else if (value == 2) {
            cf = Level_Two;
        } else if(value == 3){
            cf = Level_Three;
        }else if(value == 4){
            cf = Level_Four;
		}
		else if(value == 5){
            cf = Level_Five;
		}
        // Execute the traction control function
        handleClimateFan(cf);
        registerHandler(CLIMATE_FAN, cf);
        // Notify the event
        handlerEvent(CLIMATE_FAN);
        unregisterHandler(CLIMATE_FAN, cf);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("CLIMATE_FAN", ONE);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}

void ClimateTempMenu() {
    int option, setting;
    int values[MAX_NUM];
    ClimateTempControlFunction ct;
    TempState state;

    printf("****************************************\n");
    printf("            CLIMATE_TEMP Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
        printf("****************************************\n");
        printf("Enter CLIMATE_TEMP setting -20 to 80: \n");  /////////// 세팅
        printf("            Enter your setting: \n");
        printf("****************************************\n");
        if (scanf("%d", &setting) != 1 || setting < -20 || setting > 80){
            printf("Invalid input. Enter 0 or 1.\n");
            return;
        }

        state.setting = setting;
        // Perform write operation to file if needed
        values[0] = setting;
        writeOrUpdateValueToFile("CLIMATE_TEMP", values, ONE);

        // Set the sunroof control function
        adjustTemp(state);
        ct = ClimateTempHandlerWrapper;

        // Execute the traction control function
        handleClimateTemp(ct);
        registerHandler(CLIMATE_TEMP, ct);
        // Notify the event
        handlerEvent(CLIMATE_TEMP);
        unregisterHandler(CLIMATE_TEMP, ct);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("CLIMATE_TEMP", ONE);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}

void DefrostMenu() {
    int option, value;
    int values[MAX_NUM];
    DefrostControlFunction dfc;

    printf("****************************************\n");
    printf("            DEFROST Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter Defrost state (0=OFF, 1=ON): \n");  /////////// 세팅
            printf("            Enter your setting: \n");
            printf("****************************************\n");
        if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
            printf("Invalid input. Enter 0 or 1.\n");
            return;
        }

        // Perform write operation to file if needed
        values[0] = value;
        writeOrUpdateValueToFile("DEFROST", values, ONE);

        // Set the sunroof control function
        if (value == 0) {
            dfc = WindshieldDefrostOFF;
        } else if(value == 1) {
            dfc = WindshieldDefrostON;
        }
        // Execute the traction control function
        handleDefrost(dfc);
        registerHandler(DEFROST, dfc);
        // Notify the event
        handlerEvent(DEFROST);
        unregisterHandler(DEFROST, dfc);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("DEFROST", ONE);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}
void WindowLockMenu() { /////////////////////
    int option, value;
    int values[MAX_NUM];
    WindowLockControlFunction wl;

    printf("****************************************\n");
    printf("            WindowLock Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter WindowLock state (0=DoorUnlock, 1=Windowlock): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
        if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
            printf("Invalid input. Enter 0 or 1.\n");
            return;
        }

        // Perform write operation to file if needed
        values[0] = value;
        writeOrUpdateValueToFile("WINDOW_LOCK", values, ONE);

        // Set the sunroof control function
        if (value == 0) {
            wl = WindowUnlock;
        } else if (value == 1) {
            wl = WindowLock;
        }

        // Execute the traction control function
        handleWindowLock(wl);
        registerHandler(WINDOW_LOCK, wl);
        // Notify the event
        handlerEvent(WINDOW_LOCK);
        unregisterHandler(WINDOW_LOCK, wl);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("WINDOW_LOCK", ONE);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}
void DoorLockMenu() {
    int option, value;
    int values[MAX_NUM];
    DoorLockControlFunction dl;

    printf("****************************************\n");
    printf("            Doorlock Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter DoorLock state (0=DoorUnlock, 1=Doorlock): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
        if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
            printf("Invalid input. Enter 0 or 1.\n");
            return;
        }

        // Perform write operation to file if needed
        values[0] = value;
        writeOrUpdateValueToFile("DOOR_LOCKS", values, ONE);

        // select 0 to 1
        if (value == 0) {
            dl = DoorUnlock;
        } else if (value == 1) {
            dl = DoorLock;
        }

        // Execute the traction control function
        handleDoorLock(dl);
        registerHandler(DOOR_LOCKS, dl);
        // Notify the event
        handlerEvent(DOOR_LOCKS);
        unregisterHandler(DOOR_LOCKS, dl);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("DOOR_LOCKS", ONE);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}

void mirrorAdjustMenu() { /////////////////////////////////////////////
    int option, mirrorId, ajustmentDirection;
    int values[MAX_NUM];
    MirrorAdjustControlFunction ma;
    MirrorState state;

    printf("****************************************\n");
    printf("            MIRROR_ADJUST Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter mirrorAdjust state (0=Left, 1=Right): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");

            if (scanf("%d", &mirrorId) != 1 || (mirrorId != 0 && mirrorId != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
            return;
            }
            printf("****************************************\n");
            printf("Enter ajustmentDirection (0-3): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
            if (scanf("%d", &ajustmentDirection) != 1 || (ajustmentDirection < 0 || ajustmentDirection > 3)) {
                printf("Invalid input. Enter a value between 0 and 3.\n");
                return;
            }

        state.mirrorId = mirrorId;
        state.ajustmentDirection = ajustmentDirection;
        // Perform write operation to file if needed
        values[0] = mirrorId;
        values[1] = ajustmentDirection;
        writeOrUpdateValueToFile("MIRROR_ADJUST", values, 2);


        // Execute the traction control function
        adjustMirrorSeat(state);
        ma = mirroradjustHandlerWrapper;

        registerHandler(MIRROR_ADJUST, ma);
        // Notify the event
        handlerEvent(MIRROR_ADJUST);
        unregisterHandler(MIRROR_ADJUST, ma);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("MIRROR_ADJUST", 2);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}
/// powerwindow
void powerwindowMenu() { /////////////////////////////////////////////
    int option, windowId, Action;
    int values[MAX_NUM];
    handlePowerWindowsControlFunction pwcf;
    WindowState state;

    printf("****************************************\n");
    printf("            POWER_WINDOWS Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter powerwindow state (0=FrontLeft, 1=FrontRight, 2=RearLeft, 3=RearRight): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
            if (scanf("%d", &windowId) != 1 || windowId < 0 || windowId > 3) {
                printf("Invalid input. Enter a value between 0 and 3.\n");
            return;
            }

            printf("Enter Action (0 = Up, 1 = Down): ");
            if (scanf("%d", &Action) != 1 || (Action != 0 && Action != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
            return;
            }

        state.windowId = windowId;
        state.Action = Action;
        // Perform write operation to file if needed
        values[0] = windowId;
        values[1] = Action;
        writeOrUpdateValueToFile("POWER_WINDOWS", values, 2);


        // Execute the traction control function
        adjustPowerWindows(state);
        pwcf = windowsjustHandlerWrapper;

        registerHandler(POWER_WINDOWS, pwcf);
        // Notify the event
        handlerEvent(POWER_WINDOWS);
        unregisterHandler(POWER_WINDOWS, pwcf);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("POWER_WINDOWS", 2);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }
}
////////////////////////////////////////////////////////
void seatAdjustMenu() { /////////////////////////////////////////////
    int option, seatId, adjustType, adjustValue;
    int values[MAX_NUM];
    SeatAdjustControlFunction sac;
    SeatState state;

    printf("****************************************\n");
    printf("            SEAT_ADJUST Menu:\n");
    printf("        1. Write value to file\n");
    printf("        2. Listen to event\n");
    printf("            Enter your choice: \n");
    printf("****************************************\n");

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("****************************************\n");
            printf("Enter seatAdjust state (0= Driver, 1= Passenger): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
            if (scanf("%d", &seatId) != 1 || (seatId != 0 && seatId != 1)) {
                printf("Invalid input. Enter a value between 0 and 1.\n");
            return;
            }

            // Adjust type User input
            printf("****************************************\n");
            printf("Enter Adjustment type (0 = Position, 1 = Recline, 2 = Lumbar): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
            if (scanf("%d", &adjustType) != 1 || (adjustType < 0 || adjustType > 2)) {
                printf("Invalid input. Enter a value between 0 and 2.\n");
            return;
            }
            // Adjust Value 1~3
            printf("****************************************\n");
            printf("Enter Adjust Value (1 = level_1, 2 = level_2, 3 = level_3): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
            if (scanf("%d", &adjustValue) != 1 || adjustType < 1 || adjustType > 3) {
                printf("Invalid input. Enter a value between 1 and 3.\n");
            return;
            }

        state.seatId = seatId;
        state.adjustType = adjustType;
        state.adjustValue = adjustValue;
        // Perform write operation to file if needed
        values[0] = seatId;
        values[1] = adjustType;
        values[2] = adjustValue;

        writeOrUpdateValueToFile("SEAT_ADJUST", values, 3);


        // Execute the traction control function
        adjustSeatSeat(state);
        sac = seatadjustHandlerWrapper;

        registerHandler(SEAT_ADJUST, sac);
        // Notify the event
        handlerEvent(SEAT_ADJUST);
        unregisterHandler(SEAT_ADJUST, sac);
        break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("SEAT_ADJUST", 3);
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void headlightsMenu(){
    int option, value;
    headlightsControlFunction hc;

    printf("HEADLIGHTS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter headlights state (0=Off, 1=Low, 2=High): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("HEADLIGHTS", value);

            // Set the headlights control function
            if (value == 0) {
                hc = offHeadlights;
            } else if (value == 1) {
                hc = lowHeadlights;
            } else {
                hc = highHeadlights;
            }

            // Execute the traction control function
            headlightsControl(hc);
            registerHandler(HEADLIGHTS, hc);
            // Notify the event
            handlerEvent(HEADLIGHTS);
            unregisterHandler(HEADLIGHTS, hc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("HAEDLIGHTS");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }

}

void turnSignalsMenu(){
    int option, value;
    turnSignalsControlFunction tc;

    printf("TURN_SIGNALS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter turn signals state (0=Left, 1=Right): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("TURN_SIGNALS", value);

            // Set the headlights control function
            if (value == 0) {
                tc = leftTurnSignal;
                
            } else {
                tc = rightTurnSignal;
            }

            // Execute the traction control function
            turnSignalsControl(tc);
            registerHandler(TURN_SIGNALS, tc);
            // Notify the event
            handlerEvent(TURN_SIGNALS);
            unregisterHandler(TURN_SIGNALS, tc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("TURN_SIGNALS");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }

}

void sunroofMenu() {
    int option, value;
    int values[MAX_NUM];
    sunroofControlFunction sc;

    printf("SUNROOF Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter sunroof state (0=Open, 1=Close, 2=Tilt): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("SUNROOF_CONTROL", values, ONE);

            // Set the sunroof control function
            if (value == 0) {
                sc = openSunroof;
            } else if (value == 1) {
                sc = closeSunroof;
            } else {
                sc = tiltSunroof;
            }

            // Execute the traction control function
            printf("****************************\n");
            sunroofControl(sc);
            registerHandler(SUNROOF_CONTROL, sc);
            // Notify the event
            handlerEvent(SUNROOF_CONTROL);
            unregisterHandler(SUNROOF_CONTROL, sc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("SUNROOF_CONTROL", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void trunkReleaseMenu() {
    int option, value;
    int values[MAX_NUM];
    trunkReleaseControlFunction tr;

    printf("TRUNK RELEASE Menu:\n");
    printf("1. Activate trunk release\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("TRUNK_RELEASE", values, ONE);
            // Register the handler
            printf("****************************\n");
            tr = activateTrunkRelease;
            registerHandler(TRUNK_RELEASE, tr);
            // Notify the event
            handlerEvent(TRUNK_RELEASE);
            unregisterHandler(TRUNK_RELEASE, tr);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("Trunk_RELEASE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void fuelCapReleaseMenu() {
    int option, value;
    int values[MAX_NUM];
    fuelCapReleaseControlFunction fr;

    printf("FUEL CAP RELEASE Menu:\n");
    printf("1. Activate fuel cap release\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("FUEL_CAP_RELEASE", values, ONE);
            // Register the handler
            printf("****************************\n");
            fr = activateFuelCapRelease;
            registerHandler(FUEL_CAP_RELEASE, fr);
            // Notify the event
            handlerEvent(FUEL_CAP_RELEASE);
            unregisterHandler(FUEL_CAP_RELEASE, fr);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("FUEL_CAP_RELEASE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void parkingBrakeMenu() {
    int option, value;
    int values[MAX_NUM];
    parkingBrakeControlFunction pc;

    printf("Parking Brake Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter brake state (0=Disengage, 1=Engage): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("PARKING_BRAKE", values, ONE);

            // Set the brake control function
            if (value == 0) {
                pc = disengageBrake;
            } else {
                pc = engageBrake;
            }

            // Execute the brake control function
            printf("****************************\n");
            parkingBrakeControl(pc);
            registerHandler(PARKING_BRAKE, pc);
            // Notify the event
            handlerEvent(PARKING_BRAKE);
            unregisterHandler(PARKING_BRAKE, pc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("PARKING_BRAKE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void driveModeMenu() {
    int option, value;
    int values[MAX_NUM];
    driveModeControlFunction dc;

    printf("Drive mode Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter drive mode (0=Eco, 1=Sports, 2=Normal): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("DRIVE_MODE", values, ONE);

            // Set the drive mode control function
            if (value == 0) {
                dc = ecoMode;
            } else if (value == 1) {
                dc = sportsMode;
            } else {
                dc = normalMode;
            }

            // Execute the drive mode function
            printf("****************************\n");
            driveModeControl(dc);
            registerHandler(DRIVE_MODE, dc);
            // Notify the event
            handlerEvent(DRIVE_MODE);
            unregisterHandler(DRIVE_MODE, dc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("DRIVE_MODE", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void tractionMenu() {
    int option, value;
    int values[MAX_NUM];
    tractionControlFunction tc;

    printf("TRACTION Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter traction state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("TRACTION_CONTROL", values, ONE);

            // Set the traction control function
            if (value == 0) {
                tc = tractionOff;
            } else {
                tc = tractionOn;
            }

            // Execute the traction control function
            printf("****************************\n");
            tractionControl(tc);
            registerHandler(TRACTION_CONTROL, tc);
            // Notify the event
            handlerEvent(TRACTION_CONTROL);
            unregisterHandler(TRACTION_CONTROL, tc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("TRACTION_CONTROL",ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void heatedSeatMenu() {
    int option, seatId, heatLevel;
    int values[MAX_NUM];
    heatSeatControlFunction hc;
    HseatStatus status;

    printf("HEATED SEATS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter seat identifier (0 = Driver, 1 = Passenger): ");
            if (scanf("%d", &seatId) != 1 || (seatId < 0 || seatId > 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            printf("Enter heat level (0-3): ");
            if (scanf("%d", &heatLevel) != 1 || (heatLevel < 0 || heatLevel > 3)) {
                printf("Invalid input. Enter a value between 0 and 3.\n");
                return;
            }

            // Set the heated seat status
            status.seatId = seatId;
            status.heatLevel = heatLevel;

            values[0] = seatId;
            values[1] = heatLevel;
            writeOrUpdateValueToFile("HEATED_SEATS", values, 2);
            
            // Use a wrapper to pass the changed value of the structure
            adjustHeatedSeat(status);
            printf("****************************\n");
            hc = heatedSeatHandlerWrapper;

            // register handler
            registerHandler(HEATED_SEATS, hc);

            // Notify the event
            handlerEvent(HEATED_SEATS);

            // Unregister the handler
            unregisterHandler(HEATED_SEATS, hc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("HEATED_SEATS",2);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void cooledSeatMenu() {
    int option, seatId, coolLevel;
    int values[MAX_NUM];
    coolSeatControlFunction cc;
    CseatStatus status;

    printf("COOLED SEATS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter seat identifier (0 = Driver, 1 = Passenger): ");
            if (scanf("%d", &seatId) != 1 || (seatId < 0 || seatId > 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            printf("Enter cool level (0-3): ");
            if (scanf("%d", &coolLevel) != 1 || (coolLevel < 0 || coolLevel > 3)) {
                printf("Invalid input. Enter a value between 0 and 3.\n");
                return;
            }

            // Set the heated seat status
            status.seatId = seatId;
            status.coolLevel = coolLevel;

            values[0] = seatId;
            values[1] = coolLevel;
            writeOrUpdateValueToFile("COOLED_SEATS", values, 2);
            
            // Use a wrapper to pass the changed value of the structure
            adjustCooledSeat(status);
            printf("****************************\n");
            cc = cooledSeatHandlerWrapper;

            // register handler
            registerHandler(COOLED_SEATS, cc);

            // Notify the event
            handlerEvent(COOLED_SEATS);

            // Unregister the handler
            unregisterHandler(COOLED_SEATS, cc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("COOLED_SEATS",TWO);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void steeringMenu() {
    int option, value;
    int values[MAX_NUM];

    steeringControlFunction sc;

    printf("Steering Adjust Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter Steering Adjust (0=Up, 1=Down, 2=In, 3=Out): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2 && value != 3)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            values[0] = value;
            // Perform write operation to file if needed
            writeOrUpdateValueToFile("STEERING_ADJUST", values, ONE);

            // Set the steering control function
            if (value == 0) {
                sc = upSteering;
            } else if (value == 1) {
                sc = downSteering;
            } else if (value == 2) {
                sc = inSteering;
            } else {
                sc = outSteering;
            }

            // Execute the traction control function
            printf("****************************\n");
            steeringControl(sc);
            registerHandler(STEERING_ADJUST, sc);
            // Notify the event
            handlerEvent(STEERING_ADJUST);
            unregisterHandler(STEERING_ADJUST, sc);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            // Implement event listening functionality if needed
            printCurrentValues("STEERING_ADJUST", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }

}

void interiorLightMenu() {
    int option, value;
    int values[MAX_NUM];
    interiorLightControlFunction ic;

    printf("Interior Light Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter interior light state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            values[0] = value;
            writeOrUpdateValueToFile("INTERIOR_LIGHT", values, ONE);

            // Set the traction control function
            if (value == 0) {
                ic = offInteriorLight;
            } else {
                ic = onInteriorLight;
            }

            // Execute the interior light function
            printf("****************************\n");
            interiorLightControl(ic);
            registerHandler(INTERIOR_LIGHT, ic);
            // Notify the event
            handlerEvent(INTERIOR_LIGHT);
            unregisterHandler(INTERIOR_LIGHT, ic);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            printCurrentValues("INTERIOR_LIGHT", ONE);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}