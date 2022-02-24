#include <api.h>

void	free_matrix(char **matrix)
{
	for(int i = 0; matrix[i]; i++)
		free(matrix[i]);
	free(matrix);
}