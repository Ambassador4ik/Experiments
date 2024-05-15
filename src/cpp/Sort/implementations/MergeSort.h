#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <string>
#include <chrono>
#include <iostream>

class MergeSort {
private:
    static int charComparisons(const std::string& a, const std::string& b) {
        int i = 0;
        while (i < a.size() && i < b.size()) {
            comparisons++;
            if (a[i] < b[i]) return -1;
            if (a[i] > b[i]) return 1;
            i++;
        }
        comparisons++; // Last comparison when one string ends
        if (a.size() < b.size()) return -1;
        if (a.size() > b.size()) return 1;
        return 0;
    }

    static void merge(std::vector<std::string>& arr, int l, int m, int r) {
        std::vector<std::string> left(arr.begin() + l, arr.begin() + m + 1);
        std::vector<std::string> right(arr.begin() + m + 1, arr.begin() + r + 1);

        int i = 0, j = 0, k = l;
        while (i < left.size() && j < right.size()) {
            if (charComparisons(left[i], right[j]) <= 0) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.size()) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < right.size()) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    static void mergeSort(std::vector<std::string>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

public:
    static int comparisons;

    static void sort(std::vector<std::string>& arr) {
        comparisons = 0;
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Mergesort took " << duration.count() << " microseconds and "
                  << comparisons << " character comparisons." << std::endl;
    }
};

int MergeSort::comparisons = 0;

#endif // MERGESORT_H
