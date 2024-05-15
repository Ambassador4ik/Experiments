#include "StringGenerator.h"

StringGenerator::StringGenerator()
    : gen(rd()), dist_length(10, 200), dist_char(0, alphabet.size() - 1) {}

std::string StringGenerator::generate() {
    int length = dist_length(gen);
    std::string result;
    result.reserve(length);  // Reserve memory for efficiency
    for (int i = 0; i < length; ++i) {
        result += alphabet[dist_char(gen)];
    }
    return result;
}

std::vector<std::string> StringGenerator::generate_array(int n) {
    std::vector<std::string> array;
    array.reserve(n);  // Reserve memory for efficiency
    for (int i = 0; i < n; ++i) {
        array.push_back(generate());
    }
    return array;
}

std::vector<std::string> StringGenerator::generate_reverse_sorted_array(int n) {
    std::vector<std::string> array = generate_array(n);
    std::sort(array.begin(), array.end(), std::greater<std::string>());
    return array;
}

std::vector<std::string> StringGenerator::generate_nearly_sorted_array(int n, int swap_count) {
    std::vector<std::string> array = generate_reverse_sorted_array(n);
    // Apply a small number of random swaps to simulate near-sorting
    for (int i = 0; i < swap_count; ++i) {
        int idx1 = dist_char(gen) % n;
        int idx2 = dist_char(gen) % n;
        std::swap(array[idx1], array[idx2]);
    }
    return array;
}