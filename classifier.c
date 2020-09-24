#include "classifier.h"

/*
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
*/

static void initialize_layer
(
	Layer * layer,
	unsigned int input_size,
	unsigned int output_size
) {
	unsigned int input_and_hidden_size = input_size + output_size;

	layer->input_and_hidden_size = input_and_hidden_size;
	layer->output_size = output_size;

	Matrix * matrix_array = malloc_matrix_array(input_and_hidden_size, output_size, 4);
	Vector * vector_array = malloc_vector_array(input_and_hidden_size, 4);

	layer->forget_weight = matrix_array + 0;
	layer->input_weight = matrix_array + 1;
	layer->output_weight = matrix_array + 2;
	layer->cell_weight = matrix_array + 3;

	layer->forget_bias = vector_array + 0;
	layer->input_bias = vector_array + 1;
	layer->output_bias = vector_array + 2;
	layer->cell_bias = vector_array + 3;

	return;
}

Classifier * malloc_classifier
(
	unsigned int *layer_size,
	unsigned int number_of_layers,
	float learnrate
) {
	Classifier * new_classifier = reallocarray(NULL, 1, sizeof(Classifier));
	if (new_classifier == NULL)
		err(EXIT_FAILURE, "could not allocate classifier");

	new_classifier->learnrate = learnrate;

	new_classifier->layer = reallocarray(NULL, number_of_layers - 1, sizeof(Layer));
	if (new_classifier == NULL)
		err(EXIT_FAILURE, "could not allocate classifier");

	for (int i = 0;i < number_of_layers - 1;i++)
		initialize_layer(new_classifier->layer + i, layer_size[i], layer_size[i + 1]);
	return new_classifier;
}

void classify
(
	Classifier * classifier,
	Vector * input,
	Vector * output,
	unsigned int size
) {

}
