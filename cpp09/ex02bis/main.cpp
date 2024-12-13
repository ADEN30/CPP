#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform binary search for the correct insertion position
int binarySearch(const std::vector<int>& sortedChain, int element) {
    int left = 0;
    int right = sortedChain.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedChain[mid] == element) {
            return mid;
        } else if (sortedChain[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left; // Return the position to insert
}

// Recursive function to sort using Ford-Johnson
std::vector<int> fordJohnsonRecursive(const std::vector<int>& input) {
    // Base case: if the input size is 1 or less, it's already sorted
    if (input.size() <= 1) return input;

    std::vector<int> mainChain;   // To store larger elements
    std::vector<int> pendingList; // To store smaller elements

    // Step 1: Split input into pairs and separate larger/smaller elements
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] > input[i + 1]) {
            mainChain.push_back(input[i]);
            pendingList.push_back(input[i + 1]);
        } else {
            mainChain.push_back(input[i + 1]);
            pendingList.push_back(input[i]);
        }
    }

    // If there's an odd number of elements, add the last one to the main chain
    if (input.size() % 2 != 0) {
        mainChain.push_back(input.back());
    }

    // Step 2: Recursively sort the main chain
    mainChain = fordJohnsonRecursive(mainChain);

    // Step 3: Recursively insert elements from the pending list
    for (size_t i = 0; i < pendingList.size(); ++i) {
        int position = binarySearch(mainChain, pendingList[i]);
        mainChain.insert(mainChain.begin() + position, pendingList[i]);
    }

    return mainChain; // Return the fully sorted list
}

// Main function to demonstrate the algorithm
int main() {
    // Example input
    std::vector<int> data;
    data.push_back(3);
    data.push_back(7);
    data.push_back(5);
    data.push_back(6);
    data.push_back(2);
    data.push_back(9);
    data.push_back(1);
    data.push_back(8);
    data.push_back(4);
    data.push_back(10);

    // Print the unsorted list
    std::cout << "Before sorting: ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Perform the Ford-Johnson sort
    std::vector<int> sortedData = fordJohnsonRecursive(data);

    // Print the sorted list
    std::cout << "After sorting: ";
    for (size_t i = 0; i < sortedData.size(); ++i) {
        std::cout << sortedData[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

