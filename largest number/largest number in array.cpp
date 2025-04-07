#include <iostream>
#include <vector>
#include <limits.h>

int findKthLargest(const std::vector<int>& nums, int k) {
    if (nums.size() < k) {
        std::cerr << "Array does not have enough elements." << std::endl;
        return INT_MIN;
    }

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int num : nums) {
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second && num < first) {
            third = second;
            second = num;
        } else if (num > third && num < second) {
            third = num;
        }
    }

    if (k == 2) {
        return second;
    } else if (k == 3) {
        return third;
    } else {
        std::cerr << "Invalid value for k. Only 2 or 3 are allowed." << std::endl;
        return INT_MIN;
    }
}

int main() {
    std::vector<int> nums = {10, 5, 20, 15, 25};
    int k = 2; // Change to 3 for third largest

    int result = findKthLargest(nums, k);
    if (result != INT_MIN) {
        std::cout << "The " << k << "rd largest element is " << result << std::endl;
    }

    return 0;
}
