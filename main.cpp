#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string studentName;
    int studentID;
    double studentGPA;
    Node *pNext;
};

void createList();
void addNode();
void deleteNode();
void searchNode();
void modifyNode();
void displayList();
void purgeList();

int main()
{
    Node *pStart = NULL;
    int userChoice = 0;

    do 
    {
        cout << "-----------------------------------------------------------"
        << '\n' << "!!! MENU !!! "
        << '\n' << "1. Create list"
        << '\n' << "2. Add a node"
        << '\n' << "3. Delete a node"
        << '\n' << "4. Search for a node"
        << '\n' << "5. Modify a node"
        << '\n' << "6. Display list"
        << '\n' << "7. Purge the list"
        << '\n' << "8. Exit"
        << '\n' << "-----------------------------------------------------------"
        << endl;
        cin >> userChoice;

        switch (userChoice) 
        {
            case 1:
                createList();
                break;
            case 2:
                addNode();
                break;
            case 3:
                deleteNode();
                break;
            case 4:
                searchNode();
                break;
            case 5:
                modifyNode();
                break;
            case 6:
                displayList();
                break;
            case 7:
                purgeList();
                break;
            case 8:
                exit(0);
                break;
            default:
                break;
        }
    } while (userChoice != 0);
    return 0;
}