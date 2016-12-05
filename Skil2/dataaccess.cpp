#include <fstream>
#include "dataaccess.h"

DataAccess::DataAccess()
{

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
