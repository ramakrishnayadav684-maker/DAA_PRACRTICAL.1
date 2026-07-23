#include <iostream>
#include <vector>
#include <utility>

// Rearranges the array elements around a pivot element
int partition(std::vector<int>& arr, int low, int high) {
    // Select the rightmost element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element track
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            std::swap(arr[i], arr[j]);
        }
    }
    
    // Place the pivot in its correct sorted position
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursively breaks down and sorts the array partitions
void quickSort(std::vector<int>& arr, int low, int high) {
    // Base case: validation for valid sub-arrays
    if (low < high) {
        // Find the partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper utility to output vector contents to the terminal
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {8, 7, 2, 1, 0, 9, 6, -3, 5};
    
    std::cout << "Unsorted Array:\n";
    printArray(data);

    // Perform quicksort on the entire vector range
    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted Array:\n";
    printArray(data);

    return 0;
}
