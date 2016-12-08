#include "computer.h"

Computer::Computer()
{

}
Computer::Computer(string name, string type, int buildYear)
{
    _name = name;
    _type = type;
    _buildYear = buildYear;
}

string Computer::getName() const
{
    return _name;
}
string Computer::getType() const
{
    return _type;
}
int Computer::getBuildYear() const
{
    return _buildYear;
}


void Computer::setName(string name)
{
    _name = name;
}
void Computer::setType(string type)
{
    _type = type;
}
void Computer::setBuildYear(int buildYear)
{
    _buildYear = buildYear;
}


bool Computer::compareName(Computer a, Computer b)
{
    return a._name < b._name;
}
bool Computer::compareNameReversed(Computer a, Computer b)
{
    return a._name > b._name;
}
bool Computer::compareBuildYear(Computer a, Computer b)
{
    return a._buildYear < b._buildYear;
}
bool Computer::compareBuildYearReversed(Computer a, Computer b)
{
    return a._buildYear > b._buildYear;
}
bool Computer::compareType(Computer a, Computer b)
{
    return a._type < b._type;
}
bool Computer::compareTypeReversed(Computer a, Computer b)
{
    return a._type > b._type;
}
bool Computer::checkIfSame(vector<Computer> Computers, string name)
{
    int check = 0;
    for (size_t i = 0; i < Computers.size() ; i++)
    {
        if (Computers.at(i).getName() == name)
        {
            check = 1;
        }
    }
    if (check == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

