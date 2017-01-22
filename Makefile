CC = gcc
DEBUG = -g -Wall -Wextra
FLAGS = -std=c89 -ansi -pedantic


main:
	$(CC) $(DEBUG) $(FLAGS) src/main.c src/listdir.c -o bin/sisyph

run:
	./bin/sisyph


clean:
	rm -f bin/sisyph