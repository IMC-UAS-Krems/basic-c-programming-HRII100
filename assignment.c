#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Initialize the random number generator
    srand((unsigned int)time(0));
    int lower_limit = 1, upper_limit = 100;

    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Error: Expected 2 arguments, but got %d.\n", argc - 1);
        return 1;
    }

    // Validate that the arguments are positive integers
    for (int arg_index = 1; arg_index < argc; arg_index++) {
        if (atoi(argv[arg_index]) <= 0) {
            printf("Error: Arguments must be positive integers.\n");
            return 1;
        }
    }

    // Parse the number of rows and columns
    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);

    // Allocate memory for the matrix
    int (*matrix)[columns] = malloc(rows * columns * sizeof(int));
    if (!matrix) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Populate the matrix with random numbers
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            matrix[r][c] = (rand() % (upper_limit - lower_limit + 1)) + lower_limit;
        }
    }

    // Display the matrix on the console
    printf("Generated Matrix:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            printf("%d%c", matrix[r][c], (c == columns - 1) ? '\n' : ' ');
        }
    }

    // Write the matrix to a file
    FILE *output_file = fopen("matrix.txt", "w");
    if (!output_file) {
        printf("Error: Could not open file for writing.\n");
        free(matrix);
        return 1;
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            fprintf(output_file, "%d%c", matrix[r][c], (c == columns - 1) ? '\n' : ' ');
        }
    }

    fclose(output_file);
    free(matrix);

    printf("Matrix successfully written to 'matrix.txt'.\n");
    return 0;
}
