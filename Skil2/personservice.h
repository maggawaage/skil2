#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include "person.h"
#include "dataaccess.h"
using namespace std;

class PersonService
{
public:
    PersonService();

    vector<Person> Alpha();
    vector<Person> reAlpha();
    vector<Person> year();
    vector<Person> reYear();
    vector<Person> gender();
    vector<Person> reGender();
    vector<Person> death();
    vector<Person> reDeath();

    static vector<Person> SearchName(vector<Person> list, string name);
    static vector<Person> SearchGender(vector<Person> list, char gender);
    static vector<Person> SearchBirthYear(vector<Person> list, int birthYear);
    static vector<Person> SearchDeathYear(vector<Person> list, int deathYear);

    vector<Person> serviceToVector(vector<Person> person);
    vector<Person> deleteDublicateVector(vector<Person> Persons);

    void add(string name, char gender, int birthYear, int deathYear);
    void editName(string trueName, string name);
    void editGender(string trueName, char gender);
    void editBirthYear(string trueName, int birthYear);
    void editDeathYear(string trueName, int deathYear);
    void deletePerson(string trueName);
    void deleteConnection(string pName, string cName);
    void deleteConnectionPerson(string name);
    void deleteConnectionComputer(string name);

    void linkPersonToComputer(string pName, string cName);
    vector<Computer> getComputersConnectedToPerson(string personName);


private:
    DataAccess _access;

};

#endif // PERSONRSERVICE_H
