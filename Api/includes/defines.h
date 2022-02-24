#ifndef DEFINES_H
# define DEFINES_H

// ROUTES
# define README_LINK "https://github.com/42sp/42labs-selection-process-v2-gsilva-v/blob/main/README.md"
# define SUCCESS "{\"status\":\"200\", \"message\": \"success\"}"
# define CREATE_INTRUCTION "{\"status\":\"500\", \"message\": \"to create a new car, put name and price values\"}"
# define VEHS_NOT_FOUND "{\"status\":\"404\", \"message\": \"error vehicles not found\"}"
# define ERROR_REFRESH_DATA "{\"status\":\"500\", \"message\": \"error to update car in database\"}"
# define ERROR_REGISTER_DATA  "{\"status\":\"500\", \"message\": \"error to register car in database\"}"
# define ERROR_DELETE "{\"status\":\"500\", \"message\": \"error to delete car in database\"}"
// MAIN
# define CONNECTOR "http://localhost:8000"
// DATABASE
# define CREATE_TABLE "CREATE TABLE cars(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255), price INT)"

#endif
