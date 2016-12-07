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
    //void writeToFile(string name, char gender, int birthYear, int deathYear);
    //void writeVectorToFile(vector<Person>famousComputerphiles);
    //vector<Person> fillVector(vector<Person>famousComputerphiles);
    void testSQLcommand();
    vector<Person> alpha();
    vector<Person> reAlpha();
    vector<Person> year();
    vector<Person> reYear();
    vector<Person> gender();
    vector<Person> reGender();
    vector<Person> death();
    vector<Person> reDeath();

private:
    QSqlDatabase _runningDB;
    QSqlDatabase _query;
};
#endif // DATAACCESS_H
