#include "matrix.h"

Matrix * malloc_matrix
(
	const size_t size,
	const size_t length
) {
	Matrix * new_matrix = reallocarray(NULL, 1, sizeof(Matrix));
	if (new_matrix == NULL)
		err(EXIT_SUCCESS, "could not allocate matrix");

	new_matrix->size = size;
	new_matrix->length = length;
	new_matrix->value = reallocarray(NULL, size * length, sizeof(float));
	if (new_matrix->value == NULL)
		err(EXIT_SUCCESS, "could not allocate matrix");

	return new_matrix;
}

void free_matrix
(
	Matrix * matrix
) {
	free(matrix->value);
	free(matrix);
	return;
}

void zero_matrix
(
	Matrix * matrix
) {
	for(unsigned int i = 0;i < matrix->size * matrix->length;i++)
		matrix->value[i] = 0.0f;
	return;
}

static float randf
(
	void
) {
	return (float) rand() / ((float) RAND_MAX) * 2.0f - 1.0f;
}

void randomize_matrix
(
	Matrix * matrix
) {
	for (unsigned i = 0;i < matrix->size * matrix->length;i++)
		matrix->value[i] = randf();
	return;
}

void copy_matrix
(
	const Matrix * source,
	Matrix * destination
) {
	assert(source->size == destination->size);
	assert(source->length == destination->length);

	for (unsigned int i = 0;i < destination->size * destination->length;i++)
		destination->value[i] = source->value[i];
	return;
}

void add_matrix
(
	const Matrix * first_summand,
	const Matrix * second_summand,
	Matrix * sum
) {
	assert(first_summand->size == second_summand->size);
	assert(first_summand->length == second_summand->length);
	assert(second_summand->size == sum->size);
	assert(second_summand->length == sum->length);

	for (unsigned int i = 0;i < sum->size * sum->length;i++)
		sum->value[i] = first_summand->value[i] + second_summand->value[i];
	return;
}

void subtract_matrix
(
	const Matrix * minuend,
	const Matrix * subtrahend,
	Matrix * difference
) {
	assert(minuend->size == subtrahend->size);
	assert(minuend->length == subtrahend->length);
	assert(subtrahend->size == difference->size);
	assert(subtrahend->length == difference->length);

	for (unsigned int i = 0;i < subtrahend->size * subtrahend->length;i++)
		difference->value[i] = subtrahend->value[i] + minuend->value[i];
	return;
}

void scale_matrix
(
	const float scalar,
	const Matrix * matrix,
	Matrix * scaled_matrix
) {
	assert(matrix->size == scaled_matrix->size);
	assert(matrix->length == scaled_matrix->length);

	for (unsigned int i = 0;i < scaled_matrix->size * scaled_matrix->length;i++)
		scaled_matrix->value[i] = scalar * matrix->value[i];
	return;
}

void multiply_matrix_entrywise
(
	const Matrix * first_factor,
	const Matrix * second_factor,
	Matrix * product
) {
	assert(first_factor->size == second_factor->size);
	assert(first_factor->length == second_factor->length);
	assert(second_factor->size == product->size);
	assert(second_factor->length == product->length);

	for (unsigned int i = 0;i < product->size * product->length;i++)
		product->value[i] = first_factor->value[i] * second_factor->value[i];
	return;
}

void divide_matrix_entrywise
(
	const Matrix * dividend,
	const Matrix * divisor,
	Matrix * quotient
) {
	assert(dividend->size == divisor->size);
	assert(dividend->length == divisor->length);
	assert(divisor->size == quotient->size);
	assert(divisor->length == quotient->length);

	for (unsigned int i = 0;i < quotient->size * quotient->length;i++)
		quotient->value[i] = dividend->value[i] / divisor->value[i];
	return;
}

void multiply_vector_and_matrix
(
	const Vector * first_factor,
	const Matrix * second_factor,
	Vector * product
) {
	assert(first_factor->size == second_factor->size);
	assert(product->size == second_factor->length);

	for (int i = 0;i < second_factor->length;i++) {
		product->value[i] = 0.0f;
		for (int j = 0;j < second_factor->size;j++)
			product->value[i] += first_factor->value[j] * second_factor->value[i * second_factor->size + j];
	}
	return;
}

void multiply_vector_transformed_matrix
(
	const Vector * first_factor,
	const Matrix * second_factor,
	Vector * product
) {
assert(first_factor->size == second_factor->length);
assert(product->size == second_factor->size);

	for (int i = 0;i < second_factor->size;i++) {
		product->value[i] = 0.0f;
		for (int j = 0;j < second_factor->length;j++)
			product->value[i] += first_factor->value[j] * second_factor->value[j * second_factor->size + i];
	}
	return;
}

void multiply_vector
(
	const Vector * first_factor,
	const Vector * second_factor,
	Matrix * product
) {
	assert(first_factor->size == product->size);
	assert(second_factor->size == product->length);

	for (int i = 0;i < product->size;i++)
		for (int j = 0;j < product->size;j++)
			product->value[i * product->size + j] = first_factor->value[i] * second_factor->value[j];
	return;
}

Matrix * malloc_matrix_array
(
	unsigned int size,
	unsigned int length,
	unsigned int number_of_matrixes
) {
	Matrix * matrix = reallocarray(NULL, number_of_matrixes, sizeof(Vector));
	if (matrix == NULL)
		err(EXIT_SUCCESS, "could not allocate vector array");

	float * array = reallocarray(NULL, size * length * number_of_matrixes, sizeof(float));
	if (array == NULL)
		err(EXIT_SUCCESS, "could not allocate vector array");

	for (int i = 0;i < length;i++) {
		matrix[i].size = size;
		matrix[i].length = length;
		matrix[i].value = array + i * size * length;
	}

	return matrix;
}

void free_matrix_array
(
	Matrix * matrix_array
) {
	free(matrix_array[0].value);
	free(matrix_array);
	return;
}
