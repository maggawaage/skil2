#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <vector>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, string type, int buildYear);

    string getName() const;
    string getType() const;
    int getBuildYear() const;

    void setName(string name);
    void setType(string type);
    void setBuildYear(int buildYear);

    static bool compareName(  Computer a,   Computer b);
    static bool  compareNameReversed(  Computer a,   Computer b);
    static bool  compareBuildYear(  Computer a,   Computer b);
    static bool  compareBuildYearReversed(  Computer a,   Computer b);
    static bool  compareType(  Computer a,   Computer b);
    static bool  compareTypeReversed(  Computer a,   Computer b);
    static bool checkIfSame(vector<Computer> Computers, string name);


private:
    string _name;
    string _type;
    int _buildYear;
};

#endif // COMPUTER_H
