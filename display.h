#ifndef DISPLAY_H
#define DISPLAY_H

void displayMenu();

void handleHornCommands();
void handleRadioSourceCommands();
void handleClimateTempCommands();
void handleClimateFanCommands();
void handleClimateAirflowCommands();
void handleDefrostCommands();
void handlePowerWindowsCommands();
void handleWindowLockCommands();
void handleDoorLockCommands();
void handleMirrorAdjustCommands();
void handleSeatAdjustCommands();
void initializeFeatureHandlers();
void cleanupFeatureHandlers();

#endif // DISPLAY_H