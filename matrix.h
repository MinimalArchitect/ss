#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <assert.h>
#include <err.h>

#include "vector.h"

typedef struct
{
	size_t	size;
	size_t	length;
	float *	value;
} Matrix;

Matrix * malloc_matrix(const size_t, const size_t);
void free_matrix(Matrix *);
void zero_matrix(Matrix *);
void randomize_matrix(Matrix *);
void copy_matrix(const Matrix *, Matrix *);
void add_matrix(const Matrix *, const Matrix *, Matrix *);
void subtract_matrix(const Matrix *, const Matrix *, Matrix *);
void scale_matrix(const float, const Matrix *, Matrix *);
void multiply_matrix_entrywise(const Matrix *, const Matrix *, Matrix *);
void divide_matrix_entrywise(const Matrix *, const Matrix *, Matrix *);

void multiply_vector_and_matrix(const Vector *, const Matrix *, Vector *);
void multiply_vector_transformed_matrix(const Vector *, const Matrix *, Vector *);
void multiply_vector(const Vector *, const Vector *, Matrix *);

Matrix *malloc_matrix_array(unsigned int, unsigned int, unsigned int);
void free_matrix_array(Matrix *);

#endif /* MATRIX_H */
