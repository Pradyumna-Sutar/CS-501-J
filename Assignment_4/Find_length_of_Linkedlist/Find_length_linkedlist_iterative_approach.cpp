/*
Initialize: Set a counter variable length to 0 and a pointer current to the head of the list.
Traverse: While current is not null (meaning there are more nodes):
Increment the length counter.
Move current to the next node using current = current->next.
Return: Once the loop ends (current becomes null), return the length as it represents the total number of nodes traversed.
*/

#include <iostream> // Include header for input/output operations

// Define the Node structure for linked list elements
struct Node {
  int data;     // Holds the data value of the node
  Node* next;  // Pointer to the next node in the list
};

// Function to find the length of a linked list iteratively
int iterativeLength(Node* head) {
  int length = 0; // Initialize counter variable for length
  Node* current = head; // Start from the head of the list

  // Loop until we reach the end (null)
  while (current != nullptr) {
    length++; // Increment counter for each node visited
    current = current->next; // Move to the next node
  }

  return length; // Return the total length of the list
}

int main() {
  // Create a sample linked list (replace with your data)
  Node* head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};

  // Find the length of the list
  int listLength = iterativeLength(head);
  std::cout << "Length of the list: " << listLength << std::endl;

  // Memory deallocation (important!)
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }

  return 0;
}


/*
Include header: #include <iostream>: Includes the header file for input/output operations like using std::cout.
Node structure: Defines a Node structure with two members: data to store the node's value and next to point to the next node in the list.
iterativeLength function:
Initialization:
int length = 0;: Creates an integer variable length and initializes it to 0, as we start with no nodes counted.
Node* current = head;: Sets a pointer current to the head of the list to begin traversing.
Loop:
while (current != nullptr): This loop continues as long as current is not null, meaning there are more nodes to visit.
length++;: Increments the length counter for each node visited.
current = current->next;: Moves the current pointer to the next node in the list.
Return:
return length;: After the loop finishes (reaching the end of the list), the length variable holds the total count of nodes, which is returned.
main function:
Sample linked list:
Node* head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};: Creates a sample linked list with nodes containing values 1, 2, 3, and 4.
Calculate length:
int listLength = iterativeLength(head);: Calls the iterativeLength function with the head pointer to calculate the length and stores it in listLength.
std::cout << "Length of the list: " << listLength << std::endl;: Prints the length of the list to the console.
Memory deallocation:
Node* current = head;: Sets current back to the head to start deallocating.
while (current != nullptr): Similar loop as before, but for deallocating memory.
Node* next = current->next;: Stores the address of the next node before deleting the current one.
delete current;: Deallocates the memory of the current node.
current = next;: Moves current to the next node (previously stored in next) to repeat the deallocation process.
Return:
return 0;: Returns 0 to indicate successful program execution.
*/
