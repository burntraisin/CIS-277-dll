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
        << '\n' << "Enter your choice: ";
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
    if ((pStart == NULL) && (isListEmpty == true))
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

        while (!(temp->studentID >= 100 && temp->studentID <= 999)) // Input validation
        {
            cout << "!! ERROR: Please enter a valid number from 100-999: ";
            cin >> temp->studentID;
        }

        Node *temp2 = pStart; // Check if a duplicate record is found
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
            cout << "NOTICE: First node added." << endl;
            isListEmpty = false;
        }
        else
        {
            Node *temp2 = pStart;
            Node *prevNode = NULL;

            while (temp2 != NULL && temp2->studentID < temp->studentID) // Iterate through list until inputted ID is greater than the established node
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

            cout << "NOTICE: New node successfully added." << endl;
        }
    }
}

void deleteNode()
{
    if (pStart == NULL || isListEmpty == true)
    {
        cout << "There are no nodes to delete." << endl;
    }
    else
    {
        int inputID = 0;
        
        cout << "Enter the student ID (# 100-999) of the record to delete: ";
        cin >> inputID;

        while (!(inputID >= 100 && inputID <= 999))
        {
            cout << "!! ERROR: Please enter a valid number from 100-999: ";
            cin >> inputID;
        }

        Node *temp = pStart; // Iterate through list until inputted ID matches
        Node *prevNode = NULL;
        int matchID = 0;
        while (temp != NULL && temp->studentID != inputID)
        {
            matchID = temp->studentID;
            prevNode = temp;
            temp = temp->pNext;
        }
        // By now, the default temp->studentID == inputID is assumed to have happened
        bool isMatch = false; // Handle deleting a node that is not in the list
        if (matchID == inputID)
        {
            isMatch = true;
        }
        else
        {
            isMatch = false;
        }

        if (isMatch == false)
        {
            cout << "Record was not found." << endl;
            return;
        }
        
        if (prevNode == NULL) // Deleting the first node
        {
            prevNode = temp->pNext;
            pStart = prevNode; // Update pStart
            delete temp;
        }
        else if (temp->pNext == NULL) // Check if we've reached the last node
        {
            prevNode->pNext = NULL;
            delete temp;
        }
        else
        {
            prevNode->pNext = temp->pNext;
            delete temp;
        }
    }
}

void searchNode()
{
    if (pStart == NULL || isListEmpty == true)
    {
        cout << "There are no nodes to search." << endl;
    }
    else
    {
        int inputID = 0;

        cout << "Enter the student ID (# 100-999) of the record to display: ";
        cin >> inputID;

        while (!(inputID >= 100 && inputID <= 999))
        {
            cout << "!! ERROR: Please enter a valid number from 100-999: ";
            cin >> inputID;
        }

        Node *temp = pStart;
        bool isMatch = false;
        while (temp != NULL)
        {
            if (temp->studentID == inputID)
            {
                cout << "| Name: " << temp->studentName << "  |  " << "ID: " << temp->studentID << "  |  " << "GPA: " << temp->studentGPA << "  |" << endl;
                isMatch = true;
                break;
            }
            temp = temp->pNext;
        }
        if (isMatch == false)
        {
            cout << "Record was not found." << endl;
        }
    }
}

void modifyNode()
{
    if (pStart == NULL || isListEmpty == true)
    {
        cout << "There are no nodes to modify." << endl;
    }
    else
    {
        int inputID = 0;

        cout << "Enter the student ID (# 100-999) of the record to modify: ";
        cin >> inputID;

        while (!(inputID >= 100 && inputID <= 999))
        {
            cout << "!! ERROR: Please enter a valid number from 100-999: ";
            cin >> inputID;
        }

        Node *temp = pStart;
        bool isMatch = false;
        while (temp != NULL)
        {
            if (temp->studentID == inputID)
            {
                string originalName = temp->studentName;
                double originalGPA = temp->studentGPA;

                cout << "Enter the NEW name: ";
                cin >> temp->studentName;
                cout << "Enter the NEW GPA: ";
                cin >> temp->studentGPA;

                cout << "ORIGINAL: ";
                cout << "| Name: " << originalName << "  |  " << "ID: " << temp->studentID << "  |  " << "GPA: " << originalGPA << "  |" << endl;

                cout << "NEW CHANGES TO BE IMPLEMENTED: ";
                cout << "| Name: " << temp->studentName << "  |  " << "ID: " << temp->studentID << "  |  " << "GPA: " << temp->studentGPA << "  |" << endl;

                isMatch = true;
                break;
            }
            temp = temp->pNext;
        }
        if (isMatch == false)
        {
            cout << "Record was not found." << endl;
        }
    }
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
    Node *temp = pStart;
    Node *prevNode = NULL;

    if (pStart == NULL || isListEmpty == true)
    { 
        cout << "There are no nodes to delete." << endl;
        return;
    }

    while (temp != NULL)
    {
        prevNode = temp;
        temp = temp->pNext;
        delete prevNode;
    }

    pStart = NULL;
    cout << "All nodes have been purged. The list is empty." << endl;
}