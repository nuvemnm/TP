#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define VECTOR_SIZE 1000

// Initialize the vector
void init_vector(int *vector) {
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector[i] = 0; // Using 0 to represent an empty slot
    }
}

// Find the index of an element in the vector, return -1 if not found
int find_element(int *vector, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (vector[i] == element) {
            return i;
        }
    }
    return -1;
}

// Add an element to the vector or move it to the top and return access distance
int add_or_get_distance(int *vector, int size, int element) {
    int index = find_element(vector, size, element);

    // Calculate the access distance
    int distance = (index == -1) ? 0 : index + 1;

    // Move the element to the top or add it to the vector
    if (index != -1) {
        // If the element exists, move it to the top
        for (int i = index; i > 0; i--) {
            vector[i] = vector[i - 1];
        }
    } else {
        // If the element doesn't exist, shift all elements down
        for (int i = size - 1; i > 0; i--) {
            vector[i] = vector[i - 1];
        }
    }

    // Place the new or moved element at the top
    vector[0] = element;

    return distance;
}

// Print the current state of the vector
void print_vector(int *vector, int size) {
    printf("Vector: ");
    for (int i = 0; i < size; i++) {
        if (vector[i] != 0) { // Skip empty slots
            printf("%d ", vector[i]);
        }
    }
    printf("\n");
}

int main() {
    int vector[VECTOR_SIZE];

    // Initialize the vector
    init_vector(vector);


    char line[1000];
    int offset = 0;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        // distances[total_operations++] = add_or_push(stack, atoi(line));
        int val = strtol(line, NULL, 16);
        if (!offset) offset = val;
        int o = ((val - offset) / 4) + 1;
        printf("%d\n", add_or_get_distance(vector, VECTOR_SIZE, o));
    }

    return 0;
}
