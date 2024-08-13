# Compiler
CC = gcc

# Executable file name
TARGET = main.exe

# Source files
SRCS = main.c observer\observer.c domain\ignition.c domain\horn.c domain\headlights.c domain\turnsignals.c \
       domain\windshield.c domain\hazard.c domain\cruise.c domain\radio_volume.c domain\radio_tuning.c \
       domain\display.c domain\trunk.c domain\steering.c domain\sunroof.c domain\traction.c domain\pbrake.c \
       domain\menu.c domain\interior.c domain\drive.c domain\fuel.c domain\hseat.c domain\cseat.c \
       domain\auto_hold.c domain\hud_Adjust.c domain\glove_box_release.c domain\fog_lights.c \
       domain\emergency_brake.c domain\trailer_control.c domain\hands_free.c domain\seat_heater.c \
       domain\seat_cooler.c domain\radioSource.c domain\climateAirflow.c domain\climateFan.c domain\climateTemp.c \
       domain\defrost.c domain\doorLock.c domain\mirrorAdjust.c domain\powerWindows.c domain\windowLock.c \
       domain\seatAdjust.c

# Object files
OBJS = $(SRCS:.c=.o)

# Include directory (optional, currently commented out)
INCLUDES = -Iheader -Iobserver -I.

# Build all and execute
all: $(TARGET)
	./$(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@
       
# Clean up
clean:
	del /Q $(OBJS) $(TARGET)