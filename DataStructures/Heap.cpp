/*
    Name: D-ary heap

    Time complexity: O(logN) per operation
    Space complexity: O(N)
*/

#include <vector>
#include <iostream>
#include <stdexcept>
#include <utility>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Heap {
    std::vector<T> keys;
    int degree;

public:
    Heap(int degree) {
        this->keys = std::vector<T>();
        this->degree = degree;
    }

    Heap(std::vector<T> &keys, int degree) {
        this->keys = std::vector<T>(keys);
        this->degree = degree;
        for (int i = ((int)keys.size() - 2) / degree; i >= 0; i--)
            fix_down(i);
    }

    bool is_empty() {
        return keys.size() == 0;
    }

    void clear() {
        keys.clear();
    }

    T *find_min() {
        if (is_empty())
            return nullptr;
        
        return &keys[0];
    }

    T *delete_min() {
        if (is_empty())
            return nullptr;

        T *ret = &keys[0];
        std::swap(keys[0], keys.back());
        keys.pop_back();
        
        if (!is_empty())
            // there is nothing to fix
            fix_down(0);
        return ret;
    }

    void insert(T val) {
        keys.emplace_back(val);
        fix_up((int)keys.size() - 1);
    }

    bool decrease_key(int x, T val) {
        if (x >= (int)keys.size() || keys[x] <= val)
            return false;
        
        keys[x] = val;
        fix_up(x);
        return true;
    }

private:
    int parent_index(int x) {
        return (x - 1) / degree;
    }

    int child_index(int x, int i) {
        return x * degree + i;
    }

    void fix_down(int x) {
        if (x >= (int)keys.size())
            throw std::runtime_error("Index is too large.");

        for (int i = 1; i <= degree; i++) {
            if (x * degree + i <= (int)keys.size()) {
                int child = child_index(x, i);
                if (keys[child] < keys[x]) {
                    std::swap(keys[child], keys[x]);
                    
                    if (child < (int)keys.size())
                        // checking if 'child' is a leaf
                        fix_down(child);
                    return;
                }
            }
        }
    }

    void fix_up(int x) {
        if (x >= (int)keys.size())
            throw std::runtime_error("Index is too large.");
        if (!x)
            // root
            return;

        int parent = parent_index(x);
        if (keys[x] < keys[parent]) {
            std::swap(keys[x], keys[parent]);

            if (parent)
                // checking if 'parent' is the root
                fix_up(parent);
        }
    }
};

int main() {
    Heap<int> *heap = new Heap<int>(2);
    heap->insert(5);
    heap->insert(2);
    heap->insert(4);
    heap->insert(3);
    heap->insert(6);

    int *min_key = heap->find_min();
    cout << *min_key << endl;

    heap->delete_min();
    
    min_key = heap->find_min();
    cout << *min_key << endl;

    return 0;
}
