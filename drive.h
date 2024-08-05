#ifndef DRIVE_H
#define DRIVE_H

void initializeDriveModeHandlers();
void executeDriveModeOperation(int operation);

// Define function pointer type for drive mode
typedef void (*DriveModeOperation)();

#endif