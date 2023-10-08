#include "Neural_Network.h"

/*
struct Neural_Network
{
	int       input_size;			//размер входных данных
	int       hidden_size;			//кол-во нейронов скрытого слоя
	int 	  output_size;			//кол-во нейронов выходного слоя	

	mat  w_hidden;					//матрица весов скрытого слоя
	mat  w_output;					//матирица весов выходного слоя
};

*/

t_neural_network* neural_network_create(int input_size, int hidden_size, int output_size)
{
	t_neural_network* nn = malloc(sizeof(t_neural_network));
	if(nn == NULL)
		return NULL;

	nn -> input_size = input_size;
	nn -> hidden_size = hidden_size;

	nn -> w_hidden = (mat)malloc(nn -> hidden_size * sizeof(vec));

	//(input_size + 1) т.к добавляем еще bias
	for(int i = 0; i < nn -> hidden_size; i++)
	{
		nn -> w_hidden[i] = (vec)malloc((nn -> input_size + 1) * sizeof(mat_t));
		
		if(nn -> w_hidden == NULL)
			return NULL;
	}


	nn -> w_output = (mat)malloc(nn -> output_size * sizeof(vec));

	for(int i = 0; i < nn -> output_size; i++)
	{
		nn -> w_output[i] = (vec)malloc((nn -> hidden_size + 1) * sizeof(mat_t));

		if(nn -> w_output[i] == NULL)
			return NULL;
	}

	return nn;
}



void neural_network_destroy(t_neural_network* nn)
{
	for(int i = 0; i < nn -> hidden_size; i++)
		free(nn -> w_hidden[i]);


	for(int i = 0; i < nn -> output_size; i++)
		free(nn -> w_output[i]);

	free(nn -> w_hidden);
	free(nn -> w_output);
	free(nn);
}


void weights_init(t_neural_network* nn)
{
	for(int i = 0; i < nn -> hidden_size; i++)
		for(int j = 0; j < (nn -> input_size + 1); j++)
			nn -> w_hidden[i][j] = (j == nn -> input_size) ? 1 : 0;


	for(int i = 0; i < nn -> output_size; i++)
		for(int j = 0; j < (nn -> hidden_size + 1); j++)
			nn -> w_output[i][j] = (j == nn -> hidden_size) ? 1 : 0;		
}

/*
vec evaulate(t_neural_network* nn, vec input_data)
{
	vec hidden_output = mat_x_vec(nn -> w_hidden, input_data);
	vec output = mat_x_vec(nn -> w_output, hidden_output);
}

*/