#include <iostream>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
};

vector<Contact> contacts;

void addContact() {
    Contact c;
    cout << "Enter Name: ";
    cin >> c.name;
    cout << "Enter Phone Number: ";
    cin >> c.phone;

    contacts.push_back(c);
    cout << "Contact Added Successfully!\n";
}

void viewContacts() {
    if (contacts.empty()) {
        cout << "No Contacts Found!\n";
        return;
    }

    cout << "\n--- Contact List ---\n";
    for (int i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". " << contacts[i].name
             << " - " << contacts[i].phone << endl;
    }
}

void searchContact() {
    string name;
    cout << "Enter Name to Search: ";
    cin >> name;

    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].name == name) {
            cout << "Found: "
                 << contacts[i].name << " - "
                 << contacts[i].phone << endl;
            return;
        }
    }

    cout << "Contact Not Found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                cout << "Thank You!\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
