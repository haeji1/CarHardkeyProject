all: main.exe
	./main.exe

main.exe: main.o observer.o ignition.o horn.o headlights.o turnsignals.o windshield.o display.o
	gcc -o main.exe main.o observer.o ignition.o horn.o headlights.o turnsignals.o windshield.o display.o

main.o: main.c observer.h ignition.h horn.h headlights.h turnsignals.h windshield.h display.h
	gcc -c main.c

observer.o: observer.c observer.h
	gcc -c observer.c

display.o: display.c observer.h display.h
	gcc -c display.c

ignition.o: ignition.c observer.h ignition.h
	gcc -c ignition.c
	
horn.o: horn.c observer.h horn.h
	gcc -c horn.c

headlights.o: headlights.c observer.h headlights.h
	gcc -c headlights.c

turnsignals.o: turnsignals.c observer.h turnsignals.h
	gcc -c turnsignals.c

windshield.o: windshield.c observer.h windshield.h
	gcc -c windshield.c