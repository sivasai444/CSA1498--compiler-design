#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring() {
    printf("Original Grammar:\n");
    printf("S ? iEtS | iEtSeS | a\n\n");

    printf("Grammar after eliminating left factoring:\n");
    printf("S ? iEtS S' | a\n");
    printf("S' ? eS | ?\n");
}

int main() {
    eliminateLeftFactoring();
    return 0;
}

