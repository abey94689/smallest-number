#include <iostream>
using namespace std;

void pointerSelectionSort(int* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int* minPtr = arr[i];        // Pointer to the current minimum element
        int minIndex = i;            // Index of the current minimum element
        
        for (int j = i + 1; j < n; j++) {
            if (*arr[j] < *minPtr) { // Compare the value pointed by arr[j] with minPtr
                minPtr = arr[j];     // Update minPtr to point to the new minimum element
                minIndex = j;        // Update the index of the new minimum element
            }
        }
        
        // Swap the values at arr[i] and arr[minIndex]
        swap(*arr[i], *arr[minIndex]); // Dereference pointers to swap the actual values
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Create an array of pointers
    int* ptrArr[n];
    for (int i = 0; i < n; i++) {
        ptrArr[i] = &arr[i];  // Point each element of ptrArr to the corresponding element in arr
    }

    // Call pointerSelectionSort
    pointerSelectionSort(ptrArr, n);
    
    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << *ptrArr[i] << " ";  // Dereference the pointer to print the value
    }
    return 0;
}