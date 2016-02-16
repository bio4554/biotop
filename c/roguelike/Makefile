CC=gcc
FLAGS=-lncurses
OUTPUT=game


roguelike : main.o
	$(CC) main.o -o $(OUTPUT) $(FLAGS)

main.o : main.c
	$(CC) -c main.c $(FLAGS)

