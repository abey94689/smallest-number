#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Base case: target not found
    }
    int mid = left + (right - left) / 2; // Prevents overflow
    if (arr[mid] == target) {
        return mid; // Base case: target found
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right); // Search right half
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1); // Search left half
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    int result = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    cout << "Element found at index: " << result << endl;
    return 0;
}

