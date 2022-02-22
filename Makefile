NAME = server

CC = gcc
INCLUDE = -I ./includes/ -I /usr/local/mysql/include
CFLAGS = -g $(INCLUDE)
MYSQL_FLAGS = -L/usr/local/mysql/lib -lmysqlclient

RM = rm -rf

PATH_SRCS = ./srcs/
PATH_DB = $(PATH_SRCS)database/
PATH_JSON = $(PATH_SRCS)json/
PATH_LIB = $(PATH_SRCS)lib/
PATH_MNG = $(PATH_SRCS)row_manage/
PATH_UTILS = $(PATH_SRCS)utils/
PATH_OBJS = ./objs/

SRCS =	$(PATH_SRCS)main.c\
		$(PATH_DB)start_database.c $(PATH_DB)create_table.c\
		$(PATH_JSON)parse_json_values.c\
		$(PATH_LIB)mongoose.c\
		$(PATH_MNG)create_row.c\
		$(PATH_UTILS)ft_itoa.c $(PATH_UTILS)ft_split.c $(PATH_UTILS)ft_strjoin.c\
		$(PATH_UTILS)strlen_quote.c

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ./objs/*/*.o ./objs/*.o -o $(NAME) $(MYSQL_FLAGS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)database
	@mkdir -p $(PATH_OBJS)json
	@mkdir -p $(PATH_OBJS)lib
	@mkdir -p $(PATH_OBJS)row_manage
	@mkdir -p $(PATH_OBJS)utils
	$(CC) $(CFLAGS) -c $< -o $@ $(MYSQL_FLAGS)

clean: 
	$(RM) $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)	

.PHONY: all  clean fclean $(NAME) $(PATH_OBJS)