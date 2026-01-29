#include <stdio.h>
#include <stdlib.h>

void hfunzip(char *fileName) {
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("hfunzip: cannot open file\n");
        exit(1);
    }

    int count;
    char c;
    int countRead;
    int charRead;

    countRead = fread(&count, sizeof(int), 1, fp);
    charRead = fread(&c, sizeof(char), 1, fp);

    while (countRead == 1 || charRead == 1) {
        int i;
        for(i = 0; i < count; i++) {
            putc(c, stdout);
        }
        countRead = fread(&count, sizeof(int), 1, fp);
        charRead = fread(&c, sizeof(char), 1, fp);
    }

    if (fclose(fp) != 0) {
        printf("Error closing file.\n");
    }

    fp = NULL;

}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("hfunzip: file1 [file2 ...]\n");
        exit(1);
    }

    int i;
    for (i = 1; i < argc; i++) {
        hfunzip(argv[i]);
    }

    return 0;
}