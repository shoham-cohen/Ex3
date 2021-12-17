CC = gcc
FLAGS = -Wall -g
main = main.o

all: stringProg

stringProg: $(main)
	$(CC) $(FLAGS) -o stringProg $(main)


main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

Clean:
	rm -f *.o *.a stringProg