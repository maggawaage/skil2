#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <string>
#include "person.h"
#include "database.h"
#include <QtSql>
class DataAccess
{
public:
    DataAccess();
    void writeToFile(string name, char gender, int birthYear, int deathYear);
    void writeVectorToFile(vector<Person>famousComputerphiles);
    vector<Person> fillVector(vector<Person>famousComputerphiles);
    void testSQLcommand();

private:
    QSqlDatabase _runningDB;
};
#endif // DATAACCESS_H
