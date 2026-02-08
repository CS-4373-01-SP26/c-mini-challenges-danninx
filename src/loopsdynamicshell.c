#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
	int i,j;
	int n = 128;
	double sum;
	clock_t end, start;
	double *arr = malloc(n*n*sizeof(double));

	// THIS FILLS THE MATRIX WITH NUMBERS
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			arr[i*n+j] = (double) rand()/RAND_MAX;

	// ROW MAJOR WORK
	sum = 0;
	start = clock();
	for (i = 0; i<n; i++) 
		for (j = 0; j<n; j++) 
			sum += arr[i*n + j];
	end = clock();

	// NOTE:  YOU'LL NEED TO PROVIDE MEANING TO end AND start
	printf("Row Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

	//ADD YOUR COLUMN MAJOR WORK
	// YOU'LL NEED TO TIME IT
	sum = 0;
	start = clock();
	for (i=0; i<n; i++)
		for (j = 0; j<n; j++)
			sum += arr[j*n + i];
	end = clock();
	printf("Column Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);


	free(arr);
	return 0;
}

