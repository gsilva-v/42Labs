#include <api.h>

extern t__db_config	g_db_config;

void	create_table_cars(void)
{
	mysql_query(g_db_config.conn, "DROP TABLE IF EXISTS cars");
	mysql_query(g_db_config.conn, CREATE_TABLE);
}

void	seed_cars(void)
{
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(1,'Audi',52642)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(2,'Mercedes',57127)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(3,'Chevette',9000)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(4,'Volvo',29000)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(5,'Bentley',350000)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(6,'Citroen',21000)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(7,'Hummer',41400)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(8,'Volkswagen',21600)");
}