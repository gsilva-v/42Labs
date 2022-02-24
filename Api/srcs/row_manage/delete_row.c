#include <api.h>

extern t__db_config	g_db_config;


int	delete_row(char *table, int id)
{
	char buffer[1024];
	sprintf(buffer, "DELETE FROM %s WHERE id=%d", table, id);
	if (mysql_query(g_db_config.conn, buffer))
		return (1);
	return (0);
}

void delete_car(struct mg_http_message *request, struct mg_connection *conn)
{
	char	buffer[110];
	char	response[200];
	int		id = atoi(&request->method.ptr[13]);
	int		status = 200;

	sprintf(buffer, "/cars/%d", id);
	if (delete_row("cars", id))
	{
		sprintf(response, "%s", ERROR_DELETE);
		mg_http_reply(conn, 500, NULL, response);
		status = 500;
	}
	else
	{
		sprintf(response, "%s", SUCCESS);
		mg_http_reply(conn, 200, NULL, response);
	}
	add_log("DELETE", buffer, status);
}
