//
// Created by MinseokK on 24. 8. 3.
//

typedef void(*handlePowerWindowsControlFunction)(int);
int Up();
int Down();
void handlePowerWindows(handlePowerWindowsControlFunction *pwcf);

