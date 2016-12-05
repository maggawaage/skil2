#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "consoleui.h"
#include "person.h"
#include "computer.h"
#include "dataaccess.h"

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
        cout << "\t1. Add person  \n";
        cout << "\t2. Print list(sort) \n";
        cout << "\t3. Search list\n";
        cout << "\t4. Delete from list\n";
        cout << "\t5. Edit list\n";
        cout << "\t6. Quit \n";
        cout << endl;
        cout << "Your choice: ";
        while(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter corresponding number from 1-6: ";
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
                 cout<<"\tInvalid entry!"<<endl;
            }
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
                 cout<<"\tInvalid entry!"<<endl;
            }
            break;
        case 3:
            cout << "Do you want to delete out a list of person or a computer?\n";
            cout << "\t1. Print out person  \n";
            cout << "\t2. Print out computer \n";
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
                 cout<<"\tInvalid entry!"<<endl;
            }
        case 4:
            cout << "Do you want to delete out a list of person or a computer?\n";
            cout << "\t1. Print out person  \n";
            cout << "\t2. Print out computer \n";
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
                 cout<<"\tInvalid entry!"<<endl;
            }
        case 5:
                cout << "Do you want to print out a list of person or a computer?\n";
                cout << "\t1. Print out person  \n";
                cout << "\t2. Print out computer \n";
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
                     cout<<"\tInvalid entry!"<<endl;
                }
        case 6:
            exit(0);
            break;
        default:
            cout<<"\tInvalid entry!"<<endl;
        }
    }
    while(true);
}

void ConsoleUI::writeComputer()
{
    string name;
    string type;
    int buildYear;

    //getting valid name,type and buildYear
    cout << "Name(English characters only): ";
    cin.ignore(10000,'\n');
    getline(cin, name);

    cout << "Type of computer";
    cin.ignore(10000,'\n');
    getline(cin, type);

    cout << "Build year (if it was not built enter 0): ";
    while(!(cin>>buildYear))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter build year only in numbers(YYYY): ";
    }

    //Nýtt DA
    /*
    //check if name is already in file if not move to file
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    Person PER;
    PersonService PS;
    if(PER.checkIfSame(Persons, name))
    {
        PS.serviceToFile(name, type, buildYear);
    }
    else
    {
        cout << "\nError: This name has already been added.\n";
    }
    */
}

void ConsoleUI::writePerson()
{
    string name;
    char gender;
    int birthYear;
    int deathYear;

    //getting valid name,gender,birthYear and deathYear
    cout << "Name(English characters only): ";
    cin.ignore(10000,'\n');
    getline(cin, name);
    cout << "If male enter m. If female enter f:  ";
    while(!(cin>>gender) | !((gender == 'm')|(gender == 'M') | (gender == 'f') | (gender == 'F')))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only m/M for male or f/F for femaler: ";
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

    //check if name is already in file if not move to file
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    Person PER;
    PersonService PS;
    if(PER.checkIfSame(Persons, name))
    {
        PS.serviceToFile(name, gender, birthYear, deathYear);
    }
    else
    {
        cout << "\nError: This name has already been added.\n";
    }
}

//Laga ad computer
void ConsoleUI::sortItComputer()
{
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
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
    case 1: //sorts alphabetically
        cout << "\t1. From A-Z  \n";
        cout << "\t2. From Z-A \n";
        cout << "Your choice: ";
        int choiceAlpha;
        cin >> choiceAlpha;
        switch(choiceAlpha)
        {
        case 2:
            _service.reAlpha(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
        }
        break;
    case 2: //sorts by witch gender first and alphabetically
        cout << "\t1. First female  \n";
        cout << "\t2. First male \n";
        cout << "Your choice(default: ";
        int choiceGender;
        cin >> choiceGender;
        switch(choiceGender)
        {
        case 2:
            _service.alpha(Persons);
            _service.reGender(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
            _service.gender(Persons);
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
            _service.alpha(Persons);
            _service.year(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
            _service.reYear(Persons);
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
            _service.alpha(Persons);
            _service.death(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
            _service.reDeath(Persons);
        }
        break;
    }
    displayVector(Persons);
}

void ConsoleUI::sortItPerson()
{
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
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
    case 1: //sorts alphabetically
        cout << "\t1. From A-Z  \n";
        cout << "\t2. From Z-A \n";
        cout << "Your choice: ";
        int choiceAlpha;
        cin >> choiceAlpha;
        switch(choiceAlpha)
        {
        case 2:
            _service.reAlpha(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
        }
        break;
    case 2: //sorts by witch gender first and alphabetically
        cout << "\t1. First female  \n";
        cout << "\t2. First male \n";
        cout << "Your choice(default: ";
        int choiceGender;
        cin >> choiceGender;
        switch(choiceGender)
        {
        case 2:
            _service.alpha(Persons);
            _service.reGender(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
            _service.gender(Persons);
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
            _service.alpha(Persons);
            _service.year(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
            _service.reYear(Persons);
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
            _service.alpha(Persons);
            _service.death(Persons);
            break;
        default: // if 1 or something other
            _service.alpha(Persons);
            _service.reDeath(Persons);
        }
        break;
    }
    displayVector(Persons);
}

void ConsoleUI::searchPerson()
{
    PersonService PA;
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
            //search by name
            if ((conditionNum == 1) & (conditionAvailable[0] == 0))
            {
                string nameForSearch;
                cout << "What name do you want to search for? ";

                SearchPersons = PA.SearchName(SearchPersons, nameForSearch);
            }
            //search by gender
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
                SearchPersons = PA.SearchGender(SearchPersons, genderForSearch);
            }
            //search by birth year
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
                SearchPersons = PA.SearchBirthYear(SearchPersons, birthYearForSearch);
            }
            //search by death year
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
                SearchPersons = PA.SearchDeathYear(SearchPersons, deathYearForSearch);
            }
            //search by alive
            else if ((conditionNum == 5) & (conditionAvailable[3] == 0))
            {
                SearchPersons = PA.SearchDeathYear(SearchPersons, 0);
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

        PA.deleteDublicateVector(SearchPersons);


        if (SearchPersons.size() == 0)
        {
            cout << "No person matches this search \n";
        }
        else
        {
            cout << "Displaying search results: \n";
            displayVector(SearchPersons);
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

//Laga ad computer
void ConsoleUI::searchComputer()
{
    PersonService PA;
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
            //search by name
            if ((conditionNum == 1) & (conditionAvailable[0] == 0))
            {
                string nameForSearch;
                cout << "What name do you want to search for? ";

                SearchPersons = PA.SearchName(SearchPersons, nameForSearch);
            }
            //search by gender
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
                SearchPersons = PA.SearchGender(SearchPersons, genderForSearch);
            }
            //search by birth year
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
                SearchPersons = PA.SearchBirthYear(SearchPersons, birthYearForSearch);
            }
            //search by death year
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
                SearchPersons = PA.SearchDeathYear(SearchPersons, deathYearForSearch);
            }
            //search by alive
            else if ((conditionNum == 5) & (conditionAvailable[3] == 0))
            {
                SearchPersons = PA.SearchDeathYear(SearchPersons, 0);
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

        PA.deleteDublicateVector(SearchPersons);


        if (SearchPersons.size() == 0)
        {
            cout << "No person matches this search \n";
        }
        else
        {
            cout << "Displaying search results: \n";
            displayVector(SearchPersons);
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

<<<<<<< HEAD
void ConsoleUI::deleteFromFileComputer()
{
    vector<Computer> Computers;
    //Computers = _service.serviceToVector(Computers );
    int id;
    //displayVector(Computers , 1);

    cout << "\nEnter the ID of the person you want to delete: ";
    while(!(cin >> id))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding numbers: ";
    }

    Computers .erase (Computers .begin()+id-1);

    //_service.serviceToFile(Computers );
    //displayVector(Computers);
}

=======
>>>>>>> 95ee7ac302143045fd0a983bfd38ac00153c5d31
void ConsoleUI::deleteFromFilePerson()
{
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    int id;
    displayVector(Persons, 1);

    cout << "\nEnter the ID of the person you want to delete: ";
    while(!(cin >> id))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding numbers: ";
    }

    Persons.erase (Persons.begin()+id-1);

    _service.serviceToFile(Persons);
    displayVector(Persons);
}

<<<<<<< HEAD
void ConsoleUI::editPerson()
=======
void ConsoleUI::deleteFromFileComputer()
{
    vector<Computer> Computers;
    Computers = _service.serviceToVector(Computers);
    int id;
    displayVector(Computers, 1);

    cout << "\nEnter the ID of the person you want to delete: ";
    while(!(cin >> id))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding numbers: ";
    }

    Computers.erase (Computers.begin()+id-1);

    _service.serviceToFile(Computers);
    displayVector(Computers);
}


void ConsoleUI::edit()
>>>>>>> 95ee7ac302143045fd0a983bfd38ac00153c5d31
{
    string newName;
    int newYear;
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    int id;
    //couts vector with ID
    displayVector( Persons, 1 );

    char female = 'f';
    char male = 'm';

    cout << "\nEnter the ID of the person you want to edit? ";
    while(!(cin >> id))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding numbers: ";
    }
    cout << "What do you want to edit?\n "
         <<"\t 1. Name \n"
        <<"\t 2. Gender \n"
       <<"\t 3. Year of birth \n"
      <<"\t 4. Year of death  \n";

    //what to change
    cout << "Your choice: ";
    int editChoice;
    cin >> editChoice;
    switch(editChoice)
    {
    case 1:
        cout << "Enter new name: ";
        cin.ignore(10000,'\n');
        getline(cin, newName);
        Persons.at(id-1).setName(newName);
        break;
    case 2:
        if((Persons.at(id-1).getGender())==male)
        {
            Persons.at(id-1).setGender(female);
        }
        else
        {
            Persons.at(id-1).setGender(male);
        }
        break;
    case 3:
        cout << "Enter new year: ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        Persons.at(id-1).setBirthYear(newYear);
        break;
    case 4:
        cout << "Enter new year: ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        Persons.at(id-1).setDeathYear(newYear);
        break;
    default:
    {
        cout<<"\tInvalid entry!"<<endl;
    }

    }
    _service.serviceToFile(Persons);
    displayVector(Persons);
}

void ConsoleUI::editComputer()
{
    string newName;
    string newType;
    int newYear;
    vector<Computer> Computers;
    //computer
   // Computers = _service.serviceToVector(Computers);
    int id;
    //couts vector with ID
    //displayVector( Computers, 1 );

    cout << "\nEnter the ID of the computer you want to edit? ";
    while(!(cin >> id))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter only corresponding numbers: ";
    }
    cout << "What do you want to edit?\n "
         <<"\t 1. Name \n"
        <<"\t 2. Type \n"
       <<"\t 3. Build year \n";

    //what to change
    cout << "Your choice: ";
    int editChoice;
    cin >> editChoice;
    switch(editChoice)
    {
    case 1:
        cout << "Enter new name: ";
        cin.ignore(10000,'\n');
        getline(cin, newName);
        //Persons.at(id-1).setName(newName);
        break;
    case 2:
        cout << "Enter new type: ";
        cin.ignore(10000,'\n');
        getline(cin, newType);
        Computers.at(id-1).setType(newType);
        break;
    case 3:
        cout << "Enter new year: ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        //Persons.at(id-1).setBuildYear(newYear);
        break;
    default:
    {
        cout<<"\tInvalid entry!"<<endl;
    }

    }
   // _service.serviceToFile(Persons);
   // displayVector(Persons);
}

void ConsoleUI::displayVector( vector<Person> printIt, int x )
{
    cout << "\n";
    //couts ID if you want
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
        //couts ID number if you want
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

void ConsoleUI::teamLogo()
{
    //add team logo
    cout <<  "made by:\n"
          <<"--------------------------------------------------\n"
         <<"|  _____ _____    _    __  __   _____    ____    |\n"
        <<"| |_   _|____ |  / \\  |  \\/  | |  ___|	||\"\"||	 |\n"
       <<"|   | |   |_  | / _ \\ | |\\/| |  \\ \\     ||__||   |\n"
      <<"|   | |  ___| |/ ___ \\| |  | |   \\ \\    [ -=.]`) |\n"
     <<"|   |_| |_____/_/   \\_|_|  |_|    \\_\\   ====== 0 |\n"
    <<"|________________________________________________|\n";
}
