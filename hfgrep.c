#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hfgrep(char *string, FILE *fp) {
    if (fp == NULL) {
        printf("hfgrep: cannot open file\n");
        exit(1);
    }

    char* line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != -1) {

        if (strstr(line, string) != NULL) {
            printf("%s", line);
        }

    }

    if (line) {
        free(line);
    }

    fp = NULL;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("hfgrep: searchterm [file ...]\n");
        exit(1);
    }
    else if (argc == 2) {
        hfgrep(argv[1], stdin);
        exit(0);
    }

    int i;
    FILE *fp;
    for (i = 2; i < argc; i++) {
        fp = fopen(argv[i], "r");

        hfgrep(argv[1], fp);
        if (fclose(fp) != 0) {
            printf("Error closing file.\n");
        }
    }

    return 0;
}