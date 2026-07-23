#include <iostream>
#include <vector>
#include <utility> // For std::swap

// Function to perform an optimized bubble sort on a vector
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    
    // Outer loop for the number of passes
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        
        // Inner loop to compare adjacent elements
        // The last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

// Helper function to print the vector elements
void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    printVector(data);
    
    bubbleSort(data);
    
    std::cout << "Sorted array:   ";
    printVector(data);
    
    return 0;
}
