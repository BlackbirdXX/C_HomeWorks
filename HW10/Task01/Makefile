all: task1

task1: main.o function.o 
	gcc -o task1 main.o function.o

main.o: main.c 
	gcc -c -o main.o main.c

function.o: function.c function.h
	gcc -c -o function.o function.c

clean:
	del *.o
	del task1.exe
	