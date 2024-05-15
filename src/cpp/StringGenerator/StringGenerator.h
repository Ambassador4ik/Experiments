#ifndef STRING_GENERATOR_H
#define STRING_GENERATOR_H

#include <string>
#include <vector>
#include <random>
#include <algorithm>

class StringGenerator {
private:
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@%:;^&*()-";
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dist_length;
    std::uniform_int_distribution<> dist_char;

public:
    StringGenerator();
    std::string generate();
    std::vector<std::string> generate_array(int n);
    std::vector<std::string> generate_reverse_sorted_array(int n);
    std::vector<std::string> generate_nearly_sorted_array(int n, int swap_count);
};

#endif // STRING_GENERATOR_H
