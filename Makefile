all:
	gcc -Wall -o main geometry.c main.c
clean:
	rm -f *.o
	rm -f main
