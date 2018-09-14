/*
	Algorithm: Interval (event) scheduling
	Complexity: O(n * logn) [where n is number of intervals]
	
* * *
Change IF in line 28 if bound overlap is permitted.
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r;

    Interval(int l = 0, int r = 0) {
        this -> l = l;
        this -> r = r;
    }
};

vector<Interval> interval_scheduling(vector<Interval> &v) {
    sort(v.begin(), v.end(), [](const Interval &a, const Interval &b) { return a.r < b.r; });
    
    int last = v[0].r;
    vector<Interval> ret = {v[0]}; // chosen intervals

    for (int i = 1; i < v.size(); i++) {
        if (v[i].l > last) {
            ret.push_back(v[i]);
            last = v[i].r;
        }
    }

    return ret;
}

int main() {

    return 0;
}
