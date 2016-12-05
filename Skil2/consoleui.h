#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "personservice.h"
#include "dataaccess.h"
#include "person.h"

class ConsoleUI
{
public:
    ConsoleUI();

    void run();
    void writePerson();
    void writeComputer();
    void sortItPerson();
    void sortItComputer();
    void search();
    void deleteFromFile();
    void edit();
    void displayVector(vector<Person> printIt, int x = 0);
    void teamLogo();
private:
    PersonService _service;
};

#endif // CONSOLEUI_H
