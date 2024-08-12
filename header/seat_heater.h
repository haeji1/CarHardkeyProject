#ifndef SEAT_HEATER_H
#define SEAT_HEATER_H

// Define the structure to hold seat heater configuration
typedef struct {
    int seatId;      // 0 for Driver, 1 for Passenger
    int heatLevel;   // Heating level from 0 to 3
} seatHeaterConfig;

// Function pointer type for seat heater functions
typedef void (*seatHeaterFunction)(int);

// Function prototypes
void seatIdentifierDriver(int heatLevel);
void seatIdentifierPassenger(int heatLevel);
void setSeatHeater(seatHeaterFunction shf, const seatHeaterConfig *config);
void seatHeaterHandlerWrapper();


#endif // SEAT_HEATER_H
