#include <api.h>

void	show_documentation(struct mg_http_message *request, struct mg_connection *conn)
{
	char	response[1024];
	int		status = 200;

	sprintf(response, "{\"status\":\"200\", \"message\": %s", README_LINK);
	mg_http_reply(conn, status, NULL, response);
	char **matrix = ft_split((char *)request->method.ptr, ' ');
	add_log(matrix[0], matrix[1], 200);
	free_matrix(matrix);
}
