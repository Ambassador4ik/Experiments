#include "implementations/QuickSort.h"
#include "implementations/MergeSort.h"
#include "implementations/LCPMergeSort.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> data;
    std::ifstream file("../StringGenerator/data/reverse_sorted_strings.txt"); // Open the file containing the data
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1; // Return with error code
    }

    std::string line;
    while (std::getline(file, line)) { // Read each line from the file
        if (!line.empty()) { // Ensure the line is not empty
            data.push_back(line);
        }
    }

    file.close(); // Close the file

    QuickSort::sort(data); // Sort using QuickSort
    MergeSort::sort(data); // Sort using MergeSort
    LCPMergeSort::sort(data); // Sort using LCPMergeSort

    return 0;
}
