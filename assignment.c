#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    

        if (argc - 1 != 2){
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc-1);
        return 1;
    }

    int i;
    for (i = 1; i < argc; i++ ){
        if (atoi(argv[i]) <= 0){
            printf("Incorrect usage. The parameters you provided are not positive integers");
            return 1;
        }
    }
    
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    

    int (*matrix)[col] = malloc(sizeof(int[row][col]));
	int j,k;

    

	for(j=0;j<row;j++){
		for(k=0;k<col;k++){
            int rand_nr = (rand() % (maxrand-minrand +1)) + minrand;
			matrix[j][k] = rand_nr;
		}
	}

	for(j=0;j<row;j++){
		printf("\n");
		for(k=0;k<col;k++){
            if (k!=(col-1)){
               printf("%d  ", matrix[j][k]); 
            } else {
				printf("%d", matrix[j][k]);
			}
		}
	}

    

    FILE *file_to_write = fopen("matrix.txt", "w");

    if (file_to_write==0){
        printf("Failed to open file %s\n", "matrix.txt");
        return 1;
    }

    int num;

    
    

    for(j=0;j<row;j++){
        for(k=0;k<col;k++){
            num = matrix[j][k];
            if (k!=(col-1)){
                
                fprintf(file_to_write, "%d ", num);
                
            } else if(j==(row-1) && k==(col-1)) {
                
                fprintf(file_to_write, "%d\r", num);
                

            } else {
                
				fprintf(file_to_write, "%d\n", num);
                
                
			}

        }
    }
    
    

    fclose(file_to_write);

    
    free(matrix);

    return 0;
}
