#include <iostream>
#include <limits> // Required for INT_MAX (largest possible int value)

using namespace std;

int findSmallest(int arr[], int size) {
  // Check for an empty array. If it's empty, we have no smallest number.
  if (size <= 0) {
    cout << "Error: Array is empty or invalid size." << endl;
    return INT_MAX;  // Or some other error value, or throw an exception
  }

  int smallest = arr[0]; // Assume the first element is the smallest initially

  // Iterate through the rest of the array
  for (int i = 1; i < size; i++) {
    if (arr[i] < smallest) {
      smallest = arr[i]; // Update smallest if we find a smaller element
    }
  }

  return smallest;
}

int main() {
  int numbers[] = {5, 2, 8, 1, 9, -3, 4};
  int arraySize = sizeof(numbers) / sizeof(numbers[0]); // Calculate the size of the array

  int smallestNumber = findSmallest(numbers, arraySize);

  cout << "The smallest number in the array is: " << smallestNumber << endl;

  //Example with an empty array:
  int emptyArray[] = {};
  int emptySize = sizeof(emptyArray) / sizeof(emptyArray[0]);
  int smallestInEmpty = findSmallest(emptyArray, emptySize);
  if(smallestInEmpty == INT_MAX){
    cout << "As expected, we got an error message due to the empty array." << endl;
  }
  
  return 0;
}

s
