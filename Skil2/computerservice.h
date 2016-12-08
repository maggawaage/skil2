#ifndef ComputerSERVICE_H
#define ComputerSERVICE_H

#include <vector>
#include <string>
#include "computer.h"
#include "dataaccess.h"
using namespace std;

class ComputerService
{
public:
    ComputerService();

    vector<Computer> alpha(vector<Computer>& Computerlist);
    vector<Computer> reAlpha(vector<Computer>& Computerlist);
    vector<Computer> buildYear(vector<Computer>& Computerlist);
    vector<Computer> reBuildYear(vector<Computer>& Computerlist);
    vector<Computer> type(vector<Computer>& Computerlist);
    vector<Computer> reType(vector<Computer>& Computerlist);

    static vector<Computer> SearchName(vector<Computer> list, string searchName);
    static vector<Computer> SearchType(vector<Computer> list, string searchYype);
    static vector<Computer> SearchBuildYear(vector<Computer> list, int searchBuildYear);

    vector<Computer> serviceToVector(vector<Computer> Computer);
    void serviceToFile(string name, string type, int birthYear);
    void serviceToFile(vector<Computer> Computer);

    vector<Computer> deleteDublicateVector(vector<Computer> Computers);
    void add(string name, string type, int buildYear)

private:
    vector<Computer> alpha();
    DataAccess access;

};

#endif // ComputerRSERVICE_H
