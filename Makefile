all: main.exe
	./main.exe

main.exe: main.o observer.o
	gcc -o main.exe main.o observer.o

main.o: main.c observer.h
	gcc -c main.c

observer.o: observer.c observer.h
	gcc -c observer.c