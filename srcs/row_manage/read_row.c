#include <api.h>

extern t__db_config	g_db_config;

void	read_row(struct mg_connection *c, int id)
{
	char response[1024];
	char statement[500];
	char *buffer = strdup("{");
	char *converted_id = ft_itoa(id);
	char *route = ft_strjoin(strdup("/char/"), converted_id);
	int status = 200;
	
	sprintf(statement, "SELECT * FROM cars WHERE id=%s", converted_id);
	if (mysql_query(g_db_config.conn, statement))
		status = 500;

	MYSQL_RES *result = mysql_store_result(g_db_config.conn);
	MYSQL_ROW row = mysql_fetch_row(result);
	int num_fields = mysql_num_fields(result);

	for(int i = 0; i < num_fields && row; i++)
		buffer = formate_to_json(buffer, i, row[i]);
	buffer = ft_strjoin(buffer, "}");
	if (status != 500)
	{
		sprintf(response, "%s", buffer);
		mg_http_reply(c, status, NULL, "%s", buffer);
	}
	else
	{
		sprintf(response, "{\"status\": %d}", status);
		mg_http_reply(c, status, NULL, "%s", response);
	}
	add_log("GET", route, response, status);
	mysql_free_result(result);
	free(converted_id);
	free(buffer);
	free(route);
}	
