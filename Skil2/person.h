#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person();
    //Person(int id, string name, int birthYear, char gender,  int deathYear);
    Person(string name, int birthYear, char gender,  int deathYear);

    int getID() const;
    string getName() const;
    char getGender() const;
    int getBirthYear() const;
    int getDeathYear() const;
    void setID(int id);
    void setName(string name);
    void setGender(char gender);
    void setBirthYear(int birthYear);
    void setDeathYear(int deathYear);


    static bool compareName(Person a, Person b);
    static bool  compareNameReversed(Person a, Person b);
    static bool  compareYear(Person a, Person b);
    static bool  compareYearReversed(Person a, Person b);
    static bool  compareGender(Person a, Person b);
    static bool  compareGenderReversed(Person a, Person b);
    static bool  compareDeath(Person a, Person b);
    static bool  compareDeathReversed(Person a, Person b);
    static bool checkIfSame(vector<Person> Persons, string name);

private:
    int _id;
    string _name;
    int _birthYear;
    char _gender;
    int _deathYear;
};

#endif // PERSON_H
