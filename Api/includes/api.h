#ifndef API_H
# define API_H
# include <mongoose.h>
# include <mysql/mysql.h>
# include <json.h>
# include <defines.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>

/*
	@brief	This is database configuration
*/
typedef struct s_db_config{
	char			*host;			// Host of api
	char			*user;			// User who manages the database
	char			*pass;			// The password of connection 
	char			*dbname;		// The name of database
	unsigned int	port;			// The door that allows access
 	char			*unix_socket;
	int				flag;
	MYSQL			*conn;			// The connection 
}	t__db_config;

typedef struct s_car
{
    char    *name;
    char    *price;
} t_car;

//-------- DATABASE --------//
/*
	@brief This function start connection with DataBase, restart the main table if exist and seed the new table with some values 
*/
void	start_database(void);
/*
	@brief This function restart the main table
*/
void	create_table_cars(void);
/*
	@brief This function seed this main table in start
*/
void	seed_cars(void);

//-------- FINISH DATABASE --------//
//-------- ROW MANAGE --------//
/*
	@brief This function show link of documentation when the client entry in path /
*/
void	show_documentation(struct mg_http_message *request, struct mg_connection *conn);
int		create_row(char *table, char *key, char *value);
void	show_cars(struct mg_connection *c);
void	read_row(struct mg_connection *c, int id);
void input_car(struct mg_http_message *request, struct mg_connection *conn);
void refresh_row(struct mg_http_message *request, struct mg_connection *conn);
void delete_car(struct mg_http_message *request, struct mg_connection *conn);

//-------- FINISH ROW MANAGE --------//
//-------- ROUTE --------//
/*
	@brief This function manages what the API does, when to do it.
*/
void	route(struct mg_http_message *request, struct mg_connection *c);

//-------- FINISH ROUTE --------//
//-------- PARSE JSON --------//
/*
	@brief This function parse only json values and return values prepared to insert in row
	@param Receive the full JSON object to parse this.
*/
char	*formate_to_json(char *buffer, int i, char *row);

//-------- FINISH PARSE JSON --------//
//-------- LOG --------//

/*
	@brief This function manage the log file.
*/
void	add_log(char *method, char *route, int status);

//-------- FINISH LOG --------//


//-------- UTILS --------//

char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	free_matrix(char **matrix);

//-------- FINISH UTILS --------//

#endif // !defined(API_H)