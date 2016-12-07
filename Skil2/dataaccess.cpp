#include <fstream>
#include "dataaccess.h"

DataAccess::DataAccess()
{
    _runningDB = QSqlDatabase::database();
}

void DataAccess::testSQLcommand()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("select Name, Gender, BirthYear, DeathYear from Person;");

    while (query.next())
    {
        QString name = query.value(0).toString();
        QString gender = query.value(1).toString();
        QString birthYear = query.value(2).toString();
        QString deathYear = query.value(3).toString();
        qDebug() << name << gender << birthYear << deathYear;
    }
}
vector<Person> DataAccess::alpha()
{
    _query.exec("SELECT * FROM Persons ORDER BY Name ASC");
}
vector<Person> DataAccess::reAlpha()
{
    _query.exec("SELECT * FROM Persons ORDER BY Name DESC");
}

vector<Person> DataAccess::year()
{
    _query.exec("SELECT * FROM Persons ORDER BY BirthYear ASC");
}
vector<Person> DataAccess::reYear()
{
   _query.exec("SELECT * FROM Persons ORDER BY BirthYear DESC");
}
vector<Person> DataAccess::gender()
{
    _query.exec("SELECT * FROM Persons ORDER BY Gender ASC");
}
vector<Person> DataAccess::reGender()
{
    _query.exec("SELECT * FROM Persons ORDER BY Gener DESC");
}

vector<Person> DataAccess::death()
{
    _query.exec("SELECT * FROM Persons ORDER BY DeathYear ASC");
}
vector<Person> DataAccess::reDeath()
{
    _query.exec("SELECT * FROM Persons ORDER BY DeathYear DESC");
}
/*
vector<Person> DataAccess::fillVector(vector<Person>famousComputerphiles)
{
    fstream inputFile("person.txt");
    string name;
    char gender;
    int birthYear;
    int deathYear;
    string trash;

    if (inputFile.is_open())
    {
        while(inputFile >> trash)
        {
            Person temp;
            getline(inputFile, name);
            name=name.substr(1);
            temp.setName(name);
            inputFile >> gender;
            temp.setGender(gender);
            inputFile >> birthYear;
            temp.setBirthYear(birthYear);
            inputFile >> deathYear;
            temp.setDeathYear(deathYear);
            if(!inputFile.eof() )
            {
                famousComputerphiles.push_back(temp);
            }
        }
    }
    inputFile.close();
    return famousComputerphiles;
}

void DataAccess::writeToFile(string name, char gender, int birthYear, int deathYear)
{
    ofstream famousPersons ("person.txt", ios_base::app);
    if (famousPersons.is_open())
    {
        famousPersons << "\n* " << name;
        famousPersons << "\n";
        famousPersons <<gender;
        famousPersons << "\n";
        famousPersons <<birthYear;
        famousPersons << "\n";
        famousPersons <<deathYear;
        famousPersons << "\n";
        famousPersons.close();
    }
}

void DataAccess::writeVectorToFile(vector<Person>famousComputerphiles)
{
    string name;
    char gender;
    int birthYear;
    int deathYear;
    ofstream famousPersons ("person.txt");
    if (famousPersons.is_open())
    {
        for(size_t i = 0; i < famousComputerphiles.size() ; i++ )
        {
            famousPersons << "* ";
            name = famousComputerphiles.at(i).getName();
            famousPersons << name;
            famousPersons << "\n";
            gender = famousComputerphiles.at(i).getGender();
            famousPersons << gender;
            famousPersons << "\n";
            birthYear = famousComputerphiles.at(i).getBirthYear();
            famousPersons << birthYear;
            famousPersons << "\n";
            deathYear = famousComputerphiles.at(i).getDeathYear();
            famousPersons << deathYear;
            famousPersons << "\n";
        }
        famousPersons.close();
    }
}
*/
