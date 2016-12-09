#include "computerservice.h"
#include "dataaccess.h"
#include <algorithm>

ComputerService::ComputerService()
{

}
vector<Computer> ComputerService::SearchName(vector <Computer> list, string searchName)
{
    vector <Computer> newList;

    for (size_t i = 0; i < list.size(); i++)
    {
        if (list[i].getName().find(searchName) != string::npos)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Computer> ComputerService::SearchType(vector <Computer> list, string searchType)
{
    vector <Computer> newList;

    for (size_t i = 0; i < list.size(); i++)
    {

        if (list[i].getType().find(searchType) != string::npos)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Computer> ComputerService::SearchBuildYear(vector<Computer> list, int searchBuildYear)
{
    vector <Computer> newList;

    for (size_t i = 0; i < list.size(); i++)
    {

        if (list[i].getBuildYear() == searchBuildYear)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

vector<Computer> ComputerService::serviceToVector(vector<Computer> Computers)
{
    return _access.fillVector(Computers);
}
vector<Computer> ComputerService::deleteDublicateVector(vector<Computer> Computers)
{
    for ( size_t i = 0; i < Computers.size() ; i++ )
    {
        for ( size_t j = 0; j < Computers.size() ; j++ )
        {
            if(( Computers.at(i).getName() == Computers.at(j).getName() ) && (!( i == j )))
            {
                Computers.erase (Computers.begin()+i);
            }
        }
    }
    return Computers;
}

void ComputerService::add(string name, string type, int buildYear)
{
    _access.addComputer(name, type, buildYear );
}
void ComputerService::editName(string trueName, string name)
{
    _access.editComputerName(trueName, name);
}
void ComputerService::editType(string trueName, string type)
{
    _access.editType(trueName, type);
}
void ComputerService::editBuildYear(string trueName, int buildYear)
{
    _access.editBuildYear(trueName, buildYear);
}
void ComputerService::deleteComputer(string trueName)
{
    _access.deleteComputer(trueName);
}


vector<Computer> ComputerService::name()
{
    return _access.computerAlpha();
}
vector<Computer> ComputerService::reName()
{
    return _access.computerReAlpha();
}
vector<Computer> ComputerService::type()
{
    return _access.computerType();
}
vector<Computer> ComputerService::reType()
{
    return _access.computerReType();
}
vector<Computer> ComputerService::buildyear()
{
    return _access.computerBuildYear();
}
vector<Computer> ComputerService::reBuildyear()
{
    return _access.computerReBuildYear();
}

vector<Person> ComputerService::getPersonsConnectedToComp(string computerName)
{
    int id=_access.getComputerIdByName(computerName);
    return _access.getPersonsConnectedToComputers(id);
}

