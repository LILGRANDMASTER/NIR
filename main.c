#include <stdio.h>
#include <stdlib.h>
#include "Neural_Network.h"


int main()
{
	t_neural_network* nn = neural_network_create(4, 5, 2);

	weights_init(nn);

	for(int i = 0; i < nn -> hidden_size; i++)
	{
		for(int j = 0; j < (nn -> input_size + 1); j++)
		{
			printf("%f\t", nn -> w_hidden[i][j]);
		}
		printf("\n");
	}

	neural_network_destroy(nn);
	return 0;
}