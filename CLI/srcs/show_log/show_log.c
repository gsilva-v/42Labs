#include <cli.h>

void	show_log(FILE *file)
{
	char buffer[3000];
	int divisor = 0;
	int id = 0;
	
	printf("-------------------------------------------\n|\n");
	printf("-------------------------------------------\n");
	while (fgets(buffer, 3000, file))
	{
		printf("| %s", buffer);
		if(divisor == 4)
		{
			printf("-------------------------------------------\n");
			printf("| Id Request: %d\n", id);
			printf("-------------------------------------------\n\n");
			printf("-------------------------------------------\n");
			divisor = 0;
			id++;
		}
		else
			divisor++;
	}
}