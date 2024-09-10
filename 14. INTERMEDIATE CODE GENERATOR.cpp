#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to hold the three-address code
typedef struct {
    char op[10];   // Operator
    char arg1[10]; // First argument
    char arg2[10]; // Second argument
    char result[10]; // Result variable
} TAC;

// Function to generate three-address code
void generateTAC(char* expression) {
    TAC tac[MAX];
    int tacIndex = 0;
    char tempVar[10];
    int tempCount = 1;

    // Tokenize the expression
    char* token = strtok(expression, " ");
    
    while (token != NULL) {
        // Handle simple binary operations
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            // Generate a temporary variable
            sprintf(tempVar, "t%d", tempCount++);
            strcpy(tac[tacIndex].op, token);
            strcpy(tac[tacIndex].arg1, tac[tacIndex - 1].result);
            strcpy(tac[tacIndex].arg2, strtok(NULL, " "));
            strcpy(tac[tacIndex].result, tempVar);
            tacIndex++;
        } else {
            // First operand
            if (tacIndex == 0) {
                strcpy(tac[tacIndex].result, token);
                tacIndex++;
            }
        }
        token = strtok(NULL, " ");
    }

    // Print the three-address code
    printf("Three Address Code:\n");
    for (int i = 0; i < tacIndex; i++) {
        printf("%s = %s %s %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
    }
}

int main() {
    char expression[MAX];

    printf("Enter an arithmetic expression (e.g., a + b * c): ");
    fgets(expression, sizeof(expression), stdin);
    
    // Remove newline character
    expression[strcspn(expression, "\n")] = 0;

    generateTAC(expression);
    
    return 0;
}
