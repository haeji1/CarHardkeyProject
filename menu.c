#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "ignition.h"
#include "horn.h"
#include "headlights.h"
#include "turnsignals.h"
#include "windshield.h"
#include "hazard.h"
#include "cruise.h"
#include "radioVolume.h"
#include "radioTuning.h"
#include "sunroof.h"
#include "trunk.h"
#include "fuel.h"
#include "drive.h"
#include "traction.h"
#include "observer.h"
#include "steering.h"
#include "interior.h"
#include "pbrake.h"
#include "hseat.h"
#include "cseat.h"
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
#include "auto_hold.h"
#include "fog_lights.h"
#include "seat_heater.h"
#include "seat_cooler.h"
#include "trailer_control.h"
#include "hands_free.h"
#include "hud_Adjust.h"
#include "glove_box_release.h"
#include "emergency_brake.h"
#include "file.c"


#define MAX_NUM 5
#define ONE 1
#define TWO 2


void ignitionMenu() {
    int option, value;
    int values[MAX_NUM];
    ignitionFunction igFunc;

    printf("IGNITION Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter ignition state (1=On): ");
            if (scanf("%d", &value) != 1 || (value != 1)) {
                printf("Invalid input. Enter 1.\n");
                break;
            }

            // Perform write operation to file if needed
            values[0] = value;
            writeOrUpdateValueToFile("IGNITION", values, ONE);

            // Set the ignition function
            if (value == 1) {
                igFunc = onIgnition;
                ignitionStarted = value;
                printf("IGNITION ON\n");
            }

            // Execute the ignition function
            ignition(igFunc);

            registerHandler(IGNITION, igFunc);

            // Notify the event
            handlerEvent(IGNITION);

            return;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("IGNITION", ONE);
            ignitionStarted = getNumValues("IGNITION", ONE);

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

            // Execute the head lights function
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

            // Execute the turn signals function
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

void windshieldWipersMenu(){
    int option, value;
    windshieldWipersControlFunction wc;

    printf("WINDSHIELD_WIPERS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter windshield wipers state (0=Off, 1=Low, 2=High): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1 && value != 2)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("WINDSHIELD_WIPERS", value);

            // Set the windshield wipers control function
            if (value == 0) {
                wc = offWindshieldWipers;
            } else if (value == 1) {
                wc = lowWindshieldWipers;
            } else {
                wc = highWindshieldWipers;
            }

            // Execute the windshield wipers function
            windshieldWipersControl(wc);
            registerHandler(WINDSHIELD_WIPERS, wc);
            // Notify the event
            handlerEvent(WINDSHIELD_WIPERS);
            unregisterHandler(WINDSHIELD_WIPERS, wc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("WINDSHIELD_WIPERS");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }

}

void hazardLightsMenu(){
    int option, value;
    hazardLightsControlFunction hc;

    printf("HAZARD_LIGHTS Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter turn signals state (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 || (value != 0 && value != 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            // Perform write operation to file if needed
            // writeOrUpdateValueToFile("HAZARD_LIGHTS", value);

            // Set the hazard lights control function
            if (value == 0) {
                hc = offHazardLights;
                
            } else {
                hc = onHazardLights;
            }

            // Execute the hazard lights control function
            hazardLightsControl(hc);
            registerHandler(HAZARD_LIGHTS, hc);
            // Notify the event
            handlerEvent(HAZARD_LIGHTS);
            unregisterHandler(HAZARD_LIGHTS, hc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            // listenToEvents("HAZARD_LIGHTS");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }

}

void cruiseControlMenu() {
    int option, state, speed;
    int values[MAX_NUM];
    cruiseControlFunction cc;
    CruiseControlState cruiseControlState;

    printf("CRUISE_CONTROL Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
            printf("Enter cruise control state (0 = Off, 1 = On): ");
            if (scanf("%d", &state) != 1 || (state < 0 || state > 1)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            printf("Enter speed in cruise control (30-150): ");
            if (scanf("%d", &speed) != 1 || (speed < 30 || speed > 150)) {
                printf("Invalid input. Enter a value between 30 and 150.\n");
                return;
            }

            // Set the cruise control status
            cruiseControlState.cruiseState = state;
            //speed = getNumValues("CRUISE_CONTROL", TWO);
            cruiseControlState.speed = speed;

            values[0] = state;
            values[1] = speed;
            writeOrUpdateValueToFile("CRUISE_CONTROL", values, TWO);
            
            //Set the cruise control function
            if (state == 0) {
                cc = deactivateCruiseControl;
            } else {
                cc = activateCruiseControl;
                //adjustCruiseControlSpeed(cc);
                //cc = setCruiseControlSpeed;
            }

            //CruiseControlState cs = cruiseControlAction(cc, &cruiseControlState);
            
            // register handler
            registerHandler(CRUISE_CONTROL, (Handler)cc);

            // Notify the event
            handlerEvent(CRUISE_CONTROL);

            // Unregister the handler
            unregisterHandler(CRUISE_CONTROL, (Handler)cc);
            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("CRUISE_CONTROL", TWO);
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void radioVolumeMenu(){
    int mainOption,subOption, value;
    int values[MAX_NUM];
    radioVolumeFunction rvFunc;

    printf("RADIO_VOLUME Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &mainOption) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (mainOption) {
        case 1:
            // Suboption for volume setting
            printf("Volume Settings:\n");
            printf("1. Set volume\n");
            printf("2. Increase volume\n");
            printf("3. Decrease volume\n");
            printf("Enter your choice: ");
            if (scanf("%d", &subOption) != 1) {
                printf("Invalid input. Returning to menu.\n");
                return;
            }

            switch (subOption) {
                case 1:
                    printf("Enter volume level (0-100): ");
                    if (scanf("%d", &value) != 1 || (value < 0 || value > 100)) {
                        printf("Invalid input. Enter a value between 0 and 100.\n");
                        return;
                    }
                    rvFunc = setRadioVolume;
                    radioVolumeControl(rvFunc, value);
                    values[0] = value;
                    writeOrUpdateValueToFile("RADIO_VOLUME", values, ONE);
                    break;

                case 2:
                    printf("Enter amount to increase volume by: ");
                    if (scanf("%d", &value) != 1 || value < 0) {
                        printf("Invalid input. Enter a positive value.\n");
                        return;
                    }
                    rvFunc = increaseRadioVolume;
                    radioVolumeControl(rvFunc, value);
                    values[0] = value;
                    writeOrUpdateValueToFile("RADIO_VOLUME", values, ONE);
                    break;

                case 3:
                    printf("Enter amount to decrease volume by: ");
                    if (scanf("%d", &value) != 1 || value < 0) {
                        printf("Invalid input. Enter a positive value.\n");
                        return;
                    }
                    rvFunc = decreaseRadioVolume;
                    radioVolumeControl(rvFunc, value);
                    values[0] = value;
                    writeOrUpdateValueToFile("RADIO_VOLUME", values, ONE);
                    break;

                default:
                    printf("Invalid choice. Returning to menu.\n");
                    break;
            }
            break;

            // Execute the radio volume function
            registerHandler(RADIO_VOLUME, (Handler)rvFunc);

            // Notify the event
            handlerEvent(RADIO_VOLUME);
            unregisterHandler(RADIO_VOLUME, (Handler)rvFunc);

            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("RADIO_VOLUME", ONE);
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void radioTuningMenu(){
    int mainOption,subOption, value;
    int values[MAX_NUM];
    radioTuningFunction rtFunc;

    printf("RADIO_TUNING Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");
    if (scanf("%d", &mainOption) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (mainOption) {
        case 1:
            // Suboption for frequency setting
            printf("Radio freqency Settings:\n");
            printf("1. Set specific frequency\n");
            printf("2. Increase frequency\n");
            printf("3. Decrease frequency\n");
            printf("Enter your choice: ");
            if (scanf("%d", &subOption) != 1) {
                printf("Invalid input. Returning to menu.\n");
                return;
            }
            
            int originFrequency = getNumValues("RADIO_TUNING", ONE);

            switch (subOption) {
                case 1:
                    printf("Enter radio frequency (3-1605): ");
                    if (scanf("%d", &value) != 1 || (value < 3 || value > 1605)) {
                        printf("Invalid input. Enter a value between 3 and 1605.\n");
                        return;
                    }
                    rtFunc = setRadioTuning;
                    radioTuningControl(rtFunc, value);
                    values[0] = value;
                    writeOrUpdateValueToFile("RADIO_TUNING", values, ONE);
                    break;

                case 2:
                    printf("Enter amount to increase frequency by: ");
                    if (scanf("%d", &value) != 1 || value < 0) {
                        printf("Invalid input. Enter a positive value.\n");
                        return;
                    }
                    rtFunc = increaseRadioTuning;
                    radioTuningControl(rtFunc, value);
                    if(originFrequency + value <= 1605){
                        values[0] = originFrequency + value;
                    }else{
                        values[0] = 1605;
                    }
                    writeOrUpdateValueToFile("RADIO_TUNING", values, ONE);
                    break;

                case 3:
                    printf("Enter amount to decrease frequency by: ");
                    if (scanf("%d", &value) != 1 || value < 0) {
                        printf("Invalid input. Enter a positive value.\n");
                        return;
                    }
                    rtFunc = decreaseRadioTuning;
                    radioTuningControl(rtFunc, value);
                    //int originFrequency = getNumValues("RADIO_TUNING", ONE);
                    if(originFrequency - value >= 3) {
                        values[0] = originFrequency - value;
                    } else{
                        values[0] = 3;
                    }
                    writeOrUpdateValueToFile("RADIO_TUNING", values, ONE);
                    break;

                default:
                    printf("Invalid choice. Returning to menu.\n");
                    break;
            }
            break;

            // Execute the radio volume function
            registerHandler(RADIO_TUNING, (Handler)rtFunc);

            // Notify the event
            handlerEvent(RADIO_TUNING);
            unregisterHandler(RADIO_TUNING, (Handler)rtFunc);

            break;

        case 2:
            printf("Listening to events...\n");
            // Implement event listening functionality if needed
            printCurrentValues("RADIO_TUNING", ONE);
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
        if (scanf("%d", &value) != 1 || (value < 0 || value > 2)) {
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
        if (scanf("%d", &value) != 1 || (value < 0 || value > 2)) {
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
            if (scanf("%d", &windowId) != 1 || (windowId < 0 || windowId > 3)) {
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
            printf("****************************************\n"); // 0/1/2
            if (scanf("%d", &adjustType) != 1 || (adjustType < 0 || adjustType > 2)) {
                        // 0 != 0 F / 1 != 1 F / 2 != 2 F/
                printf("Invalid input. Enter a value between 0 and 2.\n");
            return;
            }

            // Adjust Value 1~3
            printf("****************************************\n");
            printf("Enter Adjust Value (1 = level_1, 2 = level_2, 3 = level_3): \n");
            printf("            Enter your choice: \n");
            printf("****************************************\n");
            // 1 / 2 / 3
            if (scanf("%d", &adjustValue) !=1 || (adjustValue < 1 || adjustValue > 3)){
                // 1 != 1 F / 2 != 2
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
void fogLightsMenu(){
    int option, value;
    int values[MAX_NUM];
    fogLightFunction flf;

    printf("Ac: \n");
    printf("1. Fog Light mode\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:
            printf("Enter Fog Light State (0=Off, 1=On): ");
            if (scanf("%d", &value) != 1 && (value != 0)) {
                printf("Invalid input. Enter 0 or 1.\n");
                return;
            }

            values[0] = value;
            writeOrUpdateValueToFile("FOG_LIGHTS", values, 1);

            if (value == 0) {
                flf = fogLightsOff;
            } else {
                flf = fogLightsOn;
            }
			printf("****************************\n");
            setFogLights(flf);
            registerHandler(FOG_LIGHTS, flf);
            handlerEvent(FOG_LIGHTS);
            unregisterHandler(FOG_LIGHTS, flf);
            printf("****************************\n");
            break;

        case 2:
            printf("**********Listening to events***********\n");
            printCurrentValues("FOG_LIGHTS", 1);
            printf("****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void seatHeaterMenu() {
    int option, seatId, heatLevel;
    int values[2];
    seatHeaterFunction shf;
    seatHeaterConfig config;

    printf("Seat Heater Menu:\n");
    printf("1. Set and Save Seat Heater Configuration\n");
    printf("2. Listen to Events\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    switch (option) {
        case 1:
            // Collect input for seat configuration
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

            // Set the seat heater configuration
            config.seatId = seatId;
            config.heatLevel = heatLevel;

            values[0] = seatId;
            values[1] = heatLevel;
            writeOrUpdateValueToFile("SEAT_HEATER", values, 2);

            // Choose the function pointer based on seat identifier
            if (seatId == 0) {
                shf = seatIdentifierDriver;
            } else {
                shf = seatIdentifierPassenger;
            }

            // Apply the seat heater configuration
			printf("****************************\n");
			setSeatHeater(shf, &config);
            registerHandler(SEAT_HEATER, seatHeaterHandlerWrapper);
            handlerEvent(SEAT_HEATER);
            unregisterHandler(SEAT_HEATER, seatHeaterHandlerWrapper);
			printf("****************************\n");

            break;

        case 2:
            printf("\n********** Listening to Events **********\n");
            // Print the current seat heater configuration from the file
            printCurrentValues("SEAT_HEATER", 2);
            printf("*******************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void seatCoolerMenu() {
    int option, seatId, coolLevel;
    int values[2];
    seatCoolerFunction scf;
    seatCoolerConfig config;

    printf("Seat Cooler Menu:\n");
    printf("1. Set and Save Seat Cooler Configuration\n");
    printf("2. Listen to Events\n");
    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    switch (option) {
        case 1:
            // Collect input for seat cooler configuration
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

            // Set the seat cooler configuration
            config.seatId = seatId;
            config.coolLevel = coolLevel;

            values[0] = seatId;
            values[1] = coolLevel;
            writeOrUpdateValueToFile("SEAT_COOLER", values, 2);

            // Choose the function pointer based on seat identifier
            if (seatId == 0) {
                scf = seatIdentifierDriverCooler;
            } else {
                scf = seatIdentifierPassengerCooler;
            }

            // Apply the seat cooler configuration
            printf("****************************\n");
			setSeatCooler(scf, &config);
            registerHandler(SEAT_COOLER, seatCoolerHandlerWrapper);
            handlerEvent(SEAT_COOLER);
            unregisterHandler(SEAT_COOLER, seatCoolerHandlerWrapper);
			printf("****************************\n");
            break;

        case 2:
            printf("********** Listening to Events **********\n");
            // Print the current seat cooler configuration from the file
            printCurrentValues("SEAT_COOLER", 2);
            printf("*****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            break;
    }
}

void trailerControlMenu(){
    int option, value;
    int values[MAX_NUM];
    trailerControlFunction tcf;

    printf("Trailer Control Menu: \n");
    printf("1. Activate Trailer Control\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("TRAILER_CONTROL", values, 1);

			printf("****************************\n");
            tcf = controlTrailer;
            registerHandler(TRAILER_CONTROL, tcf);
            handlerEvent(TRAILER_CONTROL);
            unregisterHandler(TRAILER_CONTROL, tcf);
			printf("****************************\n");
			break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("TRAILER_CONTROL", 1);
            printf("*****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

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


void handsFreeMenu(){
    int option, value;
    int values[MAX_NUM];
    handsFreeFunction hff;

    printf("Hands Free Menu: \n");
    printf("1. Enter '1' to Hands Free mode \n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("HANDS_FREE", values, 1);

			printf("****************************\n");
            hff = activateHandsFree;
            registerHandler(HANDS_FREE, hff);
            handlerEvent(HANDS_FREE);
            unregisterHandler(HANDS_FREE, hff);
            printf("****************************\n");
            break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("HANDS_FREE", 1);
            printf("*****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }
void hudAdjustMenu(){
    int option, value;
    int values[MAX_NUM];
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
            values[0] = 1;
            writeOrUpdateValueToFile("HUD_ADJUST", values, 1);

			printf("****************************\n");
            haf = adjustHUDSettings;
            registerHandler(HUD_ADJUST, haf);
            handlerEvent(HUD_ADJUST);
            unregisterHandler(HUD_ADJUST, haf);
            printf("****************************\n");
            break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("HUD_ADJUST", 1);
            printf("*****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }
void gloveBoxReleaseMenu(){
    int option, value;
    int values[MAX_NUM];
    GloveBoxReleaseFunction gbr;

    printf("Glove Box Release Menu: \n");
    printf("1. Open The Glove Box Latch \n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("GLOVE_BOX_RELEASE", values, 1);

			printf("****************************\n");
            gbr = releaseGloveBox;
            registerHandler(GLOVE_BOX_RELEASE, gbr);
            handlerEvent(GLOVE_BOX_RELEASE);
            unregisterHandler(GLOVE_BOX_RELEASE, gbr);
            printf("****************************\n");
            break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("GLOVE_BOX_RELEASE", 1);
            printf("*****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }

void emergencyBrakeMenu(){
    int option, value;
    int values[MAX_NUM];
    emergencyBrakeFunction ebf;

    printf("Emergency Brake Menu: \n");
    printf("1. Enter '1' to Emergency Brake\n");
    printf("2. Listen to event\n");
    if (scanf("%d", &option) != 1){
        printf("Invalid input. Returning to menu.\n");
        return;

    }

    switch (option) {
        case 1:
            values[0] = 1;
            writeOrUpdateValueToFile("EMERGENCY_BRAKE", values, 1);

			printf("****************************\n");
			ebf = activateEmergencyBrake;
            registerHandler(EMERGENCY_BRAKE, ebf);
            handlerEvent(EMERGENCY_BRAKE);
            unregisterHandler(EMERGENCY_BRAKE, ebf);
			printf("****************************\n");
			break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("EMERGENCY_BRAKE", 1);
            printf("*****************************************\n");
            break;

        default:
            printf("Invalid choice. Returning to menu. \n");
            break;
        }
    }



#include "lock_strategy.c"
#include "rear_defrost_strategy.c"
#include "MUTE_BUTTON.c"
#include "VOICE_COMMAND.c"
#include "NAVIGATION.c"
#include "Lane_Support.c"
#include "ParkingAssistance.c"
#include "end_call.c"
#include "answer_call.c"
#include "HILL_DESCENT.c"


void MUTE_BUTTON_MENU(){
    int option, value;
    int values[MAX_NUM];

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
			printf("****************************\n");
            registerHandler(MUTE_BUTTON, muteButtonHandler);
            handlerEvent(MUTE_BUTTON);
            unregisterHandler(MUTE_BUTTON, muteButtonHandler);
			printf("****************************\n");
        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("MUTE_BUTTON", 1);
			sleep(3);
            printf("*****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}

void VOICE_COMMAND_MENU(){

    printf("Steering Adjust Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    int option, value;
    int values[MAX_NUM];

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }


    switch (option) {
        case 1:
			printf("****************************\n");
        registerHandler(VOICE_COMMAND, voiceCommandToggle);
        handlerEvent(VOICE_COMMAND);
        unregisterHandler(VOICE_COMMAND, voiceCommandToggle);
        printf("****************************\n");

        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("VOICE_COMMAND", 1);
			sleep(3);
            printf("*****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void PARKING_ASSIST_MENU(){

    printf("Steering Adjust Menu:\n");
    printf("1. Write value to file\n");
    printf("2. Listen to event\n");
    printf("Enter your choice: ");

    int option, value;
    int values[MAX_NUM];

    if (scanf("%d", &option) != 1) {
        printf("Invalid input. Returning to menu.\n");
        return;
    }

    switch (option) {
        case 1:
			printf("****************************\n");
            registerHandler(PARKING_ASSIST, handleParkingAssistCommand);
            handlerEvent(PARKING_ASSIST);
            unregisterHandler(PARKING_ASSIST, handleParkingAssistCommand);
			printf("****************************\n");
        break;

        case 2:
            printf("********** Listening to Events **********\n");
			printCurrentValues("PARKING_ASSIST", 1);
			sleep(3);
            printf("*****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void REAR_DEFROST_MENU(){
    int option, value;
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
			printf("****************************\n");
            registerHandler(REAR_DEFROST,handleDefrostCommand);
            handlerEvent(REAR_DEFROST);
            unregisterHandler(REAR_DEFROST,handleDefrostCommand);
			printf("****************************\n");
        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("REAR_DEFROST", 1);
			sleep(3);
            printf("*****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}



void CHILD_LOCK_MENU(){

    int option, value;
    int values[MAX_NUM];

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
			printf("****************************\n");
            registerHandler(CHILD_LOCK, handleLockCommand);
            handlerEvent(CHILD_LOCK);
            unregisterHandler(CHILD_LOCK, handleLockCommand);
			printf("****************************\n");
        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("CHILD_LOCK", 1);
			sleep(3);
            printf("*****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void NAVIGATION_MENU(){

    int option, value;
    int values[MAX_NUM];

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
	    printf("****************************\n");
        registerHandler(NAVIGATION, navigatehandle);
        handlerEvent(NAVIGATION);
        unregisterHandler(NAVIGATION, navigatehandle);
        printf("****************************\n");

        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("NAVIGATION", 2);
			sleep(3);
            printf("*****************************************\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}


void LANE_ASSIST_MENU(){

    int option, value;
    int values[MAX_NUM];

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
			printf("****************************\n");
            registerHandler(LANE_ASSIST, handleLaneSupportCommand);
            handlerEvent(LANE_ASSIST);
            unregisterHandler(LANE_ASSIST, handleLaneSupportCommand);
            printf("****************************\n");

        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("LANE_ASSIST", 1);
			sleep(3);
            printf("*****************************************\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
            printCurrentValues("LANE_ASSIST", 1);
        break;
    }

}

void Phone_End_Call_MENU(){ //34
    int option, value;
    int values[MAX_NUM];

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
	    printf("****************************\n");
        registerHandler(PHONE_ANSWER,answerPhone);
        handlerEvent(PHONE_ANSWER);
        unregisterHandler(PHONE_ANSWER,answerPhone);
		printf("****************************\n");
        break;
        case 2:

         printf("********** Listening to Events **********\n");
         printCurrentValues("PHONE_ANSWER", 1);
		 sleep(3);
         printf("*****************************************\n");

        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}

void Phone_Answer_MENU(){
    int option, value;
    int values[MAX_NUM];

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
			printf("****************************\n");
        registerHandler(PHONE_END_CALL,endCall);
        handlerEvent(PHONE_END_CALL);
        unregisterHandler(PHONE_END_CALL,endCall);
			printf("****************************\n");
        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("PHONE_END_CALL", 1);
			sleep(3);
            printf("*****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}

void HILL_DESCENT_MENU(){
    int option, value;
    int values[MAX_NUM];

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
			printf("****************************\n");
        registerHandler(HILL_DESCENT,handleHillDescentCommand);
        handlerEvent(HILL_DESCENT);
        unregisterHandler(HILL_DESCENT,handleHillDescentCommand);
			printf("****************************\n");
        break;

        case 2:
            printf("********** Listening to Events **********\n");
            printCurrentValues("HILL_DESCENT", 1);
			sleep(3);
            printf("*****************************************\n");
        break;

        default:
            printf("Invalid choice. Returning to menu.\n");
        break;
    }

}