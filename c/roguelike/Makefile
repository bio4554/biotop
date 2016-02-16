all: game

game: main.o
	gcc main.o -o game -lncurses

main.o: main.c
	gcc -c main.c -lncurses
