/*
    Name: Interval (event) scheduling

	Time complexity: O(N * logN)
    Space complexity: O(N)
	
* * *
    Change IF in line 30 if bound overlap is permitted.
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r;
};

vector<Interval> v;

void interval_scheduling(vector<Interval> &chosen) {
    sort(v.begin(), v.end(), [](const Interval &a, const Interval &b) {
                                    return a.r < b.r;});
    
    int last = v[0].r;
    chosen = {v[0]};

    for (int i = 1; i < v.size(); i++) {
        if (v[i].l > last) {
            chosen.emplace_back(v[i]);
            last = v[i].r;
        }
    }
}

int main() {
    return 0;
}
