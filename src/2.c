// 2. Implement Archimedes algorithm to estimate pi for inscribed/circumscribed polygons with n sides, up to 100, doubling n at each step, and time it.
#include <math.h>
#include <stdio.h>
#include <time.h>

#define TIME(stmt) {\
	start = clock(); \
	stmt; \
	end = clock(); \
}

long double archimedes(int n) {
	long double result;

	long double edge_squared = 2.0;
	long long sides = 4;
	for (int i=0; i<100; i++) {
		edge_squared = 2 - (2 * sqrt(1 - (edge_squared/ 4)));
		sides *= 2;
		result = sides * sqrt(edge_squared) / 2;
		printf("{ \"iteration\": %d, \"sides\": %lld, \"approximation\": %0.10Lf }\n", i, sides, result);
	}

	return result;
}

int main() {
	clock_t start, end;

	TIME(archimedes(100););

	printf("Time taken: %ld clocks", end-start);
	return 0;
}
