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

Node *pStart = NULL;
bool isListEmpty = true;

int main()
{
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
        << '\n' << "Enter your choice: "
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

void createList()
{
    if (pStart == NULL)
    {
        pStart = new Node;
        pStart->pNext = NULL;
        isListEmpty = true;
        cout << "List has been created." << endl;
    }
    else
    {
        cout << "List has already been created." << endl;
    }
}

void addNode()
{
    if (pStart == NULL)
    {
        cout << "List was not created. Please create the list first." << endl;
    }
    else
    {
        Node *temp = new Node;

        cout << "Enter student name: ";
        cin >> temp->studentName;

        cout << "Enter the student's ID (# from 100-999): ";
        cin >> temp->studentID;
        // Input validation
        while (!(temp->studentID >= 100 && temp->studentID <= 999))
        {
            cout << "!! ERROR: Please enter a valid number from 100-999: ";
            cin >> temp->studentID;
        }
        // Check if a duplicate record is found
        Node *temp2 = pStart;
        while (temp2 != NULL)
        {
            if (temp2->studentID == temp->studentID)
            {
                cout << "!! ERROR: A duplicate record exists. Please choose a different ID or modify an existing ID." << endl;
                return;
            }
            temp2 = temp2->pNext;
        }


        cout << "Enter the student's GPA: ";
        cin >> temp->studentGPA;

        temp->pNext = NULL;

        if (isListEmpty == true)
        {
            pStart = temp;
            cout << "First node added." << endl;
            isListEmpty = false;
        }
        else
        {
            Node *temp2 = pStart;
            Node *prevNode = NULL;

            // Iterate through list until inputted ID is greater than the established node
            while (temp2 != NULL && temp2->studentID < temp->studentID)
            {
                prevNode = temp2;
                temp2 = temp2->pNext;
            }

            if (prevNode == NULL) // Inserting before the first node
            {
                temp->pNext = pStart;
                pStart = temp;
            }
            else
            {
                prevNode->pNext = temp;
                temp->pNext = temp2;
            }

            cout << "New node successfully added." << endl;
        }
    }
}

void deleteNode()
{
    if (pStart == NULL)
    {
        cout << "List was not created. Please create the list first." << endl;
    }
    else if (isListEmpty == true)
    {
        cout << "List is empty. There are no nodes to delete." << endl;
    }
    else
    {
        int inputID = 0;
        
        cout << "Enter the student ID (# 100-999) of the record to delete: ";
        cin >> inputID;

        // Input validation
        while (!(inputID >= 100 && inputID <= 999))
        {
            cout << "!! ERROR: Please enter a valid number from 100-999: ";
            cin >> inputID;
        }
    }
}

void searchNode()
{

}

void modifyNode()
{

}

void displayList()
{
    Node *temp = pStart;

    do
    {
        if (temp == NULL)
        { 
            cout << "List is empty." << endl;
        }
        else
        {
            cout << "| Name: " << temp->studentName << "  |  " << "ID: " << temp->studentID << "  |  " << "GPA: " << temp->studentGPA << "  |" << endl;
            temp = temp->pNext;
        }
    } while (temp != NULL);
}

void purgeList()
{

}