//
// Created by MinseokK on 24. 8. 3.
//

typedef void(*handlePowerWindowsControlFunction)();
int Up();
int Down();
void handlePowerWindows(handlePowerWindowsControlFunction *pwcf);

