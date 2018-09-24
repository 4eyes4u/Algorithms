/*
    Name: Mo's algorithm
    
    Time complexity: O((Q + N) * qrt(N)) for offline processing
    Space complexity: O(N)

* * *
    Calculating sum on interval.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int Q = 1e5 + 10;
const int BLOCK_SIZE = 320;
const int BLOCKS = ceil(N / BLOCK_SIZE);

struct Query {
    int l, r, idx;

    Query(int l, int r, int idx) {
        this->l = l;
        this->r = r;
        this->idx = idx;
    }

    bool operator < (const Query &other) const {
        return r < other.r;
    }
};

vector<Query> mo[BLOCKS];
int a[N];
long long sol[Q];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    int q;
    scanf("%d", &q);
    for (int i = 0, l, r; i < q; i++) {
        scanf("%d%d", &l, &r);
        mo[l / BLOCKS].emplace_back(l, r, i);
    }

    for (int i = 0; i < BLOCKS; i++)
        sort(mo[i].begin(), mo[i].end());
    
    for (int i = 0; i < BLOCKS; i++) {
        if (mo[i].size()) {
            int l = mo[i][0].l, r = l - 1;
            long long sum = 0;

            for (auto query : mo[i]) {
                while (r < query.r)
                    sum += a[++r];
                while (l < query.l)
                    sum -= a[l++];
                while (l > query.l)
                    sum += a[--l];
                
                sol[query.idx] = sum;
            }
        }
    }

    for (int i = 0; i < q; i++)
        printf("%lld ", sol[i]);
    puts("");

    return 0;
}