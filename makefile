all: main.exe
	./main.exe

main.exe: main.o observer.o ignition.o auto_hold.o emergency_brake.o fog_lights.o glove_box_release.o hands_free.o display.o hud_adjust.o seat_cooler.o display.o seat_heater.o menu.o trailer_control.o
	gcc -o main.exe main.o observer.o ignition.o auto_hold.o emergency_brake.o fog_lights.o glove_box_release.o hands_free.o display.o hud_adjust.o seat_cooler.o seat_heater.o menu.o trailer_control.o


main.o: main.c observer.h ignition.h auto_hold.h emergency_brake.h fog_lights.h glove_box_release.h hands_free.h display.h hud_adjust.h seat_cooler.h display.h seat_heater.h menu.h display.h trailer_control.h
	gcc -c main.c

observer.o: observer.c observer.h
	gcc -c observer.c

display.o: display.c observer.h display.h
	gcc -c display.c

ignition.o: ignition.c observer.h ignition.h
	gcc -c ignition.c
	
auto_hold.o: auto_hold.c observer.h auto_hold.h
	gcc -c auto_hold.c

emergency_brake.o: emergency_brake.c observer.h emergency_brake.h
	gcc -c emergency_brake.c

fog_lights.o: fog_lights.c observer.h fog_lights.h
	gcc -c fog_lights.c

glove_box_release.o: glove_box_release.c observer.h glove_box_release.h
	gcc -c glove_box_release.c

hands_free.o: hands_free.c observer.h hands_free.h 
	gcc -c hands_free.c 

hud_adjust.o: hud_adjust.c observer.h hud_adjust.h 
	gcc -c hud_adjust.c 

seat_cooler.o: seat_cooler.c observer.h seat_cooler.h
	gcc -c seat_cooler.c 

seat_heater.o: seat_heater.c observer.h seat_heater.h 
	gcc -c seat_heater.c

trailer_control.o: trailer_control.c observer.h trailer_control.h 
	gcc -c trailer_control.c

menu.o: menu.c observer.h menu.h
	gcc -c menu.c

clean:
	rm -f *.o main.exe