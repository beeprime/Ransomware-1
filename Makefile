CC = gcc
DEBUG = -g -Wall -Wextra
FLAGS = -std=c89 -ansi -pedantic


main:
	mkdir -p bin
	$(CC) $(DEBUG) $(FLAGS) src/main.c src/listdir.c src/encrypt.c src/includes.h -o bin/sisyph

run:
	./bin/sisyph


clean:
	rm -rf bin/