//
// Created by MinseokK on 24. 8. 8.
//

#ifndef DOORLOCK_H
#define DOORLOCK_H

typedef void(*DoorLockControlFunction)();


void DoorLock();
void DoorUnlock();
void handleDoorLock(DoorLockControlFunction);

#endif //DOORLOCK_H
