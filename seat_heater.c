// #include <stdio.h>
// #include "seat_heater.h"

// //0driver 1passenger
// //(0~3)heating level

//          // 0 for Driver, 1 for Passenger
//         // 0-3



// void setSeatHeater(int seatId, int heatLevel) {
//     const char* seat = (seatId == 0) ? "Driver" : "Passenger";
//     printf("Seat Heater: %s seat, Heat Level %d\n", seat, heatLevel);
// }
// #include <stdio.h>
// #include "seat_heater.h"

// // Define global variables to store seat heater settings
// static int seatId = -1;    // 0 for Driver, 1 for Passenger
// static int heatLevel = -1; // 0-3

// // Define a function to handle seat heater actions
// void seatHeaterHandler(void) {
//     if (seatId == 0) {
//         printf("Seat Heater: Driver seat, Heat Level %d\n", heatLevel);
//     } else if (seatId == 1) {
//         printf("Seat Heater: Passenger seat, Heat Level %d\n", heatLevel);
//     } else {
//         printf("Invalid seat identifier.\n");
//     }
// }

// // Set the seat heater settings
// void setSeatHeater(int id, int level) {
//     if (id < 0 || id > 1 || level < 0 || level > 3) {
//         printf("Invalid seat identifier or heat level.\n");
//         return;
//     }
//     seatId = id;
//     heatLevel = level;
//     printf("Seat Heater settings updated.\n");
// }
