#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Add element at the end of the list
    void addAtEnd(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Add element at the beginning of the list
    void addAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    // Delete the first element that matches this value
    void deleteElement(int value) {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        if (head->value == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Element deleted!" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->value != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Element not found!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Element deleted!" << endl;
    }

    // Display the entire list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor - frees memory when the program ends
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n=== Linked List Menu ===" << endl;
        cout << "1. Add at end" << endl;
        cout << "2. Add at beginning" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Display list" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.addAtEnd(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.addAtBeginning(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteElement(value);
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}