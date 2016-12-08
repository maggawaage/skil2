#include <fstream>
#include "dataaccess.h"
#include "person.h"

DataAccess::DataAccess()
{
    _runningDB = QSqlDatabase::database();
}

vector<Person> DataAccess::fillVector(vector<Person>famousComputerphiles)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT name, gender, birthYear, deathYear FROM person;");
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
    query.prepare("INSERT INTO Person (Name, Gender, BirthYear, DeathYear) "
                                "VALUES (?, ?, ?, ?)");

    query.addBindValue(QString::fromStdString(name));
    query.addBindValue(gender);
    query.addBindValue(birthYear);
    query.addBindValue(deathYear);
    query.exec();
}

void DataAccess::addComputer(string name, string type, int buildYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("INSERT INTO person (name, type, buildYear) VALUES(:iName, :iType, :iBuildYear);");
    query.bindValue(":iName", QString::fromStdString(name));
    query.bindValue(":iType", QString::fromStdString(type));
    query.bindValue(":iBuildYear", buildYear);
    query.exec();
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

void DataAccess::editName(int id, string name)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Person SET Name = :name WHERE ID = :id;");

    query.bindValue(":name", QString::fromStdString(name));
        query.bindValue(":id", id);
        query.exec();
}

void DataAccess::editGender(int id, char gender)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Person SET Gender = :gender WHERE ID = :id;");
        query.bindValue(":gender",gender);
        query.bindValue(":id", id);
        query.exec();
}

void DataAccess::editBirthYear(int id, int birthYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Person SET BirthYear = :birthYear WHERE ID = :id;");
        query.bindValue(":birthYear",birthYear);
        query.bindValue(":id", id);
        query.exec();
}

void DataAccess::editDeathYear(int id, int deathYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Person SET DeathYear = :birthYear WHERE ID = :id;");
        query.bindValue(":DeathYear",deathYear);
        query.bindValue(":id", id);
        query.exec();
}


//--------- For computer

vector<Computer> DataAccess::fillVector(vector<Computer>famousComputers)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("select name, type, year of build;");
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

vector<Computer> DataAccess::ParseLine(QSqlQuery& line)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    vector<Computer> readToVec;
    while(line.next()){
        string name = query.value("Name").toString().toStdString();
        string type = query.value("Type").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        Computer _computer(name, type, buildYear);
        readToVec.push_back(Computer(name, type, buildYear));
    }
    return readToVec;
}
vector<Computer> DataAccess::dataAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT * FROM Computer ORDER BY Name ASC");
    return ParseLine(query);
}
vector<Computer> DataAccess::dataReAlpha()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Computer ORDER BY Name DESC");
    return ParseLine(query);
}

vector<Computer> DataAccess::dataType()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Computer ORDER BY Type ASC");
    return ParseLine(query);
}
vector<Computer> DataAccess::dataReType()
{
    QSqlQuery query = QSqlQuery(_runningDB);
   _query.exec("SELECT * FROM Computer ORDER BY Type DESC");
   return ParseLine(query);
}
vector<Computer> DataAccess::dataBuildYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Computer ORDER BY BuildYear ASC");
    return ParseLine(query);
}
vector<Computer> DataAccess::dataReBuildYear()
{
    QSqlQuery query = QSqlQuery(_runningDB);
    _query.exec("SELECT * FROM Computer ORDER BY BuildYear DESC");
    return ParseLine(query);
}





