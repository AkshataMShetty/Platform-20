#include <stdio.h>
#include <stdlib.h>

int **matrix_sum()
{
	int i, j;
	int x[3][3], y[3][3];

	int **matrix3;

	printf("Enter the matrix1: \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &x[i][j]);
		}
	}

	printf("Enter the matrix2: \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &y[i][j]);
		}
	}

	matrix3 = malloc(sizeof(int *) * 3);
	for (i = 0; i < 3; i++) {
		matrix3[i] = malloc(sizeof(int *) * 3);
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			matrix3[i][j] = x[i][j] + y[i][j];
		}
	}
	return matrix3;
}



int main()
{
	int i, j;
	int (*(*fp)())[3][3];

	fp = matrix_sum ;		//asigning
	printf("The sum of the matrix is: \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d", (*fp())[i][j]);
			printf("\t");
		}
		printf("\n");
	}

	return 0;
}
