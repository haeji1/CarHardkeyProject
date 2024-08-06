all: main.exe
	./main.exe

main.exe: main.o observer.o ignition.o horn.o display.o sunroof.o drive.o steering.o interior.o traction.o menu.o pbrake.o
	gcc -o main.exe main.o observer.o ignition.o horn.o display.o sunroof.o drive.o steering.o interior.o traction.o menu.o pbrake.o
main.o: main.c observer.h ignition.h horn.h display.h sunroof.h drive.h steering.h interior.h traction.h menu.h pbrake.h
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

pbrake.o: pbrake.c observer.h pbrake.h
	gcc -c pbrake.c

steering.o: steering.c observer.h steering.h
	gcc -c steering.c

interior.o: interior.c observer.h interior.h
	gcc -c interior.c

traction.o: traction.c observer.h traction.h
	gcc -c traction.c

menu.o: menu.c observer.h menu.h
	gcc -c menu.c

clean:
	rm -f *.o main.exe