#include <stdio.h>

#define ENCRYPT_FIRST_BYTES 1024




void encrypt_file(char *path) {
    FILE *file;
    char buffer[ENCRYPT_FIRST_BYTES];

    printf("encrypt: File: '%s'\n", path);
}