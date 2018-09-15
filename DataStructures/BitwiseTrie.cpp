/*
    Name: Bitwise trie

    Time complexity: O(U) per operation
    Space complexity: O(N * U)

* * *
    Calculating maximum XOR for given number.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int U = 31;

int trie[N][2], k;

void add(int node, int x, int pw = U) {
    if (pw == -1)
        return;
    
    int bit = (x >> pw) & 1;
    if (!trie[node][bit])
        trie[node][bit] = ++k;

    add(trie[node][bit], x, pw - 1);
}

int get(int node, int x, int pw = U) {
    if (pw == -1)
        return 0;

    int bit = (x >> pw) & 1;
    if (trie[node][bit ^ 1])
        return (1 << pw) + get(trie[node][bit ^ 1], x, pw - 1);
    else if (trie[node][bit])
        return get(trie[node][bit], x, pw - 1);
    
    return 0;
}

int main() {
    add(0, 0);
    printf("%d\n", get(0, 7));

    return 0;
}
