#include <stdlib.h>
#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include "sensor_db.h"
#include "config.h"

/*
 * Make a connection to MySQL database
 * Create a table named 'yourname' if the table does not exist
 * If the table existed, clear up the existing data if clear_up_flag is set to 1
 * return the connection for success, NULL if an error occurs
 */

MYSQL *init_connection(char clear_up_flag)
{
	MYSQL *con = mysql_init(NULL);
	char *tableName = "ShaoMing";
	
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      return NULL;
  }

  if (mysql_real_connect(con, URL, USERNAME, PASSWORD, 
          DATABASE, 3306, NULL, 0) == NULL) 
  {
      fprintf(stderr, "1error%s\n", mysql_error(con));
      mysql_close(con);
      return NULL;
  }  

	MYSQL_RES *result;
	result = mysql_list_tables(con, tableName);
	if(result == NULL){
	if (mysql_query(con, "CREATE TABLE ShaoMing(id INT PRIMARY KEY AUTO_INCREMENT,sensor_id INT,sensor_value DECIMAL(4,2),timestamp TIMESTAMP)"))
	{
      fprintf(stderr, "2error%s\n", mysql_error(con));
      mysql_close(con);
      return NULL;
	}
	}else
	{
		if(clear_up_flag == 1)
		{
			if (mysql_query(con, "DROP TABLE IF EXISTS ShaoMing"))
			{
				fprintf(stderr, "3error%s\n", mysql_error(con));
				mysql_close(con);
				return NULL;
			}
			if (mysql_query(con, "CREATE TABLE ShaoMing(id INT PRIMARY KEY AUTO_INCREMENT,sensor_id INT,sensor_value DECIMAL(5,2),timestamp TIMESTAMP)"))
			{      
				fprintf(stderr, "4error%s\n", mysql_error(con));
				mysql_close(con);
				return NULL;
			}
			mysql_free_result(result);
		}else
			mysql_free_result(result);
	}
	printf("connected!");
	mysql_close(con);
	return con;
	}

///*
 //* Disconnect MySQL database
 //*/
//void disconnect(MYSQL *conn)
//{
	
	//}

///*
 //* Write an INSERT query to insert a single sensor measurement
 //* return zero for success, and non-zero if an error occurs
 //*/

//int insert_sensor(MYSQL *conn, sensor_id_t id, sensor_value_t value, sensor_ts_t ts)
//{
	//return NULL;
	//}

///*
 //* Write an INSERT query to insert all sensor measurements existed in the file pointed by sensor_data
 //* return zero for success, and non-zero if an error occurs
 //*/

//int insert_sensor_from_file(MYSQL *conn, FILE *sensor_data)
//{
	//return NULL;
	//}

///*
 //* Write a SELECT query to return all sensor measurements existed in the table
 //* return MYSQL_RES with all the results
 //*/

//MYSQL_RES *find_sensor_all(MYSQL *conn)
//{
	//return NULL;
	//}

///*
 //* Write a SELECT query to return all sensor measurements containing 'value_t'
 //* return MYSQL_RES with all the results
 //*/

//MYSQL_RES *find_sensor_by_value(MYSQL *conn, sensor_value_t value_t)
//{
	//return NULL;
	//}

///*
 //* Write a SELECT query to return all sensor measurement that its value exceeds 'value_t'
 //* return MYSQL_RES with all the results
 //*/
//MYSQL_RES *find_sensor_exceed_value(MYSQL *conn, sensor_value_t value_t)
//{
	//return NULL;
	//}

///*
 //* Write a SELECT query to return all sensor measurement containing timestamp 'ts_t'
 //* return MYSQL_RES with all the results
 //*/
//MYSQL_RES *find_sensor_by_timestamp(MYSQL *conn, sensor_ts_t ts_t)
//{
	//return NULL;
	//}

///*
 //* Write a SELECT query to return all sensor measurement recorded later than timestamp 'ts_t'
 //* return MYSQL_RES with all the results
 //*/
//MYSQL_RES *find_sensor_later_timestamp(MYSQL *conn, sensor_ts_t ts_t)
//{
	//return NULL;
	//}

///*
 //* Return the number of records contained in the result
 //*/
//int get_result_size(MYSQL_RES *result)
//{
	//return NULL;
	//}

///*
 //* Print all the records contained in the result
 //*/
//void print_result(MYSQL_RES *result)
//{
	
	//}
