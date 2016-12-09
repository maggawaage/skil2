#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include <vector>
#include <string>
#include "computer.h"
#include "dataaccess.h"

using namespace std;

class ComputerService
{

public:
    ComputerService();

    //vector<Computer> Alpha();
    //vector<Computer> reAlpha();
    //vector<Computer> buildYear();
    //vector<Computer> reBuildYear();
    //vector<Computer> type();
    //vector<Computer> reType();
    vector<Computer> name();
    vector<Computer> reName();
    vector<Computer> type();
    vector<Computer> reType();
    vector<Computer> buildyear();
    vector<Computer> reBuildyear();

    static vector<Computer> SearchName(vector<Computer> list, string searchName);
    static vector<Computer> SearchType(vector<Computer> list, string searchType);
    static vector<Computer> SearchBuildYear(vector<Computer> list, int searchBuildYear);

    vector<Computer> serviceToVector(vector<Computer> Computer);
    vector<Computer> deleteDublicateVector(vector<Computer> Computers);

    void add(string name, string type, int buildYear);
    void editName(string trueName, string name);
    void editType(string trueName, string type);
    void editBuildYear(string trueName, int buildYear);
    void deleteComputer(string trueName);

private:
    DataAccess _access;

};

#endif // COMPUTERSERVICE_H
