/* Justification:
Using Binary Trees for Biological Species Taxonomy:

Hierarchical Representation: Biological taxonomy naturally follows a hierarchical structure, organizing species into genera, families, orders, and more. A binary tree naturally represents this hierarchy, where each node corresponds to a taxon (e.g., species, genus), and edges denote parent-child relationships.
Efficient Search and Retrieval: Binary trees enable efficient searches within the taxonomic hierarchy. Whether searching for specific taxa or traversing through levels, binary trees offer logarithmic time complexity ( � ( log ⁡ � ) O(logn)), thanks to their balanced structure.
Ordered Organization: Binary trees inherently maintain order. This property is valuable for organizing taxa alphabetically or based on evolutionary relationships. In taxonomy, ordered lists of taxa are common.
Space Efficiency: Binary trees use minimal memory. They store only pointers to parent and child nodes, making them memory-efficient even with large taxonomic datasets.
Flexibility in Modification: Binary trees allow easy insertion, deletion, and restructuring of taxa. New taxa can be added as children to existing nodes, preserving the hierarchy. Outdated or incorrect taxa can be removed without disrupting the overall taxonomy.
Representing Evolutionary Relationships: Binary trees visually depict evolutionary connections. By representing taxa as nodes and parent-child relationships as evolutionary links, binary trees provide an intuitive view of phylogenetic relationships.

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a taxon (node in the tree)
struct Taxon {
    string name;
    Taxon* parent;  // Pointer to the parent taxon
    Taxon* leftChild;  // Pointer to the left child taxon (subtaxon)
    Taxon* rightChild;  // Pointer to the right child taxon (subtaxon)
};

// Function to create a new taxon
Taxon* createTaxon(const string& name) {
    Taxon* newTaxon = new Taxon;
    newTaxon->name = name;
    newTaxon->parent = nullptr;
    newTaxon->leftChild = nullptr;
    newTaxon->rightChild = nullptr;
    return newTaxon;
}

// Function to add a child taxon to a parent taxon
void addChild(Taxon* parent, Taxon* child) {
    if (parent->leftChild == nullptr) {
        parent->leftChild = child;
        child->parent = parent;
    }
    else {
        parent->rightChild = child;
        child->parent = parent;
    }
}

// Function to print the taxonomic hierarchy
void printHierarchy(Taxon* taxon, int level = 0) {
    if (taxon == nullptr) {
        return;
    }
    for (int i = 0; i < level; ++i) {
        cout << "  ";  // Indentation for hierarchy levels
    }
    cout << taxon->name << endl;  // Print the taxon name
    printHierarchy(taxon->leftChild, level + 1);  // Recursively print left child
    printHierarchy(taxon->rightChild, level + 1);  // Recursively print right child
}

int main() {
    cout << "Welcome to the Genealogy Information Program!" << endl;

    // Create the root taxon (e.g., domain)
    Taxon* root = createTaxon("Life");

    int numSpecies;
    cout << "Enter the number of species: ";
    cin >> numSpecies;  // Read the number of species from user input

    // Example: Add species dynamically
    for (int i = 0; i < numSpecies; ++i) {
        string speciesName;
        cout << "Enter species name " << i + 1 << ": ";
        cin >> speciesName;  // Read species name from user input
        Taxon* species = createTaxon(speciesName);
        addChild(root, species);  // Add species as a child to the root
    }

    // Print the taxonomic hierarchy
    cout << "\nTaxonomic Hierarchy:" << endl;
    printHierarchy(root);

    // Clean up memory (optional)
    // ...

    return 0;
}
