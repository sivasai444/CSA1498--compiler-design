#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structures for the intermediate representation
typedef struct {
    int opcode;
    int operand1;
    int operand2;
    int result;
} instruction_t;

// Define the maximum number of instructions
#define MAX_INSTRUCTIONS 1000

// Initialize the instruction array
instruction_t instructions[MAX_INSTRUCTIONS];
int num_instructions = 0;

// Function to add an instruction to the instruction array
void add_instruction(int opcode, int operand1, int operand2, int result) {
    instructions[num_instructions].opcode = opcode;
    instructions[num_instructions].operand1 = operand1;
    instructions[num_instructions].operand2 = operand2;
    instructions[num_instructions].result = result;
    num_instructions++;
}

// Function to generate assembly code from the intermediate representation
void generate_assembly() {
    for (int i = 0; i < num_instructions; i++) {
        switch (instructions[i].opcode) {
            case 0: // Addition
                printf("ADD R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            case 1: // Subtraction
                printf("SUB R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            case 2: // Multiplication
                printf("MUL R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            case 3: // Division
                printf("DIV R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            // Add more cases for other opcodes as needed
        }
    }
}

int main() {
    // Add some instructions to the instruction array
    add_instruction(0, 1, 2, 3); // ADD R3, R1, R2
    add_instruction(1, 3, 4, 5); // SUB R5, R3, R4
    add_instruction(2, 5, 6, 7); // MUL R7, R5, R6
    add_instruction(3, 7, 8, 9); // DIV R9, R7, R8

    // Generate assembly code from the intermediate representation
    generate_assembly();

    return 0;
}
