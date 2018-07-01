/*
    Algorithm: Knuth-Morris-Pratt
    Complexity: O(n + m) [where n is length of haystack and m length of needle]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> KMP(string &haystack, string &needle) {
    vector<int> matches;
    int n = haystack.length(), m = needle.length();
    int pref[m]; // prefix (failure) function
    
    for (int i = 0; i < m; i++) pref[i] = -1;
    for (int i = 0, j = -1; i < m; ) {
        while (j > -1 && needle[i] != needle[j]) j = pref[j];
        i++, j++;
        
        pref[i] = j;
    }

    for (int i = 0, j = 0; i < n; ) {
        while (j > -1 && haystack[i] != needle[j]) j = pref[j];
        i++, j++;

        if (j == m) {
            matches.push_back(i - m); // starting position
            j = pref[j];
        }
    }

    return matches;
}

int main() {
    string haystack = "abcabc";
    string needle = "bc";
    auto matches = KMP(haystack, needle);

    for (auto p: matches) cout << p << " "; // output should be 1 4
    cout << endl;

    return 0;
}
