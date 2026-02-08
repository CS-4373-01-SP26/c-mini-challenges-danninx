#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef N
#define N 128
#endif

#define RANDOMIZE(arr, n) for (i=0; i<n; i++) for (j=0; j<n; j++) arr[i*n+j] = (double) rand()/RAND_MAX;

void row_major() {
	int i,j;
	double sum;
	clock_t end, start;
	double *arr = malloc(N*N*sizeof(double));

	RANDOMIZE(arr, N);

	sum = 0;
	start = clock();
	for (i = 0; i<N; i++) 
		for (j = 0; j<N; j++) 
			sum += arr[i*N + j];
	end = clock();

	printf("Row Major: %ld clocks\n", end-start);

	free(arr);
}

void column_major() {
	int i,j;
	double sum;
	clock_t end, start;
	double *arr = malloc(N*N*sizeof(double));

	RANDOMIZE(arr, N);

	sum = 0;
	start = clock();
	for (i=0; i<N; i++)
		for (j = 0; j<N; j++)
			sum += arr[j*N + i];
	end = clock();

	printf("Column Major: %ld clocks\n", end-start);

	free(arr);
}


int main(int argc, char **argv) {
	row_major();
	column_major();
	return 0;
}

