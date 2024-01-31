all: task3

task3: main.o function.o 
	gcc -o task3 main.o function.o

main.o: main.c 
	gcc -c -o main.o main.c

function.o: function.c function.h
	gcc -c -o function.o function.c

clean:
	del *.o
	del task3.exe
	