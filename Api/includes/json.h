#ifndef JSON_H
# define JSON_H
# include <stdarg.h>
# include <strings.h>
# include <api.h>

/*
    @brief            Convert a json object to a C struct.
    @param            json_obj
    @param            qnt_prop (how many properties you will pass)
    @param            ... (the name of the property, address where the value will be stored)
    @param            example: convert_json_to_object("{\"name\": \"flavio\", \"age\": \"19\"}", 2, "name", &user.name, "age", &user.age)
*/
void	convert_json_to_object(const char *json_obj, int qnt_prop, ...);

#endif