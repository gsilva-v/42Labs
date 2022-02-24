#include <api.h>

void	add_log(char *method, char *route, int status)
{
    time_t curtime;
    FILE *file_log = fopen("../logs/log.txt", "a");

    time(&curtime);
    if (file_log != NULL)
    {
		fprintf(file_log, "Method: %s\n", method);
		fprintf(file_log, "URI: %s\n", route);
        fprintf(file_log, "Time Resquest: %s", ctime(&curtime));
        fprintf(file_log, "Status: %d\n\n", status);
        fclose(file_log);
    }
	
}