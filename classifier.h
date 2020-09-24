#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <stdlib.h>
#include <math.h>
#include <err.h>

#include "matrix.h"
#include "vector.h"

// all static memory that one layer needs
typedef struct
{
	int input_and_hidden_size;
	int output_size;

	Matrix * forget_weight;
	Vector * forget_bias;
	Matrix * input_weight;
	Vector * input_bias;
	Matrix * output_weight;
	Vector * output_bias;
	Matrix * cell_weight;
	Vector * cell_bias;
} Layer;

// all static memory that the classifier needs
typedef struct
{
	float learnrate;
	Layer * layer;
	int number_of_layers;
} Classifier;

Classifier * malloc_classifier(unsigned int *, unsigned int, float);
void classify(Classifier *, Vector *, Vector *, unsigned int);

#endif /* CLASSIFIER_H */
