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
    void sortItPerson();
    void sortItComputer();
    void searchPerson();
    void searchComputer();
    void deleteFromFilePerson();
    void deleteFromFileComputer();
    void editPerson();
    void editComputer();
    void displayVector(vector<Person> printIt, int x = 0);
    void teamLogo();
private:
    //ComputerService _Cservice;
    PersonService _service;
    Person PER;
};

#endif // CONSOLEUI_H
