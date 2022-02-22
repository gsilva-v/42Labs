#ifndef API_H
# define API_H
# include <stdio.h>
# include <mongoose.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <mysql/mysql.h>

typedef struct s_db_config{
	char			*host;
	char			*user;
	char			*pass;
	char			*dbname;
	unsigned int	port;
	char			*unix_socket;
	int				flag;
	MYSQL			*conn;
}	t__db_config;

// typedef struct s_post_car{
// 	char	*key_price;
// 	char	*value;
// }	t_post_car;

// DataBase
void	start_database(void);
void	create_table_cars(void);
void	seed_cars(void);


// Row Manage
void	create_row(char *table, char *key, char *value);


// Parse JSON
char	*parse_json_values(const char *json_obj);
char	*put_quotes_in_string(char *values);

// Utils
int		strlen_quote(char *string);
char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif