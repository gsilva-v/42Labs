#include <api.h>

extern t__db_config	g_db_config;

int	create_row(char *table, char *key, char *value)
{
	char	buffer[1024];

	sprintf(buffer, "INSERT INTO %s(%s) VALUES(%s)",  table, key, value);
	if (mysql_query(g_db_config.conn, buffer))
		return (1);
	return (0);
}

void input_car(struct mg_http_message *request, struct mg_connection *conn)
{
	t_car	car;
	char	keys[250];
	char	values[250];
	char	response[1024];
	int		status;
	
	bzero(&car, sizeof(car));
	convert_json_to_object(request->body.ptr, 2, "name", &car.name, "price", &car.price);
	if (!car.name || !car.price)
	{
		sprintf(response, "%s", CREATE_INTRUCTION);
		mg_http_reply(conn, 500, NULL, response);
		status = 500;
	}
	else
	{
		sprintf(keys, "%s, %s", "name", "price");
		sprintf(values, "'%s', %s", car.name, car.price);
		if (create_row("cars", keys, values))
		{
			sprintf(response,  "%s", ERROR_REGISTER_DATA);
			mg_http_reply(conn, 500, NULL, response);
			status = 500;
		}
		else
		{
			sprintf(response, "%s", SUCCESS);
			mg_http_reply(conn, 200, NULL, response);	
			status = 200;
		}
	}
	add_log("POST", "/cars", status);
}
