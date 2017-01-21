CC = gcc
DEBUG = -g -Wall -Wextra
FLAGS = -std=c89 -ansi -pedantic


main:
	$(CC) $(DEBUG) $(FLAGS) main.c listdir.c -o sisyph

run:
	./sisyph


clean:
	rm -f sisyph