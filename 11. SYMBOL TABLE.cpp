#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char name[50], type[20];
    int size, address;
} Symbol;

Symbol symbolTable[MAX];
int count = 0;

void insertSymbol(char name[], char type[], int size, int address) {
    for (int i = 0; i < count; i++) 
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Symbol '%s' already exists.\n", name);
            return;
        }
    strcpy(symbolTable[count].name, name);
    strcpy(symbolTable[count].type, type);
    symbolTable[count].size = size;
    symbolTable[count++].address = address;
    printf("Symbol '%s' inserted.\n", name);
}

void searchSymbol(char name[]) {
    for (int i = 0; i < count; i++) 
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Found: %s, Type: %s, Size: %d, Address: %d\n", symbolTable[i].name, symbolTable[i].type, symbolTable[i].size, symbolTable[i].address);
            return;
        }
    printf("Symbol '%s' not found.\n", name);
}

void deleteSymbol(char name[]) {
    for (int i = 0; i < count; i++) 
        if (strcmp(symbolTable[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++)
                symbolTable[j] = symbolTable[j + 1];
            count--;
            printf("Symbol '%s' deleted.\n", name);
            return;
        }
    printf("Symbol '%s' not found.\n", name);
}

void displaySymbolTable() {
    if (count == 0) {
        printf("Symbol table is empty.\n");
        return;
    }
    printf("Name\tType\tSize\tAddress\n");
    for (int i = 0; i < count; i++) 
        printf("%s\t%s\t%d\t%d\n", symbolTable[i].name, symbolTable[i].type, symbolTable[i].size, symbolTable[i].address);
}

int main() {
    int choice, size, address;
    char name[50], type[20];

    while (1) {
        printf("\n1. Insert 2. Search 3. Delete 4. Display 5. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch (choice) {
        case 1:
            printf("Enter name, type, size, address: ");
            scanf("%s %s %d %d", name, type, &size, &address);
            insertSymbol(name, type, size, address);
            break;
        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            searchSymbol(name);
            break;
        case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            deleteSymbol(name);
            break;
        case 4:
            displaySymbolTable();
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

