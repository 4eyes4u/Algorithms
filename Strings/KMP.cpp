/*
    Name: Knuth-Morris-Pratt (KMP)

    Time complexity: O(N + M)
    Space complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

char haystack[N], needle[M];
int pref[M];

void KMP(int n, int m, vector<int> &matches) {
    matches = {};

    fill(pref, pref + m, -1);
    for (int i = 0, j = -1; i < m; ) {
        while (j > -1 && needle[i] != needle[j])
            j = pref[j];

        i++, j++;
        pref[i] = j;
    }

    for (int i = 0, j = 0; i < n; ) {
        while (j > -1 && haystack[i] != needle[j])
            j = pref[j];
        
        i++, j++;
        if (j == m) {
            matches.emplace_back(i - m);
            j = pref[j];
        }
    }
}

int main() {
    strcpy(haystack, "abcabc");
    int n = strlen(haystack);
    strcpy(needle, "bc");
    int m = strlen(needle);

    // matches should be {1, 4}
    vector<int> matches;
    KMP(n, m, matches);
    for (auto match : matches)
        printf("%d\n", match);

    return 0;
}
