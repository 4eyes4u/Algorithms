/*
    Name: Suffix array & LCP array

    Time complexity: O(N * log^2(N))
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
char s[N];
int sa[N], lcp[N], pos[N], tmp[N];
int n, t;

bool suffix_compare(int i, int j) {
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    
    i += t, j += t;
    if (i < n && j < n)
        return pos[i] < pos[j];
    return i > j;
}

void init_sa() {
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }

    for (t = 1; t <= 2 * n; t *= 2) {
        sort(sa, sa + n, suffix_compare);

        for (int i = 0; i < n - 1; i++) {
            tmp[i + 1] = tmp[i];
            if (suffix_compare(sa[i], sa[i + 1]))
                tmp[i + 1]++;
        }

        for (int i = 0; i < n; i++)
            pos[sa[i]] = tmp[i];
        
        if (tmp[n - 1] == n - 1)
            break;
    }
}

void init_lcp() {
    for (int i = 0, k = 0; i < n; i++) {
        if (pos[i] != n - 1) {
            int j = sa[pos[i] + 1];
            
            while (s[i + k] == s[j + k])
                k++;

            lcp[pos[i]] = k;
            if (k) k--;
        }
    }
}

int main() {
    strcpy(s, "banana");
    n = strlen(s);
    init_sa();
    init_lcp();

    for (int i = 0; i < n; i++)
        printf("%d ", sa[i]);
    puts("");

    return 0;
}
