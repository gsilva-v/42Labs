#include <cli.h>

int	refresh(int id)
{
	FILE	*file = fopen("../logs/log.txt", "r");
	char	buffer[300];
	int		divisor = 0;
	int		counter = 0;

	while (counter < id)
	{
		fgets(buffer, 300, file);
		if(divisor == 4)
		{
			counter++;
			divisor = 0;
		}
		else
			divisor++;
	}
	id = show_log(file, id);
	fclose(file);
	return (id);
}

int	show_log(FILE *file, int id)
{
	char buffer[300];
	int divisor = 0;
	
	printf("-------------------------------------------\n\n");
	printf("-------------------------------------------\n");
	while (fgets(buffer, 300, file))
	{
		if (strncmp(buffer, "Status", 6))
			buffer[strlen(buffer)] = '\0';
		printf("| %s", buffer);
		if(divisor == 3)
		{
			printf("| Id Request: %d\n", id);
			printf("-------------------------------------------\n\n");
			printf("-------------------------------------------\n");
			divisor = 0;
			fgets(buffer, 300, file);
			id++;
		}
		else
			divisor++;
	}
	return (id);
}
