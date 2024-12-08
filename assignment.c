#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Initialize the random number generator
    srand((unsigned int)time(NULL));
    int min_value = 1, max_value = 100;

    // Verify that exactly two arguments are provided
    if (argc != 3) {
        printf("Error: Expected 2 arguments, but got %d.\n", argc - 1);
        return 1;
    }

    // Check that the arguments are positive integers
    for (int i = 1; i < argc; i++) {
        if (atoi(argv[i]) <= 0) {
            printf("Error: Arguments must be positive integers.\n");
            return 1;
        }
    }

    // Parse the input arguments
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // Dynamically allocate memory for the matrix
    int (*matrix)[cols] = malloc(rows * cols * sizeof(int));
    if (!matrix) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill the matrix with random values
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            matrix[row][col] = (rand() % (max_value - min_value + 1)) + min_value;
        }
    }

    // Print the matrix to the console
    printf("Generated Matrix:\n");
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%d%s", matrix[row][col], (col == cols - 1) ? "\n" : " ");
        }
    }

    // Write the matrix to a file
    FILE *output_file = fopen("matrix.txt", "w");
    if (!output_file) {
        printf("Error: Unable to open 'matrix.txt' for writing.\n");
        free(matrix);
        return 1;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            fprintf(output_file, "%d%s", matrix[row][col], (col == cols - 1) ? "\n" : " ");
        }
    }

    fclose(output_file);

    // Free allocated memory
    free(matrix);

    printf("Matrix successfully written to 'matrix.txt'.\n");
    return 0;
}
//AA