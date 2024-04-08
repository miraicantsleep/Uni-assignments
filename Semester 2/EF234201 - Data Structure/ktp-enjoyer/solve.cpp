#include <iostream>
#include <unordered_map>
#include <iomanip>
using namespace std;

// ===================== SETUP ======================= //
typedef struct
{
    string name;
    string religion;
    string address;
    string birthPlace;
    tm birthDate;
} KTPtype;

/* ====================== NOTES ========================
    1. For some reason, getline have a trailing buffer that ruins the input stream, but cin don't
    2. sorry for inconsistency in error handling :(
*/

// Initiate map
unordered_map<string, KTPtype> database;

void banner()
{
    cout << "KTP Data something something\n";
}

void menu()
{
    cout << "1. Input data\n"
         << "2. Read data\n"
         << "3. Delete data\n"
         << "4. Exit\n";
}

void initProgram()
{
    cout << "\033[2J\033[1;1H";
    banner();
    menu();
}

void formatOutput(auto index)
{
    cout << "=================================[PERSON DATA]=================================\n\n";
    cout << "NIK\t\t\t: " << index->first << "\n";
    cout << "Name\t\t\t: " << index->second.name << "\n";
    cout << "Religion\t\t: " << index->second.religion << "\n";
    cout << "Address\t\t\t: " << index->second.address << "\n";
    cout << "Place and Date of Birth\t: " << index->second.birthPlace << ", " << put_time(&index->second.birthDate, "%d-%m-%Y") << "\n\n";
    cout << "===============================================================================\n\n";
    
}

string inputNIK()
{
    string NIKinput;
    while (true)
    {
        cout << "Enter NIK number: ";
        getline(cin, NIKinput);

        if (NIKinput.find_first_not_of("0123456789") == string::npos)
        {
            break;
        }
        else
        {
            cerr << "Invalid input! NIK should only contain numeric characters.\n";
        }
    }
    return NIKinput;
}
void inputData()
{
    cin.ignore(); // C strings shenanigans
    KTPtype newData;

    string keyNIK = inputNIK();

    cout << "Enter full name: ";
    getline(cin, newData.name);

    cout << "Enter religion: ";
    getline(cin, newData.religion);

    cout << "Enter address: ";
    getline(cin, newData.address);

    cout << "Enter birth place: ";
    getline(cin, newData.birthPlace);

    cout << "Enter birth date (DD-MM-YYYY): ";
    cin >> get_time(&newData.birthDate, "%d-%m-%Y");

    database[keyNIK] = newData;

    cout << "Data added successfully! Press Enter key to continue...";
    cin.ignore();
    cin.get();
    initProgram();
}

void searchData()
{
    cin.ignore();

    string searchKey = inputNIK();

    auto index = database.find(searchKey);

    if (index != database.end())
    {
        cout << "Data found!\n\n";
        formatOutput(index);
    }
    else
    {
        cout << "Bruh\n";
    }

    cout << "Press Enter key to continue...";
    cin.get();
    initProgram();
}

void deleteData()
{
    cin.ignore();

    string searchKey = inputNIK();

    auto index = database.find(searchKey);

    if (index != database.end())
    {
        cout << "Data found!\n";
        formatOutput(index);

        cout << "Are you sure you want to delete this data? ";
        char userInput;
        cin >> userInput;
        if (userInput == 'y' || userInput == 'Y')
        {
            database.erase(index);
            cout << "Data deleted successfully!\n";
        }
        else
        {
            cout << "Deletion cancelled\n";
        }
        cin.ignore();
    }
    else
    {
        cout << "Bruh\n";
    }

    cout << "Press Enter key to continue...";
    cin.get();
    initProgram();
}

int main()
{
    while (true)
    {
        initProgram();
        string userInput;
        cin >> userInput;

        // Use a try catch to process unexpected input
        try
        {
            int userChoice = stoi(userInput);
            switch (userChoice)
            {
            case 1:
                inputData();
                break;
            case 2:
                searchData();
                break;
            case 3:
                deleteData();
                break;
            case 4:
                cout << "Are you sure you want to exit? (y/n) ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    cout << "adios" << endl;
                    exit(0);
                }
                else if (choice == 'N' || choice == 'n')
                {
                    initProgram();
                }
                break;
            default:
                cout << "Not a valid choice! Press Enter key to continue...";
                cin.ignore();
                cin.get();
                initProgram();
                break;
            }
        }
        catch (const invalid_argument &ia)
        {
            cerr << "Not a number! Press Enter key to continue...";
            cin.ignore();
            cin.get();
            initProgram();
        }
    }

    return 0;
}