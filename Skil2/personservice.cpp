#include "personservice.h"
#include "dataaccess.h"
#include <algorithm>

PersonService::PersonService()
{

}

vector<Person> PersonService::alpha(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareName);
    return personlist;
}
vector<Person> PersonService::reAlpha(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareNameReversed);
    return personlist;
}

vector<Person> PersonService::year(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareYear);
    return personlist;
}
vector<Person> PersonService::reYear(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareYearReversed);
    return personlist;
}

vector<Person> PersonService::gender(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareGender);
    return personlist;
}
vector<Person> PersonService::reGender(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareGenderReversed);
    return personlist;
}

vector<Person> PersonService::death(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareDeath);
    return personlist;
}
vector<Person> PersonService::reDeath(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareDeathReversed);
    return personlist;
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
    return access.fillVector(person);
}
void PersonService::serviceToFile(vector<Person> person)
{
     access.writeVectorToFile(person);
}
void PersonService::serviceToFile(string name, char gender, int birthYear, int deathYear)
{
    access.writeToFile(name, gender, birthYear, deathYear);
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
