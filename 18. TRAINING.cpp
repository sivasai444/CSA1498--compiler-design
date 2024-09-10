#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char input[MAX];
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
            return 1;
        case '*':
            return 2;
        case '(':
            return 0;
        default:
            return -1; // for identifiers
    }
}

int isOperator(char c) {
    return c == '+' || c == '*';
}

void parse() {
    char *token = strtok(input, " ");
    char current;
    char topOp;

    while (token != NULL) {
        current = token[0];

        if (isalnum(current)) { // if the token is an identifier
            printf("ID: %s\n", token);
        } else if (current == '(') {
            push(current);
        } else if (current == ')') {
            while ((topOp = pop()) != '(') {
                printf("Operator: %c\n", topOp);
            }
        } else if (isOperator(current)) {
            while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                printf("Operator: %c\n", pop());
            }
            push(current);
        }

        token = strtok(NULL, " ");
    }

    while (top != -1) {
        printf("Operator: %c\n", pop());
    }
}

int main() {
    printf("Enter an expression: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    parse();
    return 0;
}
