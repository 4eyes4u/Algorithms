/*
  Data structure: D-ary heap
  Time complexity: O(logn) per operaton [where n is number of nodes]
  Memory complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

class dHeap {
private:
    vector<int> keys;
    int d, n;
    
    int parent(int x) { return (x - 1) / d; }
    
    int child(int x, int i) { return d * x + i; }
    
    void fix_down(int x) {
        for (int i = 1; i <= d; i++) {
            if (x * d + i > n) break;
            
            if (keys[child(x, i)] < keys[x]) {
                swap(keys[child(x, i)], keys[x]);
                fix_down(child(x, i));
                return;
            }
        }
    }
    
    void fix_up(int x) {
        if (keys[x] < keys[parent(x)]) {
            swap(keys[x], keys[parent(x)]);
            fix_up(parent(x));
        }
    }
    
public:
	bool is_empty() { return n == 0; }

    void clear() {
        keys.clear();
        n = 0;
    }
    
    void init(int *a, int sz) {
        n = sz;
        keys.resize(n);
        for (int i = 0; i < n; i++) keys[i] = a[i];
        for (int i = (n - 2) / d; i >= 0; i--) fix_down(i);
    }
    
    int find_min() {
        if (is_empty()) return inf;
        return keys[0];
    }
    
    void insert_node(int val) {
        keys.push_back(val);
        n++;
        fix_up(n);
    }
    
    void delete_min() {
        if (is_empty()) return;
        
        n--;
        swap(keys[0], keys[n]);
        keys.pop_back();
        fix_down(0);
    }
    
    void decrease_key(int x, int val) {
        if (x >= n) return;
        keys[x] = val;
        fix_up(x);
    }
    
    void delete_node(int x) {
        if (is_empty()) return;
        decrease_key(x, -inf);
        delete_min();
    }
};

int main() {
    return 0;
}
