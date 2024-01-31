all: task2

task2: main.o function.o 
	gcc -o task2 main.o function.o

main.o: main.c 
	gcc -c -o main.o main.c

function.o: function.c function.h
	gcc -c -o function.o function.c

clean:
	del *.o
	del task2.exe
	