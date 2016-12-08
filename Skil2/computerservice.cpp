#include "ComputerService.h"
#include "dataaccess.h"
#include <algorithm>

ComputerService::ComputerService()
{

}

vector<Computer> ComputerService::Alpha()
{
    return _access.dataAlpha();
}
vector<Computer> ComputerService::reAlpha()
{
    return _access.dataReAlpha();
}
vector<Computer> ComputerService::buildYear()
{
    return _access.dataBuildYear();
}
vector<Computer> ComputerService::reBuildYear()
{
    return _access.dataReBuildYear();
}
vector<Computer> ComputerService::type()
{
    return _access.dataType();
}
vector<Computer> ComputerService::reType()
{
    return _access.dataReType();
}

/*vector<Computer> ComputerService::SearchName(vector <Computer> list, string searchName)
{
    vector <Computer> newList;

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].getName().find(searchName) != string::npos)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Computer> ComputerService::Searchtype(vector <Computer> list, string searchtype)
{
    vector <Computer> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getType() == searchtype)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Computer> ComputerService::Search buildYear(vector<Computer> list, int searchBirth)
{
    vector <Computer> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].get buildYear() == searchBirth)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
*/

vector<Computer> ComputerService::serviceToVector(vector<Computer> Computers)
{
    return _access.fillVector(Computers);
}
/*
void ComputerService::serviceToFile(vector<Computer> Computers)
{
     _access.writeVectorToFile(Computers);
}
void ComputerService::serviceToFile(string name, string type, int  buildYear )
{
    _access.writeToFile(name, type,  buildYear);
}*/

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

void ComputerService::add(string name, string type, int  buildYear)
{
    _access.addComputer( name, type,  buildYear );
}
