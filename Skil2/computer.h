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

    /*
    static bool compareName(Person a, Person b);
    static bool  compareNameReversed(Person a, Person b);
    static bool  compareYear(Person a, Person b);
    static bool  compareYearReversed(Person a, Person b);
    static bool  compareGender(Person a, Person b);
    static bool  compareGenderReversed(Person a, Person b);
    static bool  compareDeath(Person a, Person b);
    static bool  compareDeathReversed(Person a, Person b);
    static bool checkIfSame(vector<Person> Persons, string name);
    */

private:
    string _name;
    int _buildYear;
    string _type;
};

#endif // COMPUTER_H
