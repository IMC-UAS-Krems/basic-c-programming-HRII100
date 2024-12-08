#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        const char *str = argv[i];
        while (*str) {
            if (!isdigit(*str)) {
                fprintf(stderr, "Incorrect usage. The parameters you provided are not positive integers\n");
                return EXIT_FAILURE;
            }
            str++;
        }
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    if (rows <= 0 || cols <= 0) {
        fprintf(stderr, "Incorrect usage. The parameters must be positive integers greater than zero.\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    int minrand = 1, maxrand = 100;

    int **matrix = malloc(rows * sizeof(int *));
    if (!matrix) {
        fprintf(stderr, "Memory allocation for rows failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            fprintf(stderr, "Memory allocation for columns failed at row %d\n", i);
            for (int j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (maxrand - minrand + 1) + minrand;
        }
    }

    FILE *file = fopen("matrix.txt", "w");
    if (!file) {
        fprintf(stderr, "Failed to open file matrix.txt for writing\n");
        for (int i = 0; i < rows; i++) free(matrix[i]);
        free(matrix);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) fprintf(file, " ");
        }
        fprintf(file, "\n");
    }

    fclose(file);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("Matrix generated and saved to matrix.txt\n");
    return EXIT_SUCCESS;
}
/////aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa