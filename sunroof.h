#ifndef SUNROOF_H
#define SUNROOF_H

void initializeSunroofHandlers();
void executeSunroofOperation(int opration);

// Define function pointer type for sunroof operations (strategy pattern)
typedef void (*SunroofOperation)();

#endif