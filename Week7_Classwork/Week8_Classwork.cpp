#include <iostream>  // Include input/output stream library

#include <string>    // Include string library for string manipulation

class Person {      // Define a class named Person
private:
    std::string name;  // Private member variable to store name
    int age;            // Private member variable to store age

public:
    // Getter for name
    std::string getName() const {  // Define a member function to get name
        return name;                // Return the name
    }

    // Setter for name
    void setName(const std::string& newName) {  // Define a member function to set name
        name = newName;                         // Set the name
    }

    // Getter for age
    int getAge() const {  // Define a member function to get age
        return age;       // Return the age
    }

    // Setter for age
    void setAge(int newAge) {  // Define a member function to set age
        age = newAge;           // Set the age
    }
};

int main() {  // Main function
    Person person;  // Create an instance of the Person class
    person.setName("Jit");  // Set the name of the person
    person.setAge(22);      // Set the age of the person

    std::cout << "Name: " << person.getName() << std::endl;  // Print the name of the person
    std::cout << "Age: " << person.getAge() << std::endl;    // Print the age of the person

    return 0;  // Return 0 to indicate successful execution
}
