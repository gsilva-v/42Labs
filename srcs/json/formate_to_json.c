#include <api.h>

char	*formate_to_json(char *buffer, int i, char *row)
{
	char *temp = strdup("");

	if (i == 0)
		temp = ft_strjoin(strdup("\"id\": "), (row));
	if (i == 1)
		temp = ft_strjoin(strdup(", \"name\": \""), (row));
	if (i == 2)
		temp = ft_strjoin(strdup(", \"price\": "), (row));
	buffer = ft_strjoin(buffer, temp);
	if (i == 1)
		buffer = ft_strjoin(buffer, "\"");
	free(temp);
	return(buffer);
}