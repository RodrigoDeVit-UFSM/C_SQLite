#include <stdio.h>
#include <stdlib.h>
#include <C:\sqlite\sqlite3.h>

void Create_Table(char* sql)
{
    sqlite3* DB;
    /*std::string sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";*/
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql, NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        printf("Error Create Table or Existing Table\n");
        sqlite3_free(messaggeError);
    }
    else
        printf("Table created Successfully\n");
    sqlite3_close(DB);
}

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}

void Insert_and_Delete(void)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("example.db", &DB);
    char* query = "SELECT * FROM PERSON;";
  
    puts("STATE OF TABLE BEFORE INSERT");
  
    sqlite3_exec(DB, query, callback, NULL, NULL);
  
    char* sql = "INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
                "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
                "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);";
  
    exit = sqlite3_exec(DB, sql, NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        puts("Error Insert");
        sqlite3_free(messaggeError);
    }
    else
        puts("Records created Successfully!");
  
    puts("STATE OF TABLE AFTER INSERT");
  
    sqlite3_exec(DB, query, callback, NULL, NULL);
  
    char* sql1 = "DELETE FROM PERSON WHERE ID = 2;";
    exit = sqlite3_exec(DB, sql1, NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        puts("Error DELETE");
        sqlite3_free(messaggeError);
    }
    else
        puts("Record deleted Successfully!");
  
    puts("STATE OF TABLE AFTER DELETE OF ELEMENT");
    sqlite3_exec(DB, query, callback, NULL, NULL);
  
    sqlite3_close(DB);
}

void Select(void)
{
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);
    char* data = "CALLBACK FUNCTION";
  
    char* sql = "SELECT * FROM PERSON;";
    if (exit) {
        printf("Error open DB %s\n", sqlite3_errmsg(DB));
        return (-1);
    }
    else
        puts("Opened Database Successfully!");
  
    int rc = sqlite3_exec(DB, sql, callback, data, NULL);
  
    if (rc != SQLITE_OK)
        puts("Error SELECT");
    else {
        puts("Operation OK!");
    }
  
    sqlite3_close(DB);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);
  
    if (exit) {
        printf("Error open DB %s \n", sqlite3_errmsg(DB));
        return (-1);
    }
    else
        printf("Opened Database Successfully!\n");
    char* sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";
    
    sqlite3_close(DB);
    Create_Table(sql);
    Insert_and_Delete();
    Select();
    return (0);
}

