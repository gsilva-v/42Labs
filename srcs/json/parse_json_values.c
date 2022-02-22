#include <api.h>

char	*parse_json_values(const char *json_obj)
{
	char *values;
	char *buffer;
	char *temp;
	char **matrix_aux;
	
	buffer = strdup(json_obj);
	temp = calloc(1,1);
	values = strdup("");
	matrix_aux = ft_split(buffer, ',');
	int j = 0;
	for (int i = 0; matrix_aux[i]; i++)
	{
		j = 0;
		if (i != 0)
			values = ft_strjoin(values, ",");
		while (matrix_aux[i][j] && matrix_aux[i][j] != ':')
			j++;
		j++;
		while (matrix_aux[i][j] && (matrix_aux[i][j] == ' ' ||  matrix_aux[i][j] == '\"'))
			j++;
		temp = strndup(&matrix_aux[i][j], strlen_quote(&matrix_aux[i][j]));
		temp = ft_strjoin(strdup("'"), temp);
		temp = ft_strjoin(temp, "'");
		values = ft_strjoin(values, temp);
		free(temp);
	}
	printf("%s\n", values);
	return(values);
}