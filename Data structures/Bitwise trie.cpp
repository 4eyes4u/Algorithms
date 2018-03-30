/*
Data structure: Bitwise trie
Time complexity:
    Add number O(U) [where u is size of universe]
    Get O(u) [where u is size of universe U]
Memory complexity: O(n*u) [where n is number of added numbers and u is size of universe U]

* * *

Calculating maximum XOR for given number.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int U = 30;

int trie[N][2], k;

void add (int node, int x, int pw=u) {
    if (pw == -1) return;

    int b = (bool)(x & (1 << pw));
    if (!trie[node][b]) trie[node][b] = ++k;
    add(trie[node][b], x, pw - 1);
}

int get (int node, int x, int pw = U) {
    if (pw == -1) return 0;

    int b = (bool)(x & (1 << pw));
    if (trie[node][b ^ 1]) return (1 << pw) + get(trie[node][b ^ 1], x, pw - 1);
    else if (trie[node][b]) return get(trie[node][b], x, pw - 1);
    return 0;
}

int main() {
    add(0, 0);
    printf("%d\n", get (0, 7));

    return 0;
}
