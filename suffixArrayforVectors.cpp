#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! complexity is nlogn

// Comparator function for comparing suffixes based on lexicographical order
bool compareSuffix(const vector<int>& vec, int i, int j, int offset) {
    while (i < vec.size() && j < vec.size()) {
        if (vec[i] != vec[j]) {
            return vec[i] < vec[j];
        }
        i++;
        j++;
    }
    return i == vec.size() || (j < vec.size() && vec[i + offset] < vec[j + offset]);
}

// Function to build suffix array for a vector of integers
vector<int> buildSuffixArray(const vector<int>& vec) {
    int n = vec.size();
    vector<int> suffixArray(n);

    // Initialize suffixArray with indices 0 to n-1
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
    }

    // Sort suffixArray based on lexicographical order of suffixes
    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        rank[i] = vec[i];
    }

    for (int offset = 1; offset < n; offset *= 2) {
        sort(suffixArray.begin(), suffixArray.end(), [&](int i, int j) {
            return compareSuffix(vec, i, j, offset);
        });

        vector<int> newRank(n);
        newRank[suffixArray[0]] = 0;
        for (int i = 1; i < n; i++) {
            newRank[suffixArray[i]] = newRank[suffixArray[i - 1]] +
                                       (compareSuffix(vec, suffixArray[i - 1], suffixArray[i], offset) ? 1 : 0);
        }
        rank = newRank;
    }

    return suffixArray;
}

// Function to compute the Longest Common Prefix (LCP) array from the suffix array
vector<int> computeLCP(const vector<int>& vec, const vector<int>& suffixArray) {
    int n = vec.size();
    vector<int> lcp(n);
    vector<int> rank(n);

    // Compute rank array from suffix array
    for (int i = 0; i < n; i++) {
        rank[suffixArray[i]] = i;
    }

    int len = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffixArray[rank[i] - 1];
            while (i + len < n && j + len < n && vec[i + len] == vec[j + len]) {
                len++;
            }
            lcp[rank[i]] = len;
            if (len > 0) {
                len--;
            }
        }
    }

    return lcp;
}

int main() {
    vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    
    // Build suffix array for the vector
    vector<int> suffixArray = buildSuffixArray(vec);

    // Compute LCP array using the suffix array
    vector<int> lcpArray = computeLCP(vec, suffixArray);

    // Output the suffix array
    cout << "Suffix Array:";
    for (int idx : suffixArray) {
        cout << " " << idx;
    }
    cout << endl;

    // Output the LCP array
    cout << "LCP Array:";
    for (int len : lcpArray) {
        cout << " " << len;
    }
    cout << endl;

    return 0;
}
