#include <api.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		n;
	int		s;

	s = 0;
	n = 0;
	new = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[n] != '\0')
	{	
		new[n] = s1[n];
		n++;
	}
	while (s2[s] != '\0')
	{
		new[n + s] = s2[s];
		s++;
	}
	new[n + s] = '\0';
	free(s1);
	return (new);
}