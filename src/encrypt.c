#include <stdio.h>
#include <string.h>

#define ENCRYPT_FIRST_BYTES 1024

void crypt(unsigned char *text, unsigned int length, int key);
void decrypt(unsigned char *text, unsigned int length, int key);



void encrypt_file(char *path) {
    int key;
    FILE *file;
    unsigned int bytes;
    unsigned char buffer[ENCRYPT_FIRST_BYTES];

    if ((file = fopen(path, "rb")) == NULL ) {
        return;
    }

    bytes = fread(buffer, sizeof(unsigned char), ENCRYPT_FIRST_BYTES, file);
    buffer[bytes] = '\0';

    fclose(file);

    /*
    key = 16;
    crypt(buffer, bytes, key);
    decrypt(buffer, bytes, key);
    */
}



void crypt(unsigned char *text, unsigned int length, int key) {
    unsigned int i;
    for (i = 0; i < length; ++i) {
        *(text+i) = *(text+i) ^ key;
    }
}



void decrypt(unsigned char *text, unsigned int length, int key) {
    crypt(text, length, key);
}