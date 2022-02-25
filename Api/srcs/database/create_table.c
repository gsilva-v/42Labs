#include <api.h>

extern t__db_config	g_db_config;

void	create_table_cars(void)
{
	mysql_query(g_db_config.conn, "DROP TABLE IF EXISTS cars");
	mysql_query(g_db_config.conn, CREATE_TABLE);
}

void	seed_cars(void)
{
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(1,'Audi A1',79935)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(2,'Audi S6',200000)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(3,'Audi Q7',504990)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(4,'Mercedes GLE400',722900)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(5,'Mercedes C300', 399900)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(6,'Mercedes GLA200', 325900)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(7,'BMW M3', 757950)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(8,'BMW X1', 287950)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(9,'BMW X6', 662950)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(10,'Volkswagen Golf',151530)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(11,'Volkswagen Jetta',178490)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(12,'Volkswagen Passat',177640)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(13,'Toyota Supra',771800)");
	mysql_query(g_db_config.conn, "INSERT INTO cars VALUES(14,'Toyota Hilux',208090)");
}