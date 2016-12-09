#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "consoleui.h"
#include "person.h"
#include "computer.h"
//system(CLEAR) for windows and linux
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    int choice;

    teamLogo();

    do
    {
        cout << endl;
        cout << "Please choose from the following commands: \n";
        cout << "\t1. Add to list \n";
        cout << "\t2. Print list(sort) \n";
        cout << "\t3. Search list\n";
        cout << "\t4. Delete from list\n";
        cout << "\t5. Edit list\n";
        cout << "\t6. About \n";
        cout << "\t7. GitHub location \n";
        cout << "\t8. Quit \n";

        cout << endl;
        cout << "Your choice: ";
        while(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter corresponding number from 1-8: ";
        }

        switch(choice)
        {
        case 1:
            cout << "Do you want to add a person or a computer?\n";
            cout << "\t1. Add person  \n";
            cout << "\t2. Add computer \n";
            cout << "Your choice: ";
            int writeChoice;
            cin >> writeChoice;
            switch(writeChoice)
            {
            case 1:
                writePerson();
                break;
            case 2:
                writeComputer();
                break;
            default:
                system(CLEAR);
                cout<<"\tInvalid entry!\a"<<endl;
            }
            break;
        case 2:
            cout << "Do you want to print out a list of person or a computer?\n";
            cout << "\t1. Print out person  \n";
            cout << "\t2. Print out computer \n";
            cout << "Your choice: ";
            int sortItChoice;
            cin >> sortItChoice;
            switch(sortItChoice)
            {
            case 1:
                sortItPerson();
                break;
            case 2:
                sortItComputer();
                break;
            default:
                system(CLEAR);
                cout<<"\tInvalid entry!\a"<<endl;
            }
            break;
        case 3:
            cout << "Do you want to search for a person or a computer?\n";
            cout << "\t1. Search person  \n";
            cout << "\t2. Search computer \n";
            cout << "Your choice: ";
            int searchChoice;
            cin >> searchChoice;
            switch(searchChoice)
            {
            case 1:
                searchPerson();
                break;
            case 2:
                searchComputer();
                break;
            default:
                system(CLEAR);
                cout<<"\tInvalid entry!\a"<<endl;
            }
            break;
        case 4:
            cout << "Do you want to delete from a list of persons or a computers?\n";
            cout << "\t1. Delete person  \n";
            cout << "\t2. Delete computer \n";
            cout << "Your choice: ";
            int deleteFromFileChoice;
            cin >> deleteFromFileChoice;
            switch(deleteFromFileChoice)
            {
            case 1:
                deleteFromFilePerson();
                break;
            case 2:
                deleteFromFileComputer();
                break;
            default:
                system(CLEAR);
                cout<<"\tInvalid entry!\a"<<endl;
            }
            break;
        case 5:
            cout << "Do you want to edit a person or a computer?\n";
            cout << "\t1. Edit person  \n";
            cout << "\t2. Edit computer \n";
            cout << "Your choice: ";
            int editChoice;
            cin >> editChoice;
            switch(editChoice)
            {
            case 1:
                editPerson();
                break;
            case 2:
                editComputer();
                break;
            default:
                system(CLEAR);
                cout<<"\tInvalid entry!\a"<<endl;
            }
            break;
        case 6:
            system(CLEAR);
            about();
            break;
         case 7:
            system(CLEAR);
           //system ("start https://github.com/maggawaage/skil2");
            system ("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
            break;
        case 8:
            exit(0);
            break;
        default:
            system(CLEAR);
            cout<<"\tInvalid entry!\a"<<endl;
        }
    }
    while(true);
}

void ConsoleUI::writePerson()
{
    string name;
    char gender;
    int birthYear;
    int deathYear;

    //Getting valid name,gender,birthYear and deathYear
    while (name.empty())
    {
        cout << "Name(English characters only): ";
        cin.ignore(10000,'\n');
        getline(cin, name);
    }
    cout << "If male enter m. If female enter f:  ";
    while(!(cin>>gender) | !((gender == 'm')| (gender == 'f') ))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only m for male or f for femaler: ";
    }

    cout << "Birth year: ";
    while(!(cin>>birthYear))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter birth year only in numbers(YYYY): ";
    }
    cout << "Enter death year (If person is not dead enter 0): ";
    while(!(cin>>deathYear) )
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter death year only in numbers(YYYY):  ";
    }
    while(!(!(deathYear<birthYear)|(deathYear==0)))
    {
        cout << "You cannot die before you are born.\n"
             << "Enter death year again: ";
        cin >> deathYear;
    }

    //Checks if name is already in file if not move to file
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    if(_PER.checkIfSame(Persons, name))
    {
        _service.add(name, gender, birthYear, deathYear);
        system(CLEAR);
        cout << "\nAdded the person\n";
    }
    else
    {
        system(CLEAR);
        cout << "\nError: This name is already on the list.\a\n";
    }
}

void ConsoleUI::sortItPerson()
{
    vector<Person> Persons;
    int choice = 0;
    cout << "How would you like to sort?" << endl;
    cout << "\t1. By name  \n";
    cout << "\t2. By gender \n";
    cout << "\t3. By birthyear \n";
    cout << "\t4. By year of death \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch(choice)
    {
    case 1: //Sorts alphabetically
        cout << "\t1. From A-Z  \n";
        cout << "\t2. From Z-A \n";
        cout << "Your choice: ";
        int choiceAlpha;
        cin >> choiceAlpha;
        switch(choiceAlpha)
        {
        case 2:
            Persons = _service.reAlpha();
            break;
        default: // if 1 or something other
            Persons = _service.Alpha();
        }
        break;
    case 2: //Sorts by which gender first and alphabetically
        cout << "\t1. First female  \n";
        cout << "\t2. First male \n";
        cout << "Your choice(default: ";
        int choiceGender;
        cin >> choiceGender;
        switch(choiceGender)
        {
        case 2:
            Persons = _service.Alpha();
            Persons = _service.reGender();
            break;
        default: // if 1 or something other;
            Persons = _service.Alpha();
            Persons = _service.gender();
        }
        break;
    case 3:
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        cout << "Your choice: ";
        int choiceBirthYear;
        cin >> choiceBirthYear;
        switch(choiceBirthYear)
        {
        case 2:
            Persons = _service.Alpha();
            Persons = _service.year();
            break;
        default: // if 1 or something other
            Persons = _service.Alpha();
            Persons = _service.reYear();
            break;
        }
        break;
    case 4:
        cout << "\t1. From highest to lowest. \n";
        cout << "\t2. From lowest to highest.\n";
        cout << "Your choice: ";
        int choiceDeathYear;
        cin >> choiceDeathYear;
        switch(choiceDeathYear)
        {
        case 2:
            Persons = _service.Alpha();
            Persons = _service.death();
            break;
        default: // if 1 or something other
            Persons = _service.Alpha();
            Persons = _service.reDeath();
        }
        break;
    }
    system(CLEAR);
    displayVector(Persons);
}

void ConsoleUI::searchPerson()
{
    vector<Person> SearchPersons;

    char keepSearching = 'y';

    while (keepSearching == 'y')
    {
        SearchPersons= _service.serviceToVector(SearchPersons);

        char moreConditions = 'y';

        bool conditionAvailable[] = {0,0,0,0,0}; // Stores types of search you are using.
        string searchString[5]; // Stores types of search
        searchString[0] = "\t 1. Name \n";
        searchString[1] = "\t 2. Gender \n";
        searchString[2] = "\t 3. Year of birth \n";
        searchString[3] = "\t 4. Year of death  \n";
        searchString[4] = "\t 5. Still alive\n";

        while (moreConditions == 'y' && (!(conditionAvailable[0] && conditionAvailable[1] && conditionAvailable[2] && conditionAvailable[3]&& conditionAvailable[4])))
        {
            int conditionNum;
            for (int i = 0; i < 4; i++)
            {
                if (!conditionAvailable[i])
                {
                    cout << searchString[i];
                }
            }
            cout << "What do you want to search for? ";
            while(!(cin>>conditionNum))
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter corresponding number from 1-5: ";
            }
            //Search by name
            if ((conditionNum == 1) & (conditionAvailable[0] == 0))
            {
                string nameForSearch;
                cout << "What name do you want to search for? ";
                while (!(cin >> nameForSearch))
                {
                    getline(cin, nameForSearch);
                }
                SearchPersons = _service.SearchName(SearchPersons, nameForSearch);
            }
            //Search by gender
            else if ((conditionNum == 2) & (conditionAvailable[1] == 0) )
            {
                char genderForSearch;
                cout << "Which gender do you want to search for (m/f)? ";
                while(!(cin>>genderForSearch) | !((genderForSearch == 'm')|(genderForSearch == 'M') | (genderForSearch == 'f') | (genderForSearch == 'F')))
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter only m/M for male or f/F for femaler: ";
                }
                SearchPersons = _service.SearchGender(SearchPersons, genderForSearch);
            }
            //Search by birth year
            else if ((conditionNum == 3) & (conditionAvailable[2] == 0))
            {
                int birthYearForSearch;
                cout << "What birth year do you want to search for? ";
                while(!(cin>>birthYearForSearch))
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter birth year only in numbers(YYYY): ";
                }
                SearchPersons = _service.SearchBirthYear(SearchPersons, birthYearForSearch);
            }
            //Search by death year
            else if ((conditionNum == 4) & (conditionAvailable[3] == 0))
            {
                int deathYearForSearch;
                cout << "What death year do you want to search for? ";
                while(!(cin>>deathYearForSearch) )
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter death year only in numbers(YYYY):  ";
                }
                SearchPersons = _service.SearchDeathYear(SearchPersons, deathYearForSearch);
            }
            //Search by alive
            else if ((conditionNum == 5) & (conditionAvailable[3] == 0))
            {
                SearchPersons = _service.SearchDeathYear(SearchPersons, 0);
            }

            conditionAvailable[conditionNum-1] = 1;

            //Add type of search
            cout << "Do you want to add another condition (y/n)? ";
            while(!(cin>>moreConditions) | (!((moreConditions== 'y')|(moreConditions == 'Y') | (moreConditions == 'n') | (moreConditions == 'N'))))
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter only y/Y for yes or n/N for no: ";
            }
            cout << " \n";
        }

        _service.deleteDublicateVector(SearchPersons);


        if (SearchPersons.size() == 0)
        {
            system(CLEAR);
            cout << "No computer matches this search \a\n";
        }
        else
        {
            system(CLEAR);
            cout << "Displaying search results: \n";
            displayVector(SearchPersons);
        }


        cout << "\nDo you want to search again(y/n)? ";
        while(!(cin>>keepSearching) | !((keepSearching== 'y')|(keepSearching == 'Y') | (keepSearching == 'n') | (keepSearching == 'N')))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only y/Y for yes or n/N for no: ";
        }

    }
}

void ConsoleUI::deleteFromFilePerson()
{
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    int id;
    string trueName;
    displayVector(Persons, 1);

    cout << "\nEnter the ID of the person you want to delete: ";
    while(!(cin >> id) | (id < 1) | (id > Persons.size()))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding numbers: ";
    }

    trueName = Persons.at(id-1).getName();
    _service.deletePerson(trueName);
    Persons.clear();
    Persons = _service.serviceToVector(Persons);
    system(CLEAR);
    displayVector(Persons);
}

void ConsoleUI::editPerson()
{
    string newName;
    char newGender;
    int newYear;
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    int id;
    string trueName;
    //Couts vector with ID
    displayVector( Persons, 1 );

    cout << "\nEnter the ID of the person you want to edit? ";
    while(!(cin >> id) | (id < 1) | (id > Persons.size()))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding id: ";
    }

    trueName = Persons.at(id-1).getName();

    cout << "What do you want to edit?\n "
         <<"\t 1. Name \n"
         <<"\t 2. Gender \n"
         <<"\t 3. Year of birth \n"
         <<"\t 4. Year of death  \n";

    //What to change
    cout << "Your choice: ";
    int editChoice;
    while ( !(cin >> editChoice) | ( editChoice < 1 ) | ( editChoice > 4 ) )
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only correspondings number from 1-4 ";
    }
    switch(editChoice)
    {
    case 1:
        cout << "Enter new name: ";
        while (newName.empty())
        {
            cout << "Name(English characters only): ";
            cin.ignore(10000,'\n');
            getline(cin, newName);
        }
        if (_PER.checkIfSame(Persons, newName))
        {
            _service.editName(trueName, newName);
        }
        else
        {
            system(CLEAR);
            cout << "This name is already on the list. Nothing was edited\n";
        }
        break;
    case 2:
        cout << "Enter new gender: ";
        while(!(cin>>newGender) | !((newGender == 'm')| (newGender == 'f') ))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only m for male or f for female: ";
        }
        _service.editGender(trueName, newGender);
        break;
    case 3:
        cout << "Enter new year: ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        if ( (newYear > Persons.at(id-1).getDeathYear()) | (Persons.at(id-1).getDeathYear() == 0) )
        {
            _service.editBirthYear(trueName, newYear);
        }
        else
        {
            system(CLEAR);
            cout << "You cannot die before you are born. Nothing was edited\a\n";
        }
        break;
    case 4:
        cout << "Enter new year (if not dead enter 0): ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        if ( (newYear > Persons.at(id-1).getDeathYear()) | ( newYear == 0 ) )
        {
            _service.editDeathYear(trueName, newYear);
        }
        else
        {
            system(CLEAR);
            cout << "You cannot die before you are born. Nothing was edited\n";
        }
        break;
    default:
    {
        cout<<"\tInvalid entry!"<< endl;
    }

    }
    Persons.clear();
    Persons = _service.serviceToVector(Persons);
    displayVector(Persons);
}

void ConsoleUI::displayVector( vector<Person> printIt, int x )
{
    cout << "\n";
    //Couts ID if you want
    if (x == 1)
    {
        cout << "ID" << "\t";
    }
    cout << "Name"<< "\t\t\t" << "Gender" << "\t" << "Birth year";
    cout.width(15);
    cout <<"Year of death";
    cout.width(15);
    cout <<"Age when died" << endl;;
    cout <<"========================================================================\n";

    for(size_t i = 0; i < printIt.size(); i++)
    {
        //Couts ID number if you want
        cout.setf(ios::left);
        if (x == 1)
        {
            cout.width(8);
            cout << i+1;
        }
        cout.width(24);
        cout << printIt[i].getName();
        if(printIt[i].getGender()=='m')
        {
            cout.width(8);
            cout << "Male";
        }
        else
        {
            cout.width(8);
            cout << "Female";
        }
        cout.width(12);
        cout << printIt[i].getBirthYear();
        if (!(printIt[i].getDeathYear() == 0))
        {
            cout.width(15);
            cout << printIt[i].getDeathYear()
                 << (printIt[i].getDeathYear() - printIt[i].getBirthYear()) << endl;;
        }
        else
        {
            cout.width(15);
            cout << '-'
                 << "-\n";
        }
    }
}

//---------COMPUTER

void ConsoleUI::writeComputer()
{
    string name;
    string type;
    int buildYear;

    //Getting valid name, type and build year
    while (name.empty())
    {
        cout << "Name(English characters only): ";
        cin.ignore(10000,'\n');
        getline(cin, name);
    }
    while (type.empty())
    {
        cout << "Type(English characters only): ";
        getline(cin, type);
    }
    cout << "Build year: ";
    while(!(cin>>buildYear))
    {
        cout << "Enter build year only in numbers(YYYY): ";
        cin.ignore(10000,'\n');
    }
    //Check if name is already in file if not move to file
    vector<Computer> Computers;
    Computers = _Cservice.serviceToVector(Computers);
    if(_COP.checkIfSame(Computers, name))
    {
        _Cservice.add(name, type, buildYear);
        system(CLEAR);
        cout << "\nAdded the computer\n";
    }
    else
    {
        system(CLEAR);
        cout << "\nError: This name is already on the list.\a\n";
    }
}

//LAGA
void ConsoleUI::sortItComputer()
{
    vector<Computer> Computers;
    Computers = _Cservice.serviceToVector(Computers);
    int choice = 0;
    cout << "How would you like to sort?" << endl;
    cout << "\t1. By name  \n";
    cout << "\t2. By type \n";
    cout << "\t3. By buildyear \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch(choice)
    {
    case 1: //Sorts alphabetically
        cout << "\t1. From A-Z  \n";
        cout << "\t2. From Z-A \n";
        cout << "Your choice: ";
        int choiceAlpha;
        cin >> choiceAlpha;
        switch(choiceAlpha)
        {
        case 2:
            Computers = _Cservice.reAlpha();
            break;
        default: // if 1 or something other
            Computers = _Cservice.Alpha();
        }
        break;
    case 2: //Sorts by which gender first and alphabetically
        cout << "\t1. From A-Z  \n";
        cout << "\t2. From Z-A \n";
        cout << "Your choice(default): ";
        int choiceGender;
        cin >> choiceGender;
        switch(choiceGender)
        {
        case 2:
            Computers = _Cservice.Alpha();
            Computers = _Cservice.reType();
            break;
        default: // if 1 or something other
            Computers = _Cservice.Alpha();
            Computers = _Cservice.type();
        }
        break;
    case 3:
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        cout << "Your choice: ";
        int choiceBirthYear;
        cin >> choiceBirthYear;
        switch(choiceBirthYear)
        {
        case 2:
            Computers = _Cservice.Alpha();
            Computers = _Cservice.buildYear();
            break;
        default: // if 1 or something other
            Computers = _Cservice.Alpha();
            Computers = _Cservice.reBuildYear();
            break;
        }
        break;
    }
    system(CLEAR);
    displayComputerVector(Computers);
}

void ConsoleUI::searchComputer()
{
    {
        vector<Computer> SearchComputers;

        char keepSearching = 'y';

        while (keepSearching == 'y')
        {
            SearchComputers= _Cservice.serviceToVector(SearchComputers);

            char moreConditions = 'y';

            bool conditionAvailable[] = {0,0,0,0}; // Stores types of search you are using.
            string searchString[4]; // Stores types of search
            searchString[0] = "\t 1. Name \n";
            searchString[1] = "\t 2. Type \n";
            searchString[2] = "\t 3. Build Year \n";
            searchString[3] = "\t 4. Built? \n";


            while (moreConditions == 'y' && (!(conditionAvailable[0] && conditionAvailable[1] && conditionAvailable[2] && conditionAvailable[3])))
            {
                int conditionNum;
                for (int i = 0; i < 4; i++)
                {
                    if (!conditionAvailable[i])
                    {
                        cout << searchString[i];
                    }
                }
                cout << "What do you want to search for? ";
                while(!(cin>>conditionNum))
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter corresponding number from 1-3: ";
                }
                //Search by name
                if ((conditionNum == 1) & (conditionAvailable[0] == 0))
                {
                    string nameForSearch;
                    cout << "What name do you want to search for? ";
                    while (!(cin >> nameForSearch))
                    {
                        getline(cin, nameForSearch);
                    }
                    SearchComputers = _Cservice.SearchName(SearchComputers, nameForSearch);
                }
                //search by type
                else if ((conditionNum == 2) & (conditionAvailable[1] == 0) )
                {
                    string typeForSearch;
                    cout << "What type do you want to search for? ";
                    while (!(cin >> typeForSearch))
                    {
                        getline(cin, typeForSearch);
                    }
                    SearchComputers = _Cservice.SearchType(SearchComputers, typeForSearch);
                }
                //search by build year
                else if ((conditionNum == 3) & (conditionAvailable[2] == 0))
                {
                    int buildYearForSearch;
                    cout << "What build year do you want to search for? ";
                    while(!(cin>>buildYearForSearch))
                    {
                        cin.clear();
                        cin.ignore(10000,'\n');
                        cout << "Enter build year only in numbers(YYYY): ";
                    }
                    SearchComputers = _Cservice.SearchBuildYear(SearchComputers, buildYearForSearch);
                }
                //search by Built
                else if ((conditionNum == 4) & (conditionAvailable[3] == 0))
                {
                    SearchComputers = _Cservice.SearchBuildYear(SearchComputers, 0);
                }
                conditionAvailable[conditionNum-1] = 1;

                //add type of search
                cout << "Do you want to add another condition (y/n)? ";
                while(!(cin>>moreConditions) | (!((moreConditions== 'y')|(moreConditions == 'Y') | (moreConditions == 'n') | (moreConditions == 'N'))))
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter only y/Y for  or n/N: ";
                }
                cout << " \n";
            }

            _Cservice.deleteDublicateVector(SearchComputers);


            if (SearchComputers.size() == 0)
            {
                system(CLEAR);
                cout << "No Computer matches this search \a\n";
            }
            else
            {
                system(CLEAR);
                cout << "Displaying search results: \n";
                displayComputerVector(SearchComputers);
            }


            cout << "\nDo you want to search again(y/n)? ";
            while(!(cin>>keepSearching) | !((keepSearching== 'y')|(keepSearching == 'Y') | (keepSearching == 'n') | (keepSearching == 'N')))
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter only y/Y for  or n/N: ";
            }
        }
    }
}

void ConsoleUI::deleteFromFileComputer()
{
    vector<Computer> Computers;
    Computers = _Cservice.serviceToVector(Computers);
    int id;
    string trueName;
    displayComputerVector(Computers, 1);

    cout << "\nEnter the ID of the Computer you want to delete: ";
    while(!(cin >> id) | (id < 1) | (id > Computers.size()))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding numbers: ";
    }

    trueName = Computers.at(id-1).getName();
    _Cservice.deleteComputer(trueName);
    Computers.clear();
    Computers = _Cservice.serviceToVector(Computers);
    system(CLEAR);
    displayComputerVector(Computers);
}

void ConsoleUI::editComputer()
{
    string newName;
    string newType;
    int newYear;
    vector<Computer> Computers;
    Computers = _Cservice.serviceToVector(Computers);
    int id;
    string trueName;
    //couts vector with ID
    displayComputerVector( Computers, 1 );

    cout << "\nEnter the ID of the person you want to edit? ";
    while(!(cin >> id) | (id < 1) | (id > Computers.size()))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding id: ";
    }

    trueName = Computers.at(id-1).getName();

    cout << "What do you want to edit?\n "
         <<"\t 1. Name \n"
         <<"\t 2. Type \n"
         <<"\t 3. Build Year \n";

    //what to change
    cout << "Your choice: ";
    int editChoice;
    while ( !(cin >> editChoice) | ( editChoice < 1 ) | ( editChoice > 4 ) )
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only correspondings number from 1-4 ";
    }
    switch(editChoice)
    {
    case 1:
        cout << "Enter new name: ";
        while (newName.empty())
        {
            cout << "Name(English characters only): ";
            cin.ignore(10000,'\n');
            getline(cin, newName);
        }
        if (_COP.checkIfSame(Computers, newName))
        {
            system(CLEAR);
            _Cservice.editName(trueName, newName);
            Computers.clear();
            Computers = _Cservice.serviceToVector(Computers);
            displayComputerVector(Computers);
        }
        else
        {
            system(CLEAR);
            cout << "This name has already been added. Nothing was edited\a\n";
        }
        break;
    case 2:
        cout << "Enter new type: ";
        while (newType.empty())
        {
            cout << "Name(English characters only): ";
            cin.ignore(10000,'\n');
            getline(cin, newType);
        }
        system(CLEAR);
        _Cservice.editType(trueName, newType);
        Computers.clear();
        Computers = _Cservice.serviceToVector(Computers);
        displayComputerVector(Computers);
        break;
    case 3:
        cout << "Enter new year: ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        system(CLEAR);
        _Cservice.editBuildYear(trueName, newYear);
        Computers.clear();
        Computers = _Cservice.serviceToVector(Computers);
        displayComputerVector(Computers);
        break;
    default:
    {
        cout<<"\tInvalid entry!\a"<< endl;
    }

    }
}

void ConsoleUI::displayComputerVector( vector<Computer> printIt, int x )
{
    cout << "\n";
    //couts ID if you want
    if (x == 1)
    {
        cout << "ID" << "\t";
    }
    cout << "Name"<< "\t\t\t\t" << "Type" << "\t\t\t\t\t" << "Build year" << endl;
    cout <<"=================================================================================\n";

    for(size_t i = 0; i < printIt.size(); i++)
    {
        //couts ID number if you want
        cout.setf(ios::left);
        if (x == 1)
        {
            cout.width(8);
            cout << i+1;
        }
        cout.width(32);
        cout << printIt[i].getName();

        cout.width(40);
        cout << printIt[i].getType();

        if (!(printIt[i].getBuildYear() == 0))
        {
            cout.width(15);
            cout.width(12);
            cout << printIt[i].getBuildYear() << endl;
        }
        else
        {
            cout.width(15);
            cout << '-'
                 << "-\n";
        }
    }
    cout << endl;
}

void ConsoleUI::about()
{
    cout << endl <<"\tABOUT" << endl
         << "\tComputer Scientist and Notable Computers Linking Software (CSANCLS)" << endl
         << "\tCreated by: Group 7" << endl
         << "\tMembers: Andri Thor Sveinbjornsson\n"
         << "\t         Bjorg Arna Elfarsdottir\n"
         << "\t         Fridrik Thjalfi Stefansson\n"
         << "\t         Isabella Yr Finnsdottir\n"
         << "\t         Margret Kristin Waage Bjornssdottir\n"
         << "\t         Soley Asgeirsdottir\n";
}

void ConsoleUI::teamLogo()
{
    //add team logo
    cout <<  "Computer Scientist and Notable Computers Linking Software\n"
             <<"-------------------------------------------------------------------------------------------------------\n"
             <<"|   ,ad8888ba,    ad88888ba          db         888b      88    ,ad8888ba,   88            ad88888ba  |  \n"
             <<"|  d8\"'    `\"8b  d8\"     \"8b        d88b        8888b     88   d8\"'    `\"8b  88           d8\"     \"8b | \n"
             <<"| d8'            Y8,               d8'`8b       88 `8b    88  d8'            88           Y8,         | \n"
             <<"| 88             `Y8aaaaa,        d8'  `8b      88  `8b   88  88             88           `Y8aaaaa,   | \n"
             <<"| 88               `\"\"\"\"\"8b,     d8YaaaaY8b     88   `8b  88  88             88             `\"\"\"\"\"8b, | \n"
             <<"| Y8,                    `8b    d8\"\"\"\"\"\"\"\"8b    88    `8b 88  Y8,            88                   `8b | \n"
             <<"|  Y8a.    .a8P  Y8a     a8P   d8'        `8b   88     `8888   Y8a.    .a8P  88           Y8a     a8P | \n"
             <<"|   `\"Y8888Y\"'    \"Y88888P\"   d8'          `8b  88      `888    `\"Y8888Y\"'   88888888888   \"Y88888P\"  |  \n"
             <<"-------------------------------------------------------------------------------------------------------";
}
