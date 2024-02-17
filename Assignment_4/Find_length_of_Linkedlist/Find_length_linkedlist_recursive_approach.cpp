/*
The recursive approach works by breaking down the problem of finding the length of the entire list into finding the length of a smaller sub-list. Here's the logic:

Base case: If the current node is null (end of the list), the length is 0. Return 0.
Recursive call: Otherwise, make a recursive call to find the length of the rest of the list starting from the next node.
Add 1: Add 1 to the result of the recursive call, as it represents the length of the rest of the list, and the current node itself contributes 1 to the total length.
Return: Return the sum (1 + length of rest of the list).
Termination conditions:

The recursion terminates when the base case is reached, meaning the current node is null.
*/

#include <iostream> // Include header for input/output operations

// Define the Node structure for linked list elements
struct Node {
  int data;     // Holds the data value of the node
  Node* next;  // Pointer to the next node in the list
};

// Function to find the length of a linked list recursively
int recursiveLength(Node* head) {
  if (head == nullptr) { // Base case: empty list (null), length is 0
    return 0;
  } else {
    // Recursive call: find length of rest of the list + 1 for current node
    return 1 + recursiveLength(head->next);
  }
}

int main() {
  // Create a sample linked list (replace with your data)
  Node* head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};

  // Find the length of the list
  int listLength = recursiveLength(head);
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

/*Explaination:

#include <iostream>: Includes the header for input/output operations.
Node structure: Defines the Node structure with data and next members.
recursiveLength function:
if (head == nullptr): Base case: if the current node is null (end of list), its length is 0, so return 0.
else: Recursive case:
return 1 + recursiveLength(head->next): Make a recursive call to find the length of the rest of the list (starting from the next node) and add 1 to it as we also have the current node.
main function:
Sample linked list: Creates a sample list with nodes containing values 1, 2, 3, and 4.
Calculate length: Calls the recursiveLength function with the head pointer to find the length and stores it in listLength.
Print length: Prints the length to the console.
Memory deallocation: Similar to the iterative approach, deallocates memory used by the linked list to avoid leaks.
*/