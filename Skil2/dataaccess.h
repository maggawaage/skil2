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
    vector<Person> fillVector(vector<Person>famousComputerphiles);
    void addPerson(string name, char gender, int birthYear, int deathYear);

    vector<Person> parsePersonLine(QSqlQuery& line);
    vector<Person> DataAlpha();
    vector<Person> DataReAlpha();
    vector<Person> DataYear();
    vector<Person> DataReYear();
    vector<Person> DataGender();
    vector<Person> DataReGender();
    vector<Person> DataDeath();
    vector<Person> DataReDeath();

    void editName(string trueName, string name);
    void editGender(string trueName, char gender);
    void editBirthYear(string trueName, int birthYear);
    void editDeathYear(string trueName, int deathYear);
    void deletePerson(string trueName);

    //--------Computer----------

    vector<Computer> fillVector(vector<Computer>famousComputers);
    void addComputer(string name, string type, int buildYear);

    vector<Computer> parseComputerLine(QSqlQuery& query);
    vector<Computer> computerAlpha();
    vector<Computer> computerReAlpha();
    vector<Computer> computerType();
    vector<Computer> computerReType();
    vector<Computer> computerBuildYear();
    vector<Computer> computerReBuildYear();

    void editComputerName(string trueName, string name);
    void editType(string trueName, string type);
    void editBuildYear(string trueName, int buildYear);
    void deleteComputer(string trueName);

    void linkPersonToComputer(int Person_ID, int Computer_ID);
    void deleteConnection(int PersonID, int ComputerID);
    void deleteConnectionComputer(int ComputerID);
    void deleteConnectionPerson(int PersonID);

    vector<Person> getPersonsConnectedToComputers(int id);
    vector<Computer> getComputersConnectedToPersons(int id);

    int getPersonIdByName(string name);
    int getComputerIdByName(string name);


private:
    QSqlDatabase _runningDB;
    QSqlDatabase _query;
};
#endif // DATAACCESS_H
