#include <stdio.h>
#include <string.h>

#define ENCRYPT_FIRST_BYTES 1024

void crypt(char *text, int key);
void decrypt(char *text, int key);




void encrypt_file(char *path) {
    printf("encrypt: File: '%s'\n", path);
}



void crypt(char *text, int key) {
    unsigned int i;
    for (i = 0; i < strlen(text); ++i) {
        *(text+i) = *(text+i) ^ key;
    }
}



void decrypt(char *text, int key) {
    crypt(text, key);
}