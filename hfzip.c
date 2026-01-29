#include <stdio.h>
#include <stdlib.h>

void hfzip(FILE *fp) {

    int counter;
    int c = getc(fp);

    while (c != EOF) {
        counter = 1;
        int next;
        while ((next = getc(fp)) == c) {
            counter++;
        }

        fwrite(&counter, sizeof(int), 1, stdout);
        fwrite(&c, 1, 1, stdout);
        c = next;
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("hfzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *temp = tmpfile();
    if (temp == NULL) {
        printf("hfzip: cannot create temporary file\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("hfzip: cannot open file\n");
            exit(1);
        }
        
        int c;
        while ((c = getc(fp)) != EOF) {
            fputc(c, temp);
        }
        fclose(fp);
    }

    rewind(temp);
    hfzip(temp);
    fclose(temp);

    return 0;
}