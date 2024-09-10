#include <stdio.h>
#include <string.h>
#define MAX 10

void computeFollow(char symbol, char follow[][MAX], char productions[][MAX], int num_productions, char first[][MAX]) {
    if (symbol == 'S') {
        follow[symbol - 'A']['$' - '$'] = 1;  
    }
    
    for (int i = 0; i < num_productions; i++) {
        char *prod = productions[i];
        for (int j = 3; prod[j] != '\0'; j++) {
            if (prod[j] == symbol) {
                if (prod[j + 1] >= 'A' && prod[j + 1] <= 'Z') {
                    
                    for (int k = 0; k < MAX; k++) {
                        if (first[prod[j + 1] - 'A'][k]) {
                            follow[symbol - 'A'][k] = 1;
                        }
                    }
                }
                if (prod[j + 1] == '\0' || first[prod[j + 1] - 'A']['?' - 'A']) {
                    
                    for (int k = 0; k < MAX; k++) {
                        if (follow[prod[0] - 'A'][k]) {
                            follow[symbol - 'A'][k] = 1;
                        }
                    }
                }
            }
        }
    }
}

void displayFollow(char follow[MAX][MAX], char non_terminals[], int num_non_terminals) {
    for (int i = 0; i < num_non_terminals; i++) {
        printf("FOLLOW(%c) = { ", non_terminals[i]);
        for (int j = 0; j < MAX; j++) {
            if (follow[non_terminals[i] - 'A'][j]) {
                printf("%c ", (j == ('$' - '$')) ? '$' : 'a' + j);
            }
        }
        printf("}\n");
    }
}

int main() {
    char productions[MAX][MAX] = {
        "S->AaAb",
        "S->BbBa",
        "A->?",
        "B->?"
    };

    char non_terminals[] = {'S', 'A', 'B'};
    int num_non_terminals = 3;
    int num_productions = 4;

    char first[MAX][MAX] = {
        {1, 1, 0},  
        {0, 0, 1},  
        {0, 0, 1}   
    };

    char follow[MAX][MAX] = {0};

    for (int i = 0; i < num_non_terminals; i++) {
        computeFollow(non_terminals[i], follow, productions, num_productions, first);
    }

    displayFollow(follow, non_terminals, num_non_terminals);

    return 0;
}

