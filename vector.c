#include "vector.h"

Vector * malloc_vector
(
	const unsigned int size
) {
	Vector * new_vector = reallocarray(NULL, 1, sizeof(Vector));
	if (new_vector == NULL)
		err(EXIT_SUCCESS, "could not allocate vector");

	new_vector->size = size;
	new_vector->value = reallocarray(NULL, size, sizeof(float));
	if (new_vector == NULL)
		err(EXIT_SUCCESS, "could not allocate vector");
	return new_vector;
}

void free_vector
(
	Vector * vector
) {
	free(vector->value);
	free(vector);
	return;
}

void zero_vector
(
	Vector * vector
) {
	for(unsigned int i = 0;i < vector->size;i++)
		vector->value[i] = 0.0f;
	return;
}

static float randf
(
	void
) {
	return (float) rand() / ((float) RAND_MAX) * 2.0f - 1.0f;
}

void randomize_vector
(
	Vector * vector
) {
	for (unsigned i = 0;i < vector->size;i++)
		vector->value[i] = randf();
	return;
}

void copy_vector
(
	const Vector * source,
	Vector * destination
) {
	assert(source->size == destination->size);

	for (unsigned int i = 0;i < destination->size;i++)
		destination->value[i] = source->value[i];
	return;
}

void add_vector
(
	const Vector * first_summand,
	const Vector * second_summand,
	Vector * sum
) {
	assert(first_summand->size == second_summand->size);
	assert(second_summand->size == sum->size);

	for (unsigned int i = 0;i < sum->size;i++)
		sum->value[i] = first_summand->value[i] + second_summand->value[i];
	return;
}

void subtract_vector
(
	const Vector * minuend,
	const Vector * subtrahend,
	Vector * difference
) {
	assert(minuend->size == subtrahend->size);
	assert(subtrahend->size == difference->size);

	for (unsigned int i = 0;i < subtrahend->size;i++)
		difference->value[i] = subtrahend->value[i] + minuend->value[i];
	return;
}

void scale_vector
(
	const float scalar,
	const Vector * vector,
	Vector * scaled_vector
) {
	assert(vector->size == scaled_vector->size);

	for (unsigned int i = 0;i < scaled_vector->size;i++)
		scaled_vector->value[i] = scalar * vector->value[i];
	return;
}

void multiply_vector_entrywise
(
	const Vector * first_factor,
	const Vector * second_factor,
	Vector * product
) {
	assert(first_factor->size == second_factor->size);
	assert(second_factor->size == product->size);

	for (unsigned int i = 0;i < product->size;i++)
		product->value[i] = first_factor->value[i] * second_factor->value[i];
	return;
}

void divide_vector_entrywise
(
	const Vector * dividend,
	const Vector * divisor,
	Vector * quotient
) {
	assert(dividend->size == divisor->size);
	assert(divisor->size == quotient->size);

	for (unsigned int i = 0;i < quotient->size;i++)
		quotient->value[i] = dividend->value[i] / divisor->value[i];
	return;
}

void function_on_vector
(
	const Vector * input,
	float (*function)(float),
	Vector * output
) {
	assert(input->size == output->size);

	for (unsigned int i = 0;i < output->size;i++)
		output->value[i] = function(input->value[i]);
	return;
}

void normalize_vector
(
	const Vector * input,
	Vector * output
) {
	assert(input->size == output->size);

	float sum = 0.0;

	for (int i = 0;i < input->size;i++)
		sum += input->value[i] * input->value[i];

	for (unsigned int i = 0;i < output->size;i++)
		output->value[i] = input->value[i] / sum;
	return;
}

Vector * malloc_vector_array
(
	unsigned int size,
	unsigned int number_of_vectors
) {
	Vector * vector = reallocarray(NULL, number_of_vectors, sizeof(Vector));
	if (vector == NULL)
		err(EXIT_SUCCESS, "could not allocate vector array");

	float * array = reallocarray(NULL, size * number_of_vectors, sizeof(float));
	if (array == NULL)
		err(EXIT_SUCCESS, "could not allocate vector array");

	for (int i = 0;i < number_of_vectors;i++) {
		vector[i].size = size;
		vector[i].value = array + i * size;
	}

	return vector;
}

void free_vector_array
(
	Vector * vector_array
) {
	free(vector_array[0].value);
	free(vector_array);
	return;
}
