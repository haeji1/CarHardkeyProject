#ifndef SEAT_COOLER_H
#define SEAT_COOLER_H

// Define the structure to hold seat cooler configuration
typedef struct {
    int seatId;      // 0 for Driver, 1 for Passenger
    int coolLevel;   // Cooling level from 0 to 3
} seatCoolerConfig;

typedef void (*seatCoolerFunction)(int);

void seatIdentifierDriverCooler(int coolLevel);
void seatIdentifierPassengerCooler(int coolLevel);
void setSeatCooler(seatCoolerFunction scf, const seatCoolerConfig *config);
void seatCoolerHandlerWrapper();

#endif // SEAT_COOLER_H
