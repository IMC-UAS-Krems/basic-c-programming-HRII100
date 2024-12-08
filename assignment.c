#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please provide exactly two arguments: rows and columns.\n");
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    if (rows <= 0 || cols <= 0) {
        printf("Rows and columns must be positive numbers.\n");
        return 1;
    }

    srand(time(NULL));

    // Allocate memory for the matrix
    int *matrix = malloc(rows * cols * sizeof(int));
    if (!matrix) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // Fill the matrix with random numbers
    printf("Filling the matrix with random numbers...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = rand() % 100 + 1;
        }
    }

    // Print the matrix to the console
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    // Write the matrix to a file
    printf("Writing the matrix to a file...\n");
    FILE *file = fopen("matrix.txt", "w");
    if (!file) {
        printf("Could not open file.\n");
        free(matrix);
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i * cols + j]);
        }
        fprintf(file, "\n");
    }

    // Close the file and free memory
    fclose(file);
    free(matrix);

    printf("Matrix saved to matrix.txt\n");
    return 0;
}
