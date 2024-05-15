// QuickSort.h
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>
#include <chrono>
#include <iostream>

class QuickSort {
private:
    static int partition(std::vector<std::string>& arr, int low, int high) {
        std::string pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            comparisons++;  // Increment comparison count
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    static void quickSort(std::vector<std::string>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

public:
    static int comparisons;

    static void sort(std::vector<std::string>& arr) {
        comparisons = 0;
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Quicksort took " << duration.count() << " microseconds and "
                  << comparisons << " comparisons." << std::endl;
    }
};

int QuickSort::comparisons = 0;

#endif // QUICKSORT_H
