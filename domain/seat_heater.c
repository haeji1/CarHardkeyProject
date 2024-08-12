#include <stdio.h>
#include "seat_heater.h"

// Global variable to keep track of seat heater status
seatHeaterConfig globalHseatStatus;

// Functions for seat heater control
void seatIdentifierDriver(int heatLevel) {
    globalHseatStatus.seatId = 0;
    globalHseatStatus.heatLevel = heatLevel;
    
}

void seatIdentifierPassenger(int heatLevel) {
    globalHseatStatus.seatId = 1;
    globalHseatStatus.heatLevel = heatLevel;
    
}

// Set the seat heater based on configuration
void setSeatHeater(seatHeaterFunction shf, const seatHeaterConfig *config) {
    printf("Setting seat heater...\n");
    shf(config->heatLevel);  // Call the appropriate function with the heat level
}

// Function wrapper for event handling
void seatHeaterHandlerWrapper() {
    const char *seatName = (globalHseatStatus.seatId == 0) ? "Driver" : "Passenger";
    printf("\nSeat %s heat level set to %d\n", seatName, globalHseatStatus.heatLevel);
}
