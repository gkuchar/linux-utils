#include <stdio.h>
#include <stdlib.h>

void hfcat(char* fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("hfcat: cannot open file\n");
        exit(1);
    }

    char buffer[100];
    int n = 100;

    while ((fgets(buffer, n, fp)) != NULL) {
        fputs(buffer, stdout);
    }

    if (fclose(fp) != 0) {
        printf("Error closing file.\n");
    }

    fp = NULL;

}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        exit(0);
    }

    int i;
    for (i = 1; i < argc; i++) {
        hfcat(argv[i]);
    }

    return 0;
}