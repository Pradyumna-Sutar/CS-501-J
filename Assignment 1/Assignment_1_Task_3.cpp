/*Intermediate: Code ImplementationImplement the bubble sort algorithm in C++. Provide them with the followingunsorted array: ` [3, 6, 1, 8, 2] `. Code from scratch and test it to ensure it workscorrectly.*/

#include <iostream>

using namespace std;
//.//.
// Function to perform the Bubble Sort algorithm on an array
void bubbleSort(int array[], int size) {
    // Outer loop: Iterate through each element of the array
    for (int i = 0; i < size - 1; i++) {
        // Inner loop: Compare and swap elements to bubble up the largest element to its correct position
        for (int j = 0; j < size - i - 1; j++) {
            // Compare adjacent elements and swap if they're in the wrong order
            if (array[j] > array[j + 1]) {
                // Swap elements to correct their order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// The main function where the program begins execution
int main() {
    // Initialize an array with unsorted values
    int unsortedArray[] = { 9, 3, 5, 2, 6, 1 };
    // Calculate the size of the array
    int arraySize = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

    // Display the unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << unsortedArray[i] << " ";
    }
    cout << endl;

    // Call the bubbleSort function to sort the array
    bubbleSort(unsortedArray, arraySize);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << unsortedArray[i] << " ";
    }
    cout << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}
