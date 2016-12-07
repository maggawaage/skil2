#include <fstream>
#include "dataaccess.h"
#include "person.h"

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
vector<Person> DataAccess::parseLine(QSqlQuery& line)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    vector<Person> readToVec;
    while(line.next()){
        string name = query.value("Name").toString().toStdString();
        char gender = query.value("Gender").toString().toStdString()[0];
        int birthYear = query.value("BirthYear").toUInt();
        int deathYear = query.value("DeathYear").toUInt();
        Person _person(name, gender, birthYear, deathYear);
        readToVec.push_back(Person(name, gender, birthYear, deathYear));
    }
    return readToVec;
}
vector<Person> DataAccess::DataAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY Name ASC");
    return parseLine(query);
}
vector<Person> DataAccess::DataReAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Persons ORDER BY Name DESC");
    return parseLine(query);
}

vector<Person> DataAccess::DataYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Persons ORDER BY BirthYear ASC");
    return parseLine(query);
}
vector<Person> DataAccess::DataReYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
   _query.exec("SELECT * FROM Persons ORDER BY BirthYear DESC");
   return parseLine(query);
}
vector<Person> DataAccess::DataGender()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Persons ORDER BY Gender ASC");
    return parseLine(query);
}
vector<Person> DataAccess::DataReGender()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Persons ORDER BY Gender DESC");
    return parseLine(query);
}
vector<Person> DataAccess::DataDeath()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Persons ORDER BY DeathYear ASC");
    return parseLine(query);
}
vector<Person> DataAccess::DataReDeath()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Persons ORDER BY DeathYear DESC");
    return parseLine(query);
}
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
