#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Function prototypes
int precedence(char op);
int evaluate(int a, int b, char op);
void parseExpression(char *expression);

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} CharStack;

typedef struct {
    int top;
    int items[MAX];
} IntStack;

// Stack functions
void initCharStack(CharStack *s) {
    s->top = -1;
}

void pushChar(CharStack *s, char item) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = item;
    }
}

char popChar(CharStack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    return '\0'; // Stack underflow
}

char peekChar(CharStack *s) {
    if (s->top >= 0) {
        return s->items[s->top];
    }
    return '\0'; // Stack is empty
}

void initIntStack(IntStack *s) {
    s->top = -1;
}

void pushInt(IntStack *s, int item) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = item;
    }
}

int popInt(IntStack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    return 0; // Stack underflow
}

// Function to determine precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to evaluate a simple expression
int evaluate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Function to parse and evaluate the expression
void parseExpression(char *expression) {
    CharStack operators;
    IntStack operands;
    initCharStack(&operators);
    initIntStack(&operands);

    for (int i = 0; i < strlen(expression); i++) {
        char current = expression[i];

        // If the character is a digit, push it to the operands stack
        if (isdigit(current)) {
            int num = 0;
            while (isdigit(current)) {
                num = num * 10 + (current - '0');
                current = expression[++i];
            }
            pushInt(&operands, num);
            i--; // Adjust for the outer loop increment
        }
        // If the character is an operator
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            while (operators.top != -1 && precedence(peekChar(&operators)) >= precedence(current)) {
                int b = popInt(&operands);
                int a = popInt(&operands);
                char op = popChar(&operators);
                pushInt(&operands, evaluate(a, b, op));
            }
            pushChar(&operators, current);
        }
    }

    // Process remaining operators in the stack
    while (operators.top != -1) {
        int b = popInt(&operands);
        int a = popInt(&operands);
        char op = popChar(&operators);
        pushInt(&operands, evaluate(a, b, op));
    }

    // The result is the last remaining item in the operands stack
    printf("Result: %d\n", popInt(&operands));
}

int main() {
    char expression[MAX];
    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = 0; // Remove trailing newline
    parseExpression(expression);
    return 0;
}
