#ifndef CLI_H
# define CLI_H

# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <stdbool.h>
# include <get_next_line.h>

/*
	@brief This function show all log file in terminal
	@param Get the file log opened
*/
int	show_log(FILE *file, int id);
int	refresh(int id);

#endif