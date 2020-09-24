#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <err.h>
#include <assert.h>

typedef struct
{
	unsigned int size;
	float * value;
} Vector;

Vector * malloc_vector(const unsigned int);
void free_vector(Vector *);
void zero_vector(Vector *);
void randomize_vector(Vector *);
void copy_vector(const Vector *, Vector *);
void add_vector(const Vector *, const Vector *, Vector *);
void subtract_vector(const Vector *, const Vector *, Vector *);
void scale_vector(const float, const Vector *, Vector *);
void multiply_vector_entrywise(const Vector *, const Vector *, Vector *);
void divide_vector_entrywise(const Vector *, const Vector *, Vector *);
void function_on_vector(const Vector *, float (*)(float), Vector *);
void normalize_vector(const Vector *, Vector *);

Vector *malloc_vector_array(unsigned int, unsigned int);
void free_vector_array(Vector *);

#endif /* VECTOR_H */
