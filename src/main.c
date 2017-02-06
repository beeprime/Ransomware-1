#include "includes.h"


int listdir(char *root, int level);
void total_removal_of_file(char *path);




int main() {
    char *root = "test";

#ifdef DEBUG
    printf("Sisyph start from '%s'\n\n", root);
#endif

    listdir(root, 0);

    return 0;
}