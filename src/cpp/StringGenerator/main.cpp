#include "StringGenerator.h"
#include <iostream>
#include <fstream>  // Include for file I/O

int main() {
    StringGenerator generator;
    // Number of strings in each file
    const int num_strings = 30000;

    // Generate standard array of strings
    std::vector<std::string> standard_strings = generator.generate_array(num_strings);
    std::ofstream standard_file("data/standard_strings.txt");
    for (const auto& str : standard_strings) {
        standard_file << str << std::endl;
    }
    standard_file.close();

    // Generate reverse sorted array of strings
    std::vector<std::string> reverse_sorted_strings = generator.generate_reverse_sorted_array(num_strings);
    std::ofstream reverse_sorted_file("data/reverse_sorted_strings.txt");
    for (const auto& str : reverse_sorted_strings) {
        reverse_sorted_file << str << std::endl;
    }
    reverse_sorted_file.close();

    // Generate nearly sorted array of strings
    std::vector<std::string> nearly_sorted_strings = generator.generate_nearly_sorted_array(num_strings, 5); // Assume 5 swaps
    std::ofstream nearly_sorted_file("data/nearly_sorted_strings.txt");
    for (const auto& str : nearly_sorted_strings) {
        nearly_sorted_file << str << std::endl;
    }
    nearly_sorted_file.close();

    return 0;
}
