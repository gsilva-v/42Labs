#include <api.h>

extern t__db_config	g_db_config;

void	start_database(void)
{
	g_db_config.dbname = "api";
	g_db_config.port = 3306;
	g_db_config.pass = "Batatinha123.-.";
	g_db_config.user = "gsilva-v";
	g_db_config.host = "localhost";
	g_db_config.unix_socket = NULL;
	g_db_config.flag = 0;
	g_db_config.conn = mysql_init(NULL);
	if(!(mysql_real_connect(g_db_config.conn, g_db_config.host, g_db_config.user, g_db_config.pass, \
		g_db_config.dbname, g_db_config.port, g_db_config.unix_socket, g_db_config.flag)))
	{
		fprintf(stderr, "failed connection to database! ( %s [%d] )\n", \
		mysql_error(g_db_config.conn), mysql_errno(g_db_config.conn));
		exit (404);
	}
	create_table_cars();
	seed_cars();
}
