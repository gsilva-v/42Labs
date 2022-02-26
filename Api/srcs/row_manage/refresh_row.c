#include <api.h>

extern t__db_config	g_db_config;

char	*get_old_values(int id)
{
	char		statement[500];
	char		*converted_id = ft_itoa(id);
	char		*buffer = strdup("{");

	sprintf(statement, "SELECT * FROM cars WHERE id=%s", converted_id);
	mysql_query(g_db_config.conn, statement);		
	MYSQL_RES	*result = mysql_store_result(g_db_config.conn);
	MYSQL_ROW	row = mysql_fetch_row(result);

	int			num_fields = mysql_num_fields(result);

	for(int i = 0; i < num_fields && row; i++)
		buffer = formate_to_json(buffer, i, row[i]);
	buffer = ft_strjoin(buffer, "}");
	return(buffer);
}


int	update_row(char *table, int id, char *new_values)
{
	char	buffer[1024];

	sprintf(buffer, "UPDATE %s SET %s WHERE id=%d",  table, new_values, id);
	if (mysql_query(g_db_config.conn, buffer))
		return (1);
	return (0);
}

void refresh_row(struct mg_http_message *request, struct mg_connection *conn)
{
	t_car	car;
	int		status = 200;
	char	values[250];
	char	route[110];
	char	response[1024];
	int		id = atoi(&request->method.ptr[10]);
	char	*buffer = get_old_values(id);

	sprintf(route, "/cars/%d", id);
	if (!strcmp(buffer, "{}"))
	{
		sprintf(response, VEHS_NOT_FOUND);
		mg_http_reply(conn, 404, NULL, "%s", response);	
		add_log("PUT", "/cars", 404);
		free(buffer);
		return ;
	}
	convert_json_to_object(buffer, 2, "name", &car.name, "price", &car.price);
	free(buffer);
	convert_json_to_object(request->body.ptr, 2, "name", &car.name, "price", &car.price);
	sprintf(values, "name = '%s', price = %s", car.name, car.price);
	if (update_row("cars", id, values))
	{
		sprintf(response, "%s", ERROR_REFRESH_DATA);
		mg_http_reply(conn, 500, NULL, response);	
		status = 500;
	}
	else
	{
		sprintf(response, "%s", SUCCESS);
		mg_http_reply(conn, 200, NULL, response);	
	}
	add_log("PUT", route, status);
}
