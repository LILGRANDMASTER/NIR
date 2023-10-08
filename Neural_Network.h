#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_

#include <stdlib.h>
#include <math.h>

#define SIGMOID(x) 	1.0 / (1 + exp(x))
#define RELU(x)		fmax(0, x)

typedef double** 	mat;
typedef double* 	vec;
typedef double		mat_t;


struct Neural_Network
{
	int       input_size;			//размер входных данных
	int       hidden_size;			//кол-во нейронов скрытого слоя
	int 	  output_size;			//кол-во нейронов выходного слоя	

	mat  w_hidden;					//матрица весов скрытого слоя
	mat  w_output;					//матирица весов выходного слоя
};

typedef struct Neural_Network t_neural_network;


//Конструктор нейронной сети
//input_size 		- размер входных данных
//hidden_layer_size - кол-во нейронов скрытого слоя
//output_size 		- кол-во нейронов выходного слоя
t_neural_network* neural_network_create(int input_size, int hidden_size, int output_size);

//Деструктор неронной сети
void neural_network_destroy(t_neural_network* nn);

//Прямой проход по сети
vec evaulate(t_neural_network* nn, vec input_data);

void weights_init(t_neural_network* nn);

//TODO: loss function
//TODO: Matrix multiplication
//TODO: forward propogation
//TODO: back propogation
//TODO: initialize weights





#endif