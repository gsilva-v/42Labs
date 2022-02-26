NAME = server

CC = gcc
INCLUDE = -I ./includes/ -I /usr/local/mysql/include
CFLAGS = -g $(INCLUDE) -Wall -Werror -Wextra
MYSQL_FLAGS = -L/usr/local/mysql/lib -lmysqlclient

RM = rm -rf

PATH_SRCS = ./srcs/
PATH_DB = $(PATH_SRCS)database/
PATH_JSON = $(PATH_SRCS)json/
PATH_LOG = $(PATH_SRCS)log/
PATH_LIB = $(PATH_SRCS)lib/
PATH_LOG = $(PATH_SRCS)log/
PATH_MAIN = $(PATH_SRCS)main/
PATH_REQ = $(PATH_SRCS)request/
PATH_MNG = $(PATH_SRCS)row_manage/
PATH_UTILS = $(PATH_SRCS)utils/
PATH_OBJS = ./objs/

SRCS =	$(PATH_MAIN)main.c \
		$(PATH_DB)start_database.c $(PATH_DB)create_table.c \
		$(PATH_JSON)json.c $(PATH_JSON)formate_to_json.c \
		$(PATH_LOG)add_log.c \
		$(PATH_LIB)mongoose.c \
		$(PATH_MNG)create_row.c $(PATH_MNG)show_cars.c $(PATH_MNG)read_row.c \
		$(PATH_MNG)refresh_row.c $(PATH_MNG)delete_row.c $(PATH_MNG)show_documentation.c \
		$(PATH_REQ)parse_request.c \
		$(PATH_UTILS)ft_itoa.c $(PATH_UTILS)ft_split.c $(PATH_UTILS)ft_strjoin.c \
		$(PATH_UTILS)free_matrix.c

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ./objs/*/*.o -o $(NAME) $(MYSQL_FLAGS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)database
	@mkdir -p $(PATH_OBJS)json
	@mkdir -p $(PATH_OBJS)main
	@mkdir -p $(PATH_OBJS)log
	@mkdir -p $(PATH_OBJS)lib
	@mkdir -p $(PATH_OBJS)request
	@mkdir -p $(PATH_OBJS)row_manage
	@mkdir -p $(PATH_OBJS)utils
	$(CC) $(CFLAGS) -c $< -o $@ $(MYSQL_FLAGS)

clean: 
	$(RM) $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)	

re: fclean all

.PHONY: all  clean fclean $(PATH_OBJS) re