all: main.exe
	./main.exe

main.exe: main.o observer.o ignition.o horn.o display.o sunroof.o drive.o
	gcc -o main.exe main.o observer.o ignition.o horn.o display.o sunroof.o drive.o
main.o: main.c observer.h ignition.h horn.h display.h sunroof.h drive.h
	gcc -c main.c

observer.o: observer.c observer.h
	gcc -c observer.c

display.o: display.c observer.h display.h
	gcc -c display.c

ignition.o: ignition.c observer.h ignition.h
	gcc -c ignition.c
	
horn.o: horn.c observer.h horn.h
	gcc -c horn.c

sunroof.o: sunroof.c observer.h sunroof.h
	gcc -c sunroof.c

drive.o: drive.c observer.h drive.h
	gcc -c drive.c