/*
    Name: Monotone queue

    Time complexity: O(1) amortized per operation
    Space complexity: O(N)

* * *
    RMQ operation is minimum.
*/

#include <bits/stdc++.h>
using namespace std;

dequeue<int> dq;

void add(int x) {
    while (!dq.empty() && dq.back() > x)
        dq.pop_back();
  
  dq.push_back(x);
}

int get_min() {
    if (!dq.empty())
        return dq.front();
    return -1;
}

int main() {
    return 0;
}
