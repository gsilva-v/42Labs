#include <api.h>

t__db_config	g_db_config;

static void listener(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	(void)fn_data;
	if (ev == MG_EV_HTTP_MSG) 
  	{
		struct mg_http_message *request = (struct mg_http_message *) ev_data;
		route(request, c);
	}
}

int main(void)
{
	struct mg_mgr manager;

	start_database();	
	mg_mgr_init(&manager);                                        // Init manager
	mg_http_listen(&manager, CONNECTOR, listener, &manager);  // Setup listener
	while(true)
		mg_mgr_poll(&manager, 1000);                         // Event loop
	mg_mgr_free(&manager);                                        // Cleanup
	return 0;
}