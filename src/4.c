// 4. Compare the speed of *,/,sqrt, sin operations/functions.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	double result;
	clock_t start;
	clock_t end;
} DoubleResult;

#define TIME(stmt) {\
	start = clock(); \
	stmt; \
	end = clock(); \
}

#define RESULT(x) return (DoubleResult){.result = x, .start = start, .end = end}

#define RANDOMIZE(arr, length, min, max) {\
	for (size_t i=0; i<length; i++) {\
		arr[i] = rand() / (double) RAND_MAX; \
		arr[i] *= (max - min); \
		arr[i] += (min); \
	} \
}

void print_results(const char* name, DoubleResult results, int n) {
	clock_t total = (results.end - results.start);
	double average = ((double) total) / n;

	printf("Test \"%s\" (%d operations) : %ld total clocks, %f clocks/op\n", name, n, total, average);
}

DoubleResult test_mult(double *vals, int n) {
	clock_t start, end;
	double c;
 
	TIME({
		for (int i=0; i<n; i += 2) {
			c = vals[i] * vals[i+1];
		}
	});

	RESULT(c);
}

DoubleResult test_div(double *vals, int n) {
	clock_t start, end;
	double c;

	TIME({
		for (int i=0; i<n; i+=2) {
			c = vals[i] / vals[i+1];
		}
	});

	RESULT(c);
}

DoubleResult test_sqrt(double *vals, int n) {
	clock_t start, end;
	double res;

	TIME({
		for (int i=0; i<n; i++) {
			res = sqrt(vals[i]);
		}
	});

	RESULT(res);
}

DoubleResult test_sin(double *vals, int n) {
	clock_t start, end;
	double res;

	TIME({
		for (int i=0; i<n; i++) {
			res = sin(vals[i]);
		}
	});
	RESULT(res);
}

int main() {
	// OPERATOR TESTS
	double *operator_values = malloc(100000 * sizeof(double));
	DoubleResult mult_results;
	DoubleResult div_results;

	RANDOMIZE(operator_values, 100000, 1, 100000000000000);

	mult_results = test_mult(operator_values, 100000);
	div_results = test_div(operator_values, 100000);

	print_results("*", mult_results, 50000);
	print_results("/", div_results, 50000);
	
	// FUNCTION TESTS
	double *function_values = malloc(100000 * sizeof(double));
	DoubleResult sqrt_results;
	DoubleResult sin_results;

	RANDOMIZE(function_values, 100000, 0, 2 * M_PI);

	sqrt_results = test_sqrt(function_values, 100000);		
	sin_results = test_sin(function_values, 100000);
	
	print_results("sqrt()", sqrt_results, 100000);
	print_results("sin()", sin_results, 100000);

	return 0;
}
