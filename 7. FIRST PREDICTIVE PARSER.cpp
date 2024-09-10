#include <stdio.h>
#include <string.h>

#define MAX 10

void computeFirst(char symbol, char first[MAX][MAX], char productions[MAX][MAX], int num_productions) {
    
    for (int i = 0; i < num_productions; i++) {
        if (productions[i][0] == symbol) {
            
            for (int j = 2; productions[i][j] != '\0'; j++) {
                
                if (productions[i][j] >= 'a' && productions[i][j] <= 'z') {
                    first[symbol - 'A'][productions[i][j] - 'a'] = 1;
                    break;
                }
                
                else if (productions[i][j] == '?') {
                    first[symbol - 'A']['?' - 'A'] = 1;
                    break;
                }
                
                else if (productions[i][j] >= 'A' && productions[i][j] <= 'Z') {
                   
                    computeFirst(productions[i][j], first, productions, num_productions);
                    break;
                }
            }
        }
    }
}
void displayFirst(char first[MAX][MAX], char non_terminals[], int num_non_terminals) {
    for (int i = 0; i < num_non_terminals; i++) {
        printf("FIRST(%c) = { ", non_terminals[i]);
        for (int j = 0; j < MAX; j++) {
            if (first[non_terminals[i] - 'A'][j] == 1) {
                printf("%c ", 'a' + j);
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
    char first[MAX][MAX] = {0};

    for (int i = 0; i < num_non_terminals; i++) {
        computeFirst(non_terminals[i], first, productions, num_productions);
    }
    displayFirst(first, non_terminals, num_non_terminals);

    return 0;
}

