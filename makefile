CC=gcc
FLAG=-Wall -g 

all: frequency

frequency: main.o freq.o
	$(CC) $(FLAG) -o frequency main.o freq.o 

main.o: main.c freq.h
	$(CC) $(FLAG) -c main.c

freq.o: freq.c freq.h
	$(CC) $(FLAG) -c freq.c

.PHONY:  frequency clean all
clean:
	rm -f *.o *.a *.so frequency
