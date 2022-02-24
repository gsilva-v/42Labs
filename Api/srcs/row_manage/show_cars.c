#include <api.h>

extern t__db_config	g_db_config;

void	show_cars(struct mg_connection *c)
{

	int status = 200;
	if (mysql_query(g_db_config.conn, "SELECT * FROM cars"))
		status = 500;
	MYSQL_RES *result = mysql_store_result(g_db_config.conn);
	MYSQL_ROW row;
	
	int num_fields = mysql_num_fields(result);
	
	int first = 1;
	char *buffer = strdup("{");
	
	while ((row = mysql_fetch_row(result)))
	{
		if (!first)
			buffer = ft_strjoin(buffer, ", ");
		buffer = ft_strjoin(buffer, "{");
		for(int i = 0; i < num_fields; i++)
			buffer = formate_to_json(buffer, i, row[i]);
		first = 0;
		buffer = ft_strjoin(buffer, "}");
	}
	buffer = ft_strjoin(buffer, "}");
	if (status != 500)
	{
		char *response = strdup(buffer);
		mg_http_reply(c, status, NULL, response);
		add_log("GET", "/cars", response, status);
		free(response);
	}
	else
	{
		char response[1024];
		sprintf(response, "{\"status\": %d}", status);
		mg_http_reply(c, status, NULL, response);
		add_log("GET", "/cars", response, status);
	}
	mysql_free_result(result);
	free(buffer);
}