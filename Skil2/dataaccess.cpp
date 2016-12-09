#include <fstream>
#include <iostream> //eyða
#include "dataaccess.h"


DataAccess::DataAccess()
{
    _runningDB = QSqlDatabase::database();
}

vector<Person> DataAccess::fillVector(vector<Person>famousComputerphiles)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT Name, Gender, BirthYear, DeathYear FROM Persons;");
    query.exec();
    while (query.next())
    {
        Person temp;
        QString name = query.value(0).toString();
        temp.setName(name.toStdString());
        QString gender = query.value(1).toString();
        temp.setGender(gender.toDouble());
        QString birthYear = query.value(2).toString();
        temp.setBirthYear(birthYear.toInt());
        QString deathYear = query.value(3).toString();
        temp.setDeathYear(deathYear.toInt());
        famousComputerphiles.push_back(temp);
    }
    return famousComputerphiles;
}

void DataAccess::addPerson(string name, char gender, int birthYear, int deathYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    //INSERT INTO Person (Name, Gender, BirthYear, DeathYear) VALUES ("GD", "Male", 1989, 0);
    query.prepare("INSERT INTO Persons (Name, Gender, BirthYear, DeathYear) "
                  "VALUES (?, ?, ?, ?)");

    query.addBindValue(QString::fromStdString(name));
    query.addBindValue(gender);
    query.addBindValue(birthYear);
    query.addBindValue(deathYear);
    query.exec();
}

vector<Person> DataAccess::parseLine(QSqlQuery& query)
{
    vector<Person> readToVec;
    while(query.next())
    {
        string name = query.value("Name").toString().toStdString();
        char gender = query.value("Gender").toString().toDouble();
        int birthYear = query.value("BirthYear").toUInt();
        int deathYear = query.value("DeathYear").toUInt();
        //Person _person(name, gender, birthYear, deathYear);
        readToVec.push_back(Person(name, birthYear, gender, deathYear));
    }
    return readToVec;
}
vector<Person> DataAccess::DataAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY Name ASC;");
    return parseLine(query);
}
vector<Person> DataAccess::DataReAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY Name DESC;");
    return parseLine(query);
}
vector<Person> DataAccess::DataYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY BirthYear ASC");
    return parseLine(query);
}
vector<Person> DataAccess::DataReYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY BirthYear DESC");
    return parseLine(query);
}
vector<Person> DataAccess::DataGender()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY Gender ASC");
    return parseLine(query);
}
vector<Person> DataAccess::DataReGender()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY Gender DESC");
    return parseLine(query);
}
vector<Person> DataAccess::DataDeath()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY DeathYear ASC");
    return parseLine(query);
}
vector<Person> DataAccess::DataReDeath()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Persons ORDER BY DeathYear DESC");
    return parseLine(query);
}

void DataAccess::editName(string trueName, string name)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET Name = :name WHERE ID = Name = :Name;");

    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":Name",QString::fromStdString(trueName));
    query.exec();
}
void DataAccess::editGender(string trueName, char gender)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET Gender = :gender WHERE Name = :Name;");
    query.bindValue(":gender",gender);
    query.bindValue(":Name", QString::fromStdString(trueName));
    query.exec();
}
void DataAccess::editBirthYear(string trueName, int birthYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET BirthYear = :birthYear WHERE Name = :Name;");
    query.bindValue(":birthYear",birthYear);
    query.bindValue(":Name", QString::fromStdString(trueName));
    query.exec();
}
void DataAccess::editDeathYear(string trueName, int deathYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET DeathYear = :birthYear WHERE Name = :Name;");
    query.bindValue(":DeathYear",deathYear);
    query.bindValue(":Name", QString::fromStdString(trueName));
    query.exec();
}
void DataAccess::deletePerson(string trueName)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM Persons WHERE Name = :Name;");
    query.bindValue(":Name", QString::fromStdString(trueName));
    query.exec();
}

//--------Computer----------

vector<Computer> DataAccess::fillVector(vector<Computer>famousComputers)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT Name, Type, BuildYear FROM Computers;");
    while (query.next())
    {
        Computer temp;
        QString name = query.value(0).toString();
        temp.setName(name.toStdString());
        QString type = query.value(1).toString();
        temp.setType(type.toStdString());
        QString buildYear = query.value(2).toString();
        temp.setBuildYear(buildYear.toInt());
        famousComputers.push_back(temp);
    }
    return famousComputers;
}
//búinn erftir að tengja
void DataAccess::addComputer(string name, string type, int buildYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    //INSERT INTO Person (Name, Gender, BirthYear, DeathYear) VALUES ("GD", "Male", 1989, 0);
    query.prepare("INSERT INTO Computers (Name, Type, BuildYear) "
                  "VALUES (?, ?, ?)");

    query.addBindValue(QString::fromStdString(name));
    query.addBindValue(QString::fromStdString(type));
    query.addBindValue(buildYear);
    query.exec();
}

vector<Computer> DataAccess::ParseLine(QSqlQuery& line)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    vector<Computer> readToVec;
    while(line.next())
    {
        string name = query.value("Name").toString().toStdString();
        string type = query.value("Type").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        Computer _computer(name, type, buildYear);
        readToVec.push_back(Computer(name, type, buildYear));
    }
    return readToVec;
}
vector<Computer> DataAccess::DataComputerAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Computers ORDER BY Name ASC");
    return ParseLine(query);
}
vector<Computer> DataAccess::DataComputerReAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Computers ORDER BY Name DESC");
    return ParseLine(query);
}
vector<Computer> DataAccess::DataComputerType()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Computers ORDER BY Type ASC");
    return ParseLine(query);
}
vector<Computer> DataAccess::DataComputerReType()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Computers ORDER BY Type DESC");
    return ParseLine(query);
}
vector<Computer> DataAccess::DataComputerBuildYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Computers ORDER BY BuildYear ASC");
    return ParseLine(query);
}
vector<Computer> DataAccess::DataComputerReBuildYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Computers ORDER BY BuildYear DESC");
    return ParseLine(query);
}

void DataAccess::editComputerName(string trueName, string name)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET Name = :name WHERE Name = :Name;");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":Name",QString::fromStdString(trueName));
    query.exec();
}
void DataAccess::editType(string trueName, string computerType)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET Type = :type WHERE Name = :Name;");
    query.bindValue(":type", QString::fromStdString(computerType));
    query.bindValue(":Name", QString::fromStdString(trueName));
    query.exec();
}
void DataAccess::editBuildYear(string trueName, int buildYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET BuildYear = :buildYear WHERE Name = :Name;");
    query.bindValue(":buildYear",buildYear);
    query.bindValue(":Name", QString::fromStdString(trueName));
    query.exec();
}
void DataAccess::deleteComputer(string trueName)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM Computers WHERE Name = :Name;");
    query.bindValue(":Name", QString::fromStdString(trueName));
    query.exec();
}

void DataAccess::linkPersonTwoComputer(int Person_ID, int Computer_ID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("INSERT INTO CID_PID_LINK (Person_ID, Computer_ID) "
                  "VALUES (?, ?)");
    query.addBindValue(Person_ID);
    query.addBindValue(Computer_ID);
    query.exec();
}

