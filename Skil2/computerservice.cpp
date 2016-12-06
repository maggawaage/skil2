#include "computerservice.h"


ComputerService::ComputerService()
{

}

vector<Computer> ComputerService::alpha(vector<Computer>& Computerlist)
{
    sort(Computerlist.begin(), Computerlist.end(), Computer::compareName);
    return Computerlist;
}
vector<Computer> ComputerService::reAlpha(vector<Computer>& Computerlist)
{
    sort(Computerlist.begin(), Computerlist.end(), Computer::compareNameReversed);
    return Computerlist;
}

vector<Computer> ComputerService::buildYear(vector<Computer>& Computerlist)
{
    sort(Computerlist.begin(), Computerlist.end(), Computer::comparebuildYear);
    return Computerlist;
}
vector<Computer> ComputerService::rebuildYear(vector<Computer>& Computerlist)
{
    sort(Computerlist.begin(), Computerlist.end(), Computer::comparebuildYearReversed);
    return Computerlist;
}

vector<Computer> ComputerService::type(vector<Computer>& Computerlist)
{
    sort(Computerlist.begin(), Computerlist.end(), Computer::comparetype);
    return Computerlist;
}
vector<Computer> ComputerService::reType(vector<Computer>& Computerlist)
{
    sort(Computerlist.begin(), Computerlist.end(), Computer::comparetypeReversed);
    return Computerlist;
}

vector<Computer> ComputerService::SearchName(vector <Computer> list, string searchName)
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
vector<Computer> ComputerService::SearchType(vector <Computer> list, char searchYype)
{
    vector <Computer> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].gettype() == searchType)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Computer> ComputerService::SearchBuildYear(vector<Computer> list, int searchBuildYear)
{
    vector <Computer> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getBuildYear() == searchBuildYear)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}


/*
 vector<Computer> ComputerService::serviceToVector(vector<Computer> Computer)
 {
 return access.fillVector(Computer);
 }
 void ComputerService::serviceToFile(vector<Computer> Computer)
 {
 access.writeVectorToFile(Computer);
 }
 void ComputerService::serviceToFile(string name, char type, int birthbuildYear, int deathbuildYear)
 {
 access.writeToFile(name, type, birthbuildYear, deathbuildYear);
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
 */
