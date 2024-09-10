#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[50];
    char ch;
    int characters = 0, words = 0, lines = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            words++;
        }
    }

    if (characters > 0) {
        words++;
        lines++;
    }

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    fclose(file);
    return 0;
}
