CC = gcc
CFLAGS = -Wall -g

TARGET = main.exe

all: $(TARGET)

$(TARGET): main.o observer.o ignition.o display.o \
		   hud_adjust.o glove_box_release.o fog_lights.o \
           emergency_brake.o trailer_control.o auto_hold.o \
           hands_free.o seat_heater.o seat_cooler.o menu.o
	$(CC) -o $(TARGET) main.o observer.o ignition.o display.o \
	    hud_adjust.o glove_box_release.o fog_lights.o \
	    emergency_brake.o trailer_control.o auto_hold.o \
	    hands_free.o seat_heater.o seat_cooler.o menu.o


main.o: main.c observer.h ignition.h display.h hud_adjust.h \
        glove_box_release.h fog_lights.h emergency_brake.h \
        trailer_control.h auto_hold.h hands_free.h seat_heater.h \
        seat_cooler.h menu.h
	$(CC) $(CFLAGS) -c main.c

observer.o: observer.c observer.h
	$(CC) $(CFLAGS) -c observer.c

display.o: display.c observer.h display.h
	$(CC) $(CFLAGS) -c display.c

ignition.o: ignition.c observer.h ignition.h
	$(CC) $(CFLAGS) -c ignition.c

hud_adjust.o: hud_adjust.c observer.h hud_adjust.h
	$(CC) $(CFLAGS) -c hud_adjust.c

glove_box_release.o: glove_box_release.c observer.h glove_box_release.h
	$(CC) $(CFLAGS) -c glove_box_release.c

fog_lights.o: fog_lights.c observer.h fog_lights.h
	$(CC) $(CFLAGS) -c fog_lights.c

emergency_brake.o: emergency_brake.c observer.h emergency_brake.h
	$(CC) $(CFLAGS) -c emergency_brake.c

trailer_control.o: trailer_control.c observer.h trailer_control.h
	$(CC) $(CFLAGS) -c trailer_control.c

auto_hold.o: auto_hold.c observer.h auto_hold.h
	$(CC) $(CFLAGS) -c auto_hold.c

hands_free.o: hands_free.c observer.h hands_free.h
	$(CC) $(CFLAGS) -c hands_free.c

seat_heater.o: seat_heater.c observer.h seat_heater.h
	$(CC) $(CFLAGS) -c seat_heater.c

seat_cooler.o: seat_cooler.c observer.h seat_cooler.h
	$(CC) $(CFLAGS) -c seat_cooler.c

menu.o: menu.c observer.h menu.h
	$(CC) $(CFLAGS) -c menu.c

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
