#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Validate the number of arguments
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1;
    }

    // Validate that the arguments are positive integers
    for (int i = 1; i < argc; i++) {
        if (atoi(argv[i]) <= 0) {
            printf("Incorrect usage. The parameters you provided are not positive integers.\n");
            return 1;
        }
    }

    // Parse the number of rows and columns
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // Initialize random number generator
    srand(time(NULL));
    int min_value = 1, max_value = 100;

    // Allocate memory for the matrix
    int (*matrix)[cols] = malloc(rows * cols * sizeof(int));
    if (!matrix) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill the matrix with random numbers
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            matrix[r][c] = (rand() % (max_value - min_value + 1)) + min_value;
        }
    }

    // Print the matrix to the console
    printf("Generated Matrix:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%d%s", matrix[r][c], (c == cols - 1) ? "\n" : " ");
        }
    }

    // Write the matrix to a file
    FILE *file = fopen("matrix.txt", "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        free(matrix);
        return 1;
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            fprintf(file, "%d%s", matrix[r][c], (c == cols - 1) ? "\n" : " ");
        }
    }

    fclose(file);
    free(matrix);

    printf("Matrix successfully written to 'matrix.txt'.\n");
    return 0;
}
//a