// 3. Implement matrix – vector multiplication. Read in the following text file (mv.txt) which contains the matrix and vector to be multiplied. Print your answer to the screen and time the computation. The format of mv.txt is: line 1 contains numrows, numcols. The next numrows contains the rows of the matrix, each with numcols integer values. The next line contains the length of the vector. The next line contains the vector of that length.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int rows;
	int cols;
	int *data;
} Matrix;

typedef struct {
	int length;
	int *data;
} Vector;

//TODO
void mult_mat(Matrix *first, Matrix *second) {
	if (first->cols != second->rows) {
		printf("Cannot multiply matrices where first.cols != second.rows; aborting...\n");
		exit(1);
	}

	int ar = first->rows;
	int ac = first->cols;

	int br = second->rows;
	int bc = second->cols;

	for (int i=0; i<ar; i++) {

	}
}

void mult_mat_vec(Matrix *matrix, Vector *vector, Vector *result) {
	if (matrix->cols != vector->length) {
		printf("Cannot multiply matrix and vector where #columns != vector length; aborting...\n");
		exit(1);
	}
	
	int r = matrix->rows;
	int c = matrix->cols;

	for (int i=0; i<r; i++) {
		int sum = 0;
		for (int j=0; j<c; j++) {
			sum += matrix->data[i*c + j] * vector->data[j];
		}

		result->data[i] = sum;
	}
}

Matrix* matrix_init(int rows, int cols) {
	Matrix* mat = (Matrix *)calloc(1, sizeof(Matrix));
	mat->rows = rows;
	mat->cols = cols;
	mat->data = calloc(rows * cols, sizeof(int));
	return mat;
}

Vector* vector_init(int length) {
	Vector* vec = (Vector *)calloc(1, sizeof(Vector));
	vec->length = length;
	vec->data = calloc(length, sizeof(int));

	return vec;
}

void fscan_nums(FILE *fd, int *ptr, int n) {
	for (int i=0; i<n-1; i++) {
		fscanf(fd, "%d ", ptr + i);		
	}
	fscanf(fd, "%d", ptr + n - 1);
}

void fscan_matrix(FILE *fd, Matrix *mat) {
	int r = mat->rows;
	int c = mat->cols;
	
	for (int i=0; i<r; i++) {
		int row_offset = i * c;
		fscan_nums(fd, mat->data + row_offset, c);
		fscanf(fd, "\n");
	}
}

void fscan_vector(FILE *fd, Vector *vec) {
	int length = vec->length;	
	fscan_nums(fd, vec->data, length);
}

void print_vector_ln(Vector *vec) {
	printf("Vector of length %d [ ", vec->length);
	for (int i=0; i<vec->length-1; i++) {
		printf("%d, ", vec->data[i]);
	}
	
	printf("%d ]\n", vec->data[vec->length - 1]);
}

int main() {
	FILE *mv = fopen("mv.txt", "r");	

	int mat_rows, mat_cols;
	fscanf(mv, "%d %d\n", &mat_rows, &mat_cols);
	Matrix *mat = matrix_init(mat_rows, mat_cols);
	fscan_matrix(mv, mat);

	int vec_length;
	fscanf(mv, "%d\n", &vec_length);
	Vector *vec = vector_init(vec_length);
	fscan_vector(mv, vec);	

	Vector *result = vector_init(vec_length);
	
	// TIME COMPUTATION
	clock_t start, end;
	start = clock();
	mult_mat_vec(mat, vec, result);
	end = clock();

	printf("Result:\n\t- ");
	print_vector_ln(result);

	printf("\nTime for computation:\n\t- %ld clocks", end-start);

	return 0;
}
