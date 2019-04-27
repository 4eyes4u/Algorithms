/*
    Name: Z-algorithm and Z-matching

    Time complexity: O(N) for Z-algorithm and O(N + M) for Z-matching
    Space complexity: O(N) for Z-algorithm and O(N + M) for Z-matching

* * *
DUMMY is a single-char string that is not present in the input.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> z_algorithm(const std::string &s) {
    int n = s.length(), l = 0, d = 0;
    std::vector<int> z(n, 0);

    for (int i = 1; i < n; i++) {
        if (i <= d)
            z[i] = std::min(d - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > d) {
            l = i;
            d = i + z[i] - 1;
        }
    }

    return z;
}

std::vector<int> z_matching(const std::string &haystack,
                            const std::string &needle,
                            const std::string DUMMY = "#") {
    
    std::string aux = needle + DUMMY + haystack;
    std::vector<int> matches, z = z_algorithm(aux);
    for (int i = needle.size() + 1; i < aux.length(); i++)
        if (z[i] == needle.size())
            matches.emplace_back(i - needle.size() - 1);

    return matches;
}

int main() {
    std::string haystack = "ACBACDACBACBACDA";
    std::string needle = "ACBA";

    auto matches = z_matching(haystack, needle); // 0 6 9

    return 0;
}