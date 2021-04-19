// EJERCICIO CLASE
#include <stdio.h>
#include "sqlite/sqlite3.h"
#include <string.h>

int showAllCountries(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, name from country";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int id;
	char name[100];

	printf("\n");
	printf("\n");
	printf("Showing countries:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(name, (char *) sqlite3_column_text(stmt, 1));
			printf("ID: %d Name: %s\n", id, name);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int deleteAllCountry(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from country";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int insertNewCountry(sqlite3 *db, char name[]) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into country (id, name) values (NULL, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, name, strlen(name), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

void ejercicio_de_ejemplo() {
    sqlite3 *db;

	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	result = deleteAllCountry(db);
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = insertNewCountry(db, "France");
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = showAllCountries(db);
	if (result != SQLITE_OK) {
		printf("Error getting all countries\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
}

