#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <string>
#include "person.h"
#include "computer.h"
#include "database.h"
#include <QtSql>
class DataAccess
{
public:
    DataAccess();
    void writeToFile(string name, char gender, int birthYear, int deathYear);
    void writeVectorToFile(vector<Person>famousComputerphiles);
    vector<Person> fillVector(vector<Person>famousComputerphiles);
    vector<Computer> fillVector(vector<Computer>famousComputers);
    void addPerson(string name, char gender, int birthYear, int deathYear);
    void addComputer(string name, string type, int buildYear);

    vector<Person> parseLine(QSqlQuery& line);
    vector<Person> DataAlpha();
    vector<Person> DataReAlpha();
    vector<Person> DataYear();
    vector<Person> DataReYear();
    vector<Person> DataGender();
    vector<Person> DataReGender();
    vector<Person> DataDeath();
    vector<Person> DataReDeath();
    void editName(int id, string name);
    void editGender(int id, char gender);
    void editBirthYear(int id, int birthYear);
    void editDeathYear(int id, int deathYear);

    vector<Computer> ParseLine(QSqlQuery& query);
    vector<Computer> dataAlpha();
    vector<Computer> dataReAlpha();
    vector<Computer> dataType();
    vector<Computer> dataReType();
    vector<Computer> dataBuildYear();
    vector<Computer> dataReBuildYear();


private:
    QSqlDatabase _runningDB;
    QSqlDatabase _query;
};
#endif // DATAACCESS_H
