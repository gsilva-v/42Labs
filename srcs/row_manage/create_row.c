#include <api.h>

extern t__db_config	g_db_config;

void	create_row(char *table, char *key, char *value)
{
	char buffer[1024];
	sprintf(buffer, "INSERT INTO %s(%s) VALUES(%s)", table, key, value);
	printf ("%s\n", buffer);
	if (mysql_query(g_db_config.conn, buffer))
		printf("invalid car\n");
}