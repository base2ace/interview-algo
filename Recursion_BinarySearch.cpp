#include <iostream>
#include <vector>

// Recursive binary search function
int binarySearchRecursive(const std::vector<int>& arr, int target, int left, int right) {
    // Base case: when the search range is empty, the target is not found
    if (left > right) {
        return -1;
    }

    // Calculate the middle index
    int mid = left + (right - left) / 2;

    // Base case: when the middle element is the target
    if (arr[mid] == target) {
        return mid;
    }

    // If the target is less than the middle element, search the left half
    if (target < arr[mid]) {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
    // If the target is greater than the middle element, search the right half
    else {
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
}

int main() {
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;

    // Perform binary search on the sorted array
    int index = binarySearchRecursive(sortedArray, target, 0, sortedArray.size() - 1);

    if (index != -1) {
        std::cout << "Element " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }

    return 0;
}
