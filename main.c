#include <stdlib.h>
#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include "sensor_db.h"
#include "config.h"


int main()
{	
	MYSQL *con = init_connection(1);
	return 0;
}
