#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <string>
#include "person.h"
class DataAccess
{
public:
    DataAccess();
    void writeToFile(string name, char gender, int birthYear, int deathYear);
    void writeVectorToFile(vector<Person>famousComputerphiles);
    vector<Person> fillVector(vector<Person>famousComputerphiles);
};
#endif // DATAACCESS_H
