# Compiler
CC = gcc

# Executable file name
TARGET = main.exe

# Source files
SRCS = main.c observer.c ignition.c horn.c headlights.c turnsignals.c windshield.c \
       hazard.c cruise.c radio_volume.c radio_tuning.c display.c trunk.c steering.c \
       sunroof.c traction.c pbrake.c menu.c interior.c drive.c fuel.c hseat.c cseat.c \
       auto_hold.c hud_Adjust.c glove_box_release.c fog_lights.c emergency_brake.c \
       trailer_control.c hands_free.c seat_heater.c seat_cooler.c RadioSource.c \
       ClimateAirflow.c ClimateFan.c ClimateTemp.c Defrost.c DoorLock.c MirrorAdjust.c \
       PowerWindows.c WindowLock.c SeatAdjust.c

# Object files
OBJS = $(SRCS:.c=.o)

# Build all and execute
all: $(TARGET)
	./$(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Compile .c files to .o files
%.o: %.c
	$(CC) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)