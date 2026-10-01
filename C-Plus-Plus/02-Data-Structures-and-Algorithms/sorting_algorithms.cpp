/**
 * Fundamental Sorting Algorithms in Modern C++
 * Includes: Bubble Sort, Selection Sort, Insertion Sort using std::vector
 */

#include <iostream>
#include <vector>
#include <utility>

void printVector(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// 1. Selection Sort
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

// 2. Bubble Sort (Optimized)
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// 3. Insertion Sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> sample = {64, 34, 25, 12, 22, 11, 90};

    std::vector<int> a1 = sample;
    selectionSort(a1);
    printVector(a1, "Selection Sorted");

    std::vector<int> a2 = sample;
    bubbleSort(a2);
    printVector(a2, "Bubble Sorted   ");

    std::vector<int> a3 = sample;
    insertionSort(a3);
    printVector(a3, "Insertion Sorted");

    return 0;
}
