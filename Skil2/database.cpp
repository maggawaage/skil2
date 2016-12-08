#include "database.h"
#include <QtSql>

Database::Database()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "/Users/isabellayr/Desktop/HR/Verk2/skil2/Skil2/Db.sqlite"; //eg thurfti ad nota full path til ad fa thetta til ad virka
    _db.setDatabaseName(dbName);
    _db.open();
}

void Database::quit()
{
    _db.close();
}

