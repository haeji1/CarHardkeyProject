//
// Created by MinseokK on 24. 8. 8.
//

#ifndef POWERWINDOWS_H
#define POWERWINDOWS_H

typedef struct{
    int windowId; // 0/1/2/3
    int Action; // 0/ 1
} WindowState;

WindowState globalWindowState;
typedef void(*handlePowerWindowsControlFunction)();
void adjustPowerWindows(WindowState State);
void windowsjustHandlerWrapper();
void handlePowerWindows(handlePowerWindowsControlFunction);
#endif //POWERWINDOWS_H
