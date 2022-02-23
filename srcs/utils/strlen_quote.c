#include <api.h>

int	strlen_quote(char *string)
{
	for (int i = 0; string[i]; i++)
	{
		if (string[i] == '\"' || string[i] == '}')
			return (i);
	}
	return (-1);
}