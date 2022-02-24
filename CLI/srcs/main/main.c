#include <cli.h>

void wait_cmd(char *buffer)
{
	FILE	*file;

	if (buffer)
	{
		if (!strncmp(buffer, "show", 4))
		{
			file = fopen("../logs/log.txt", "r");
			show_log(file);
			fclose(file);	
		}
		else if (!strncmp(buffer, "exit", 4))
		{
			free(buffer);
			exit(0);
		}	
		free(buffer);
	}
}

int	main(void)
{
	char	*buffer;

	while (true)
	{
		buffer = get_next_line(STDIN_FILENO);
		wait_cmd(buffer);
	}
	return (0);
}