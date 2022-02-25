#include <cli.h>


int wait_cmd(char *buffer, int id)
{
	FILE	*file;
	if (buffer)
	{
		if (!strncmp(buffer, "show", 4))
		{
			file = fopen("../logs/log.txt", "r");
			id = show_log(file, 0);
			fclose(file);	
		}
		else if (!strncmp(buffer, "exit", 4))
		{
			free(buffer);
			exit(0);
		}	
		else if (!strncmp(buffer, "clean", 5))
			system("clear");
		else if (!strncmp(buffer, "att", 3))
			id = refresh(id);
		free(buffer);
	}
	return (id);
}

int	main(void)
{
	char	*buffer;
	static int id = 0;

	system("clear");
	while (true)
	{
		write(1, "[input command] ", 17);
		buffer = get_next_line(STDIN_FILENO);
		id = wait_cmd(buffer, id);
	}

	return (0);
}