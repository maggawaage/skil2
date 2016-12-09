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
    void writeComputer();
    void writeConnection();
    void sortItPerson();
    void sortItComputer();
    void searchPerson();
    void searchComputer();
    void deleteFromFilePerson();
    void deleteFromFileComputer();
    void editPerson();
    void editComputer();
    void displayVector(vector<Person> printIt, int x = 0);
    void displayComputerVector( vector<Computer> printIt, int x = 0 );
    void personLinkedToComputer();
    void computerLinkedToPerson();
    void about();
    void printDabs();
    void teamLogo();

private:
    ComputerService _Cservice;
    Computer _COP;
    PersonService _service;
    Person _PER;
};

#endif // CONSOLEUI_H
