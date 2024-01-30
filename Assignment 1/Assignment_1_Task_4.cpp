/* Optimization ChallengeChallenge yourself to optimize the bubble sort algorithm. Provided with thepartially sorted array ` [1, 2, 3, 4, 5, 10, 9, 8, 7, 6] `. Optimize the algorithm toreduce the number of comparisons or swaps, making the sorting process moreefficient. */

#include <iostream>

using namespace std;

// Function to perform optimized Bubble Sort on an array
void optimizedBubbleSort(int array[], int size) {
    bool swapped;  // Flag to track if any swaps were made

    // Outer loop: Iterate through each element of the array
    for (int i = 0; i < size - 1; i++) {
        swapped = false;  // Initialize the flag for each pass

        // Inner loop: Compare and swap elements to bubble up the largest element to its correct position
        for (int j = 0; j < size - i - 1; j++) {
            // Compare adjacent elements and swap if they're in the wrong order
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);  // Swap elements
                swapped = true;  // Set the flag to true
            }
        }

        // If no swaps were made in a pass, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int inputArray[] = {9, 3, 5, 2, 6, 1, 5, 10, 27, 13};
    int arraySize = sizeof(inputArray) / sizeof(inputArray[0]);

    // Display the unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << inputArray[i] << " ";
    }
    cout << endl;

    // Perform optimized Bubble Sort
    optimizedBubbleSort(inputArray, arraySize);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << inputArray[i] << " ";
    }
    cout << endl;

    return 0;
}
