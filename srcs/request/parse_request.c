#include <api.h>

extern t__db_config	g_db_config;

void	route(struct mg_http_message *request, struct mg_connection *conn)
{
	char	*info;
	char	**key_value;

	if (mg_http_match_uri(request, "/cars") && !strncmp(request->method.ptr, "GET", 3))
		show_cars(conn);
	else if (mg_http_match_uri(request, "/cars/*") && !strncmp(request->method.ptr, "GET", 3))
		read_row(conn, atoi(&request->method.ptr[10]));
	else if (mg_http_match_uri(request, "/cars") && !strncmp(request->method.ptr, "POST", 4))
		input_car(request, conn);
	else if (mg_http_match_uri(request, "/cars/*") && !strncmp(request->method.ptr, "PUT", 3))
		refresh_row(request, conn);
	else if (mg_http_match_uri(request, "/cars/*") && !strncmp(request->method.ptr, "DELETE", 6))
		delete_car(request, conn);
	else
	{
		char response[256];
		sprintf(response, "%s", "{\"status\":\"404\"}");
		mg_http_reply(conn, 404, NULL, response);
		char **matrix = ft_split((char *)request->method.ptr, ' ');
		add_log(matrix[0], matrix[1], response, 404);
		free_matrix(matrix);
	}
}