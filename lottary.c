#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // For time-based randomness

#define MAX_EMPLOYEES 1000

// Employee structure
typedef struct {
    int id;
    char name[100];
} Employee;

// Function to calculate bit size of a name
int calculate_bit_size(const char *name) {
    return strlen(name) * 8;  // Each character = 8 bits
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    // Open file containing employee data
    FILE *file = fopen("employees.txt", "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read employee data
    while (fscanf(file, "%d,%99[^\n]", &employees[count].id, employees[count].name) == 2) {
        count++;
        if (count >= MAX_EMPLOYEES) break;
    }
    fclose(file);

    if (count == 0) {
        printf("No employees found!\n");
        return 1;
    }

    // Calculate total bit sum of all names
    int total_bits = 0;
    for (int i = 0; i < count; i++) {
        total_bits += calculate_bit_size(employees[i].name);
    }

    // Introduce time-based randomness
    srand(time(0));  // Seed randomness
    int random_offset = rand() % count;  // Random number between 0 and count-1

    // Select winner using (total_bits + random_offset) % count
    int winnerIndex = (total_bits + random_offset) % count;

    printf("\n🎉 The winner is: %s (ID: %d) 🎉\n", employees[winnerIndex].name, employees[winnerIndex].id);

    return 0;
}
