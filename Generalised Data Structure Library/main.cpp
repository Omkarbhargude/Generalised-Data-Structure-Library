#include <iostream>
#include <limits> 
#include "genlib.h" 
using namespace std;

// Function prototypes to handle different data structure menus
void runStackMenu();
void runQueueMenu();
void runSinglyLinkedListMenu();

// Main menu loop
int main() {
    int choice = 0;

    while (true) {
        cout << "\n=============================================" << endl;
        cout << "         GENERIC DATA STRUCTURES MENU        " << endl;
        cout << "=============================================" << endl;
        cout << "1. Stack" << endl;
        cout << "2. Queue" << endl;
        cout << "3. Singly Linear Linked List" << endl;
        cout << "4. Singly Circular Linked List " << endl;
        cout << "5. Doubly Linear Linked List " << endl;
        cout << "6. Doubly Circular Linked List " << endl;
        cout << "7. Binary Search Tree " << endl;
        cout << "8. Sorting Algorithms " << endl;
        cout << "9. Searching Algorithms " << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                runStackMenu();
                break;

            case 2:
                runQueueMenu();
                break;

            case 3:
                runSinglyLinkedListMenu();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

// Function to handle Singly Linked List operations
void runSinglyLinkedListMenu() {
    Singly_LinkedList<int> intList;
    Singly_LinkedList<char> charList;
    Singly_LinkedList<float> floatList;
    Singly_LinkedList<string> sList;

    int choice = 0;
    char value, pos;

    while (true) {
        cout << "\n--- Singly Linear Linked List Menu ---" << endl;
        cout << "1. Insert at First" << endl;
        cout << "2. Insert at Last" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete at First" << endl;
        cout << "5. Delete at Last" << endl;
        cout << "6. Delete at Position" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Count Nodes" << endl;
        cout << "9. Search for an element" << endl;
        cout << "10. Search first occurrence" << endl;
        cout << "11. Search last occurrence" << endl;
        cout << "12. Search all occurrences" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                charList.InsertAtFirst(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                charList.InsertAtLast(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                charList.InsertAtPosition(value, pos);
                break;
            case 4:
                charList.DeleteAtFirst();
                break;
            case 5:
                charList.DeleteAtLast();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                charList.DeleteAtPosition(pos);
                break;
            case 7:
                charList.DisplayGenList();
                break;
            case 8:
                cout << "Number of nodes: " << charList.CountNodes() << endl;
                break;
            case 9:
                cout << "Enter value to search: ";
                cin >> value;
                if (charList.SearchListNode(value)) {
                    cout << "Element found." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 10:
                cout << "Enter value to search: ";
                cin >> value;
                pos = charList.SearchFirstOuccurence(value);
                if (pos != -1) {
                    cout << "First occurrence at position: " << pos << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 11:
                cout << "Enter value to search: ";
                cin >> value;
                pos = charList.SearchLastOuccurence(value);
                if (pos != -1) {
                    cout << "Last occurrence at position: " << pos << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 12:
                cout << "Enter value to search: ";
                cin >> value;
                cout << "Total occurrences: " << charList.SearchAllOuccurence(value) << endl;
                break;
            case 0:
                return; // Return to main menu
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

// Function to handle Singly Linked List operations
void runSinglyCLLMenu() {
    SinglyCLL<int> intList;
    SinglyCLL<char> charList;
    SinglyCLL<float> floatList;
    SinglyCLL<string> sList;

    int choice = 0;
    char value, pos;

    while (true) {
        cout << "\n--- Singly Linear Linked List Menu ---" << endl;
        cout << "1. Insert at First" << endl;
        cout << "2. Insert at Last" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete at First" << endl;
        cout << "5. Delete at Last" << endl;
        cout << "6. Delete at Position" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Count Nodes" << endl;
        cout << "9. Search for an element" << endl;
        cout << "10. Search first occurrence" << endl;
        cout << "11. Search last occurrence" << endl;
        cout << "12. Search all occurrences" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                charList.InsertAtFirst(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                charList.InsertAtLast(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                charList.InsertAtPosition(value, pos);
                break;
            case 4:
                charList.DeleteAtFirst();
                break;
            case 5:
                charList.DeleteAtLast();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                charList.DeleteAtPosition(pos);
                break;
            case 7:
                charList.DisplayGenList();
                break;
            case 8:
                cout << "Number of nodes: " << charList.CountNodes() << endl;
                break;
            case 9:
                cout << "Enter value to search: ";
                cin >> value;
                if (charList.SearchListNode(value)) {
                    cout << "Element found." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 10:
                cout << "Enter value to search: ";
                cin >> value;
                pos = charList.SearchFirstOuccurence(value);
                if (pos != -1) {
                    cout << "First occurrence at position: " << pos << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 11:
                cout << "Enter value to search: ";
                cin >> value;
                pos = charList.SearchLastOuccurence(value);
                if (pos != -1) {
                    cout << "Last occurrence at position: " << pos << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 12:
                cout << "Enter value to search: ";
                cin >> value;
                cout << "Total occurrences: " << charList.SearchAllOuccurence(value) << endl;
                break;
            case 0:
                return; // Return to main menu
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}


// Function to handle Stack operations
void runStackMenu() {
    Stack<int> intStack;
    int choice = 0;
    int value;

    while (true) {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "--------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                intStack.PushNode(value);
                break;
            case 2:
                value = intStack.PopNode();
                if (value != 0) { // Assuming 0 is not a valid pop result if stack is empty
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                intStack.DisplayNode();
                break;
            case 4:
                cout << "Number of elements: " << intStack.CountNode() << endl;
                break;
            case 0:
                return; // Return to main menu
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

// Function to handle Queue operations
void runQueueMenu() {
    Queue<int> intQueue;
    int choice = 0;
    int value;

    while (true) {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "--------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                intQueue.EnqueueNode(value);
                break;
            case 2:
                value = intQueue.DequeueNode();
                if (value != 0) { // Assuming 0 is not a valid dequeue result
                    cout << "Dequeued value: " << value << endl;
                }
                break;
            case 3:
                intQueue.DisplayNode();
                break;
            case 4:
                cout << "Number of elements: " << intQueue.CountNode() << endl;
                break;
            case 0:
                return; // Return to main menu
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

//

//      Functions to be add

//