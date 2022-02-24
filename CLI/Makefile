NAME = cli

CC = gcc
INCLUDE = -I ./includes/
CFLAGS = -g $(INCLUDE) -Wall -Werror -Wextra

RM = rm -rf

PATH_SRCS = ./srcs/
PATH_MAIN = $(PATH_SRCS)main/
PATH_GNL = $(PATH_SRCS)gnl/
PATH_SHOW = $(PATH_SRCS)show_log/

PATH_OBJS = ./objs/

SRCS =  $(PATH_MAIN)main.c\
		$(PATH_GNL)gnl.c\
		$(PATH_SHOW)show_log.c

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(PATH_OBJS)*/*.o -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
		@mkdir -p $(PATH_OBJS)
		@mkdir -p $(PATH_OBJS)show_log
		@mkdir -p $(PATH_OBJS)gnl
		@mkdir -p $(PATH_OBJS)main
	    $(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(PATH_OBJS) clean fclean re