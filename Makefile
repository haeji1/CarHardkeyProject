# Compiler
CC = gcc

# Executable file name
TARGET = main.exe

# Source files
SRCS = domain/main.c observer/observer.c domain/ignition.c domain/horn.c domain/headlights.c domain/turnsignals.c \
       domain/windshield.c domain/hazard.c domain/cruise.c domain/radio_volume.c domain/radio_tuning.c \
       domain/display.c domain/trunk.c domain/steering.c domain/sunroof.c domain/traction.c domain/pbrake.c \
       domain/menu.c domain/interior.c domain/drive.c domain/fuel.c domain/hseat.c domain/cseat.c \
       domain/auto_hold.c domain/hud_Adjust.c domain/glove_box_release.c domain/fog_lights.c \
       domain/emergency_brake.c domain/trailer_control.c domain/hands_free.c domain/seat_heater.c \
       domain/seat_cooler.c domain/RadioSource.c domain/ClimateAirflow.c domain/ClimateFan.c domain/ClimateTemp.c \
       domain/Defrost.c domain/DoorLock.c domain/MirrorAdjust.c domain/PowerWindows.c domain/WindowLock.c \
       domain/SeatAdjust.c

# Object files
OBJS = $(SRCS:.c=.o)

# Include directory (optional, currently commented out)
INCLUDES = -Iheader -Iobserver

# Build all and execute
all: $(TARGET)
	./$(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Compile .c files to .o files
# %.o: %.c
# 	$(CC) -I. -c $< -o $@
%.o: %.c
	$(CC) -I. -c $< -o $@
# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
