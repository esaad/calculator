CFLAGS=-Wall -g

all:
	gcc -std=c99 -o calculator calculator.c

clean:

	rm -f calculator
