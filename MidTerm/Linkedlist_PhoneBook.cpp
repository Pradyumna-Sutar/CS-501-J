/* Justification: 
Dynamic Size: A phone book’s contact list can vary in size. Linked lists can dynamically adjust their size to accommodate new contacts without preallocating memory. Unlike vectors, which may need reallocation when reaching capacity, linked lists handle varying sizes efficiently.
Efficient Insertion and Deletion: Linked lists excel at adding or removing contacts. These operations have constant-time complexity (O(1)) at the beginning or end of the list. In contrast, vectors may require shifting elements during insertion or deletion.
No Wasted Space: Linked lists use memory proportional to the number of stored contacts. Vectors, due to their internal capacity, may allocate more memory than needed, potentially wasting space.
Non-Contiguous Memory: Linked lists don’t require continuous memory blocks. This flexibility is useful when memory is fragmented or when contact sizes vary.
Ease of Reordering: Reordering contacts (e.g., alphabetizing by name) is efficient with linked lists. Vectors might involve costly element shifting during such operations.
Flexible Node Structure: Linked lists can store additional data (e.g., email addresses) by extending the node structure without compromising memory efficiency.
*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
};

// Initialize a vector to store contacts
vector<Contact> contacts;

// Function to add a new contact to the list
void addContact() {
    Contact newContact;
    cout << "Enter the contact name: ";  // Prompt user for contact name
    cin >> newContact.name;  // Read the contact name from user input
    cout << "Enter the phone number: ";  // Prompt user for phone number
    cin >> newContact.phoneNumber;  // Read the phone number from user input
    contacts.push_back(newContact);  // Add the new contact to the vector
    cout << "Contact '" << newContact.name << "' with phone number '" << newContact.phoneNumber << "' added successfully!" << endl;  // Print success message
}

// Function to view all contacts in the list
void viewContacts() {
    if (contacts.empty()) {  // Check if the vector is empty
        cout << "No contacts found." << endl;  // Print a message if no contacts are available
    }
    else {
        cout << "Contacts:" << endl;  // Print a header for the contact list
        for (const auto& contact : contacts) {  // Iterate through the vector
            cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << endl;  // Print contact name and phone number
        }
    }
}

int main() {
    while (true) {  // Infinite loop for menu
        cout << "\nPhone Contact List" << endl;  // Print menu options
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice (1/2/3): ";  // Prompt user for choice
        cin >> choice;  // Read user choice

        switch (choice) {  // Switch based on user choice
        case 1:
            addContact();  // Call addContact function
            break;
        case 2:
            viewContacts();  // Call viewContacts function
            break;
        case 3:
            cout << "Exiting the program. Goodbye!" << endl;  // Print exit message
            return 0;  // Exit the program
        default:
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;  // Print error message
        }
    }

    return 0;  // Return 0 to indicate successful execution
}
