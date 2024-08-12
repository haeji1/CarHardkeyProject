//
// Created by MinseokK on 24. 8. 8.
//

#ifndef WINDOWLOCK_H
#define WINDOWLOCK_H
typedef void(*WindowLockControlFunction)();


void WindowLock();
void WindowUnlock();
void handleWindowLock(WindowLockControlFunction);
#endif //WINDOWLOCK_H
