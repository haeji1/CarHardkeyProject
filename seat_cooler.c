#include <stdio.h>
#include "seat_cooler.h"

// Global variable to keep track of seat cooler status
seatCoolerConfig globalCseatStatus;

// Functions for seat cooler control
void seatIdentifierDriverCooler(int coolLevel) {
    globalCseatStatus.seatId = 0;
    globalCseatStatus.coolLevel = coolLevel;
}

void seatIdentifierPassengerCooler(int coolLevel) {
    globalCseatStatus.seatId = 1;
    globalCseatStatus.coolLevel = coolLevel;
}

// Set the seat cooler based on configuration
void setSeatCooler(seatCoolerFunction scf, const seatCoolerConfig *config) {
    printf("Setting seat cooler...\n");
    scf(config->coolLevel);  // Call the appropriate function with the cool level
}

// Function wrapper for event handling
void seatCoolerHandlerWrapper() {
    const char *seatName = (globalCseatStatus.seatId == 0) ? "Driver" : "Passenger";
    printf("\nSeat %s cool level set to %d\n", seatName, globalCseatStatus.coolLevel);
}
