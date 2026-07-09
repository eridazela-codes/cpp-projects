#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

const string FILENAME = "contacts.txt";

// Save all contacts to file (overwrites the file)
void saveToFile(const vector<Contact>& contacts) {
    ofstream outFile(FILENAME);
    for (const auto& c : contacts) {
        outFile << c.name << "," << c.phone << "," << c.email << endl;
    }
    outFile.close();
}

// Load all contacts from file
vector<Contact> loadFromFile() {
    vector<Contact> contacts;
    ifstream inFile(FILENAME);
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        Contact c;
        getline(ss, c.name, ',');
        getline(ss, c.phone, ',');
        getline(ss, c.email, ',');
        contacts.push_back(c);
    }
    inFile.close();
    return contacts;
}

void addContact(vector<Contact>& contacts) {
    Contact c;
    cout << "Enter name: ";
    cin >> c.name;
    cout << "Enter phone: ";
    cin >> c.phone;
    cout << "Enter email: ";
    cin >> c.email;

    contacts.push_back(c);
    saveToFile(contacts);
    cout << "Contact saved successfully!\n" << endl;
}

void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts found.\n" << endl;
        return;
    }
    cout << "\n=== Contact List ===" << endl;
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". " << contacts[i].name 
             << " | " << contacts[i].phone 
             << " | " << contacts[i].email << endl;
    }
    cout << endl;
}

void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to delete.\n" << endl;
        return;
    }
    displayContacts(contacts);
    cout << "Enter contact number to delete: ";
    int index;
    cin >> index;

    if (index < 1 || index > (int)contacts.size()) {
        cout << "Invalid number!\n" << endl;
        return;
    }
    contacts.erase(contacts.begin() + (index - 1));
    saveToFile(contacts);
    cout << "Contact deleted successfully!\n" << endl;
}

int main() {
    vector<Contact> contacts = loadFromFile();
    int choice;

    do {
        cout << "=== Contact Book ===" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                deleteContact(contacts);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!\n" << endl;
        }
    } while (choice != 4);

    return 0;
}