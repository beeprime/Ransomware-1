#include <stdio.h>
#include <dirent.h>
#include <string.h>
/**
 * DT_DIR is defined in the file <unistd.h>,
 * but it is not supported in ANSI C.
 */
#define DT_DIR  4
#define DT_FILE 8




int is_file(struct dirent *entry) {
    return (entry->d_type == DT_FILE);
}


int is_dir(struct dirent *entry) {
    return (entry->d_type == DT_DIR);
}


int is_inode(struct dirent *entry) {
    return (
        (!strncmp(entry->d_name, ".", 1) && strlen(entry->d_name) == 1) ||
        (!strncmp(entry->d_name, "..", 2) && strlen(entry->d_name) == 2)
    );
}


int is_root(char *path) {
    return (strlen(path) == 1 && strncmp(path, "/", 1) == 0);
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

        if (is_inode(entry)) {
            printf("Node: %s\n", path);
        } else if (is_dir(entry)) {
            printf("Catalog: %s\n", path);
            listdir(path, depth + 1);
        } else if (is_file(entry)) {
            printf("File: %s\n", path);
        }
    } while ((entry = readdir(dir)));

    closedir(dir);
    return 0;
}