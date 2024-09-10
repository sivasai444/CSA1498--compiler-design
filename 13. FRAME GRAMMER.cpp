#include <stdio.h>
#include <string.h>

char input[100];
int index = 0;

// Function prototypes
void S();
void A();
void B();
void match(char expected);

int main() {
    printf("Enter the input string: ");
    scanf("%s", input);
    
    // Start parsing from the start symbol S
    S();
    
    // Check if the entire input has been consumed
    if (input[index] == '\0') {
        printf("The input string is valid according to the grammar.\n");
    } else {
        printf("The input string is invalid according to the grammar.\n");
    }
    
    return 0;
}

// Function to parse S
void S() {
    match('a'); // Match 'a'
    A();        // Parse A
    B();        // Parse B
}

// Function to parse A
void A() {
    if (input[index] == 'b') {
        match('b'); // Match 'b'
    }
    // e (epsilon) production: do nothing
}

// Function to parse B
void B() {
    match('c'); // Match 'c'
}

// Function to match expected character
void match(char expected) {
    if (input[index] == expected) {
        index++; // Move to the next character
    } else {
        printf("Error: Expected '%c' but found '%c'\n", expected, input[index]);
        // Exit the program if there is a mismatch
        
    }
}
