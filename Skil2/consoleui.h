#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "personservice.h"
#include "computerservice.h"
#include "person.h"
#include "computer.h"

class ConsoleUI
{
public:
    ConsoleUI();

    void run();
    void writePerson();
    void sortItPerson();
    void searchPerson();
    void deleteFromFilePerson();
    void editPerson();
    void displayVector(vector<Person> printIt, int x = 0);

    void writeComputer();
    void sortItComputer();
    void searchComputer();
    void deleteFromFileComputer();
    void editComputer();
    void displayComputerVector( vector<Computer> printIt, int x = 0 );
    void teamLogo();
private:
    ComputerService _Cservice;
    Computer _COP;
    PersonService _service;
    Person _PER;
};

#endif // CONSOLEUI_H
