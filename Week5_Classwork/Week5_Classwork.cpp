#include <iostream> // Include the input-output stream library

using namespace std; // Use the standard namespace

struct Node { // Define a structure for a binary tree node
    int data; // Data stored in the node
    Node* left; // Pointer to the left child node
    Node* right; // Pointer to the right child node
};

Node* createNode(int data) { // Function to create a new node with the given data
    Node* newNode = new Node(); // Allocate memory for the new node
    newNode->data = data; // Set the data of the new node
    newNode->left = newNode->right = nullptr; // Initialize left and right pointers as null
    return newNode; // Return the newly created node
}

void printPreorder(Node* root) { // Function to perform preorder traversal of the tree
    if (root == nullptr) // If the root is null, return from the function
        return;
    cout << root->data << " "; // Print the data of the current node
    printPreorder(root->left); // Recursively traverse the left subtree
    printPreorder(root->right); // Recursively traverse the right subtree
}

int main() { // Main function where program execution starts
    Node* root = createNode(1); // Create the root node with data 1
    root->left = createNode(2); // Create the left child of the root with data 2
    root->right = createNode(3); // Create the right child of the root with data 3
    root->left->left = createNode(4); // Create the left child of the left child of the root with data 4

    cout << "Preorder traversal of the tree: "; // Print message indicating preorder traversal
    printPreorder(root); // Perform preorder traversal of the tree starting from the root
    cout << endl; // Print newline character

    // Remember to free the memory allocated for nodes
    delete root->left->left; // Delete the leftmost leaf node
    delete root->left; // Delete the left child of the root
    delete root->right; // Delete the right child of the root
    delete root; // Delete the root node

    return 0; // Indicate successful termination of the program
}

