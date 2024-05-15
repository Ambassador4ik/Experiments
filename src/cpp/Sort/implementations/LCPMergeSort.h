#ifndef LCPMERGESORT_H
#define LCPMERGESORT_H

#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <utility> // For std::pair

class LCPMergeSort {
private:
    static int lcp(const std::string& a, const std::string& b, int known_lcp) {
        int l = known_lcp;
        while (l < a.size() && l < b.size() && a[l] == b[l]) {
            ++l;
            ++comparisons; // Count each character comparison
        }
        if (l < a.size() && l < b.size()) ++comparisons; // Count the final mismatched comparison
        return l;
    }

    static std::pair<char, int> lcpCompare(const std::string& a, const std::string& b, int known_lcp) {
        int l = lcp(a, b, known_lcp);
        if (l == a.size() && l == b.size()) return {'=', l};
        if (l == a.size() || (l < b.size() && a[l] < b[l])) return {'<', l};
        return {'>', l};
    }

    static std::vector<std::pair<std::string, int>> stringMerge(
        std::vector<std::pair<std::string, int>>& P,
        std::vector<std::pair<std::string, int>>& Q) {

        std::vector<std::pair<std::string, int>> R;
        size_t i = 0, j = 0;
        while (i < P.size() && j < Q.size()) {
            if (P[i].second > Q[j].second) {
                R.push_back(P[i++]);
            } else if (P[i].second < Q[j].second) {
                R.push_back(Q[j++]);
            } else {
                auto [comp, lcp_length] = lcpCompare(P[i].first, Q[j].first, P[i].second);
                if (comp == '<') {
                    R.push_back(P[i]);
                    ++i;
                    if (j < Q.size()) Q[j].second = lcp_length;
                } else {
                    R.push_back(Q[j]);
                    ++j;
                    if (i < P.size()) P[i].second = lcp_length;
                }
            }
        }
        while (i < P.size()) R.push_back(P[i++]);
        while (j < Q.size()) R.push_back(Q[j++]);
        return R;
    }

    static std::vector<std::pair<std::string, int>> stringMergeSort(const std::vector<std::string>& strings) {
        if (strings.size() == 1) return {{strings[0], 0}};

        size_t mid = strings.size() / 2;
        std::vector<std::string> left(strings.begin(), strings.begin() + mid);
        std::vector<std::string> right(strings.begin() + mid, strings.end());

        std::vector<std::pair<std::string, int>> sortedLeft = stringMergeSort(left);
        std::vector<std::pair<std::string, int>> sortedRight = stringMergeSort(right);

        return stringMerge(sortedLeft, sortedRight);
    }

    static void stringMergeSort(std::vector<std::string>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            std::vector<std::string> leftVec(arr.begin() + left, arr.begin() + mid + 1);
            std::vector<std::string> rightVec(arr.begin() + mid + 1, arr.begin() + right + 1);

            auto sortedLeft = stringMergeSort(leftVec);
            auto sortedRight = stringMergeSort(rightVec);

            auto merged = stringMerge(sortedLeft, sortedRight);
            for (int i = left; i <= right; ++i) {
                arr[i] = merged[i - left].first;
            }
        }
    }

public:
    static int comparisons;

    static void sort(std::vector<std::string>& arr) {
        comparisons = 0;
        auto start = std::chrono::high_resolution_clock::now();
        stringMergeSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Mergesort with LCP took " << duration.count() << " microseconds and "
                  << comparisons << " comparisons." << std::endl;
    }
};

int LCPMergeSort::comparisons = 0;

#endif // LCPMERGESORT_H
