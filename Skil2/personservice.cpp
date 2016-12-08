#include "personservice.h"
#include "dataaccess.h"
#include <algorithm>
#include "dataaccess.h"

PersonService::PersonService()
{

}

vector<Person> PersonService::Alpha()
{
    return _access.DataAlpha();
}
vector<Person> PersonService::reAlpha()
{
    return _access.DataReAlpha();
}

vector<Person> PersonService::year()
{
    return _access.DataYear();
}
vector<Person> PersonService::reYear()
{
    return _access.DataReYear();
}

vector<Person> PersonService::gender()
{
    return _access.DataGender();
}
vector<Person> PersonService::reGender()
{
    return _access.DataReGender();
}

vector<Person> PersonService::death()
{
    return _access.DataDeath();
}
vector<Person> PersonService::reDeath()
{
    return _access.DataReDeath();
}

vector<Person> PersonService::SearchName(vector <Person> list, string searchName)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].getName().find(searchName) != string::npos)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Person> PersonService::SearchGender(vector <Person> list, char searchGender)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getGender() == searchGender)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Person> PersonService::SearchBirthYear(vector<Person> list, int searchBirth)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getBirthYear() == searchBirth)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Person> PersonService::SearchDeathYear(vector<Person> list, int searchDeath)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getDeathYear() == searchDeath)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Person> PersonService::serviceToVector(vector<Person> person)
{
    return _access.fillVector(person);
}
void PersonService::serviceToFile(vector<Person> person)
{
     _access.writeVectorToFile(person);
}
void PersonService::serviceToFile(string name, char gender, int birthYear, int deathYear)
{
    _access.writeToFile(name, gender, birthYear, deathYear);
}
vector<Person> PersonService::deleteDublicateVector(vector<Person> Persons)
{
        for ( size_t i = 0; i < Persons.size() ; i++ )
        {
            for ( size_t j = 0; j < Persons.size() ; j++ )
            {
                if(( Persons.at(i).getName() == Persons.at(j).getName() ) && (!( i == j )))
                {
                    Persons.erase (Persons.begin()+i);
                }
            }
        }
        return Persons;
}
void PersonService::add(string name, char gender, int birthYear, int deathYear)
{
    _access.addPerson(name, gender, birthYear, deathYear);
}
void PersonService::editName(string trueName, string name)
{
    _access.editName(trueName, name);
}
void PersonService::editGender(string trueName, char gender)
{
    _access.editGender(trueName, gender);
}
void PersonService::editBirthYear(string trueName, int birthYear)
{
    _access.editBirthYear(trueName, birthYear);
}
void PersonService::editDeathYear(string trueName, int deathYear)
{
    _access.editDeathYear(trueName, deathYear);
}
void PersonService::deletePerson(string trueName)
{
    _access.deletePerson(trueName);
}
