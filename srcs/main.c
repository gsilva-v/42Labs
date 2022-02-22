#include <api.h>

static int i = 0;

t__db_config	g_db_config;

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	struct mg_http_serve_opts opts = {.root_dir = "."};   // Serve local dir
	int fd = open("log", O_CREAT | O_WRONLY, 0777);
	if (ev == MG_EV_HTTP_MSG) 
  	{
		struct mg_http_message *hm = (struct mg_http_message *) ev_data;
		if (mg_http_match_uri(hm, "/user"))
		{
			char *buf = ft_itoa(i);
			i++;
			write(fd, "/user ", 6);
			write(fd, buf, strlen(buf));
      		mg_http_reply(c, 200, NULL, "%s", "Gabriel");
		}
		else if (mg_http_match_uri(hm, "/cars"))
		{
			char *values = parse_json_values(hm->body.ptr);
			create_row("cars", "name, price", values);
			printf("%s\n", hm->body.ptr);
			mg_http_reply(c, 500, NULL, "%s", "");
		}
			
	}
}

int main(int argc, char *argv[])
{
	struct mg_mgr mgr;
	start_database();	
	mg_mgr_init(&mgr);                                        // Init manager
	mg_http_listen(&mgr, "http://localhost:8000", fn, &mgr);  // Setup listener
	for (;;) mg_mgr_poll(&mgr, 1000);                         // Event loop
	mg_mgr_free(&mgr);                                        // Cleanup
	return 0;
}