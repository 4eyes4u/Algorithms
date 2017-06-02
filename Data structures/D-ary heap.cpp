/*
Data structure: D-ary heap
Complexities:
    Insert O(log_d(n)) worst case
    Find Minimum O(1) worst case
    Delete Minimum O(d*log_d(n)) worst case
    Delete O(d*log_d(n)) worst case
    Decrease Key (log_d(n)) worst cast

    [where n is number of nodes]
*/

#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

class dHeap
{
private:
    vector<int> keys;
    int d, n;
    int parent(int x)
    {
        return (x-1)/d;
    }
    int child(int x, int i)
    {
        return d*x+i;
    }
    void fixDown(int x)
    {
        for (int i=1;i<=d;i++)
        {
            if (x*d+i>n) break;
            if (keys[x*d+i]<keys[x])
            {
                swap(keys[x*d+i], keys[x]);
                fixDown(x*d+i);
                return;
            }
        }
    }
    void fixUp(int x)
    {
        if (keys[x]<keys[parent(x)])
        {
            swap (keys[x], keys[parent(x)]);
            fixUp(parent(x));
        }
    }
public:
    bool isEmpty()
    {
        return n==0;
    }
    void clear()
    {
        keys.clear();
        n=0;
    }
    void init(int *a, int sz)
    {
        n=sz;
        keys.resize(n);
        for (int i=0;i<n;i++) keys[i]=a[i];
        for (int i=(int)((n-2)/d);i>=0;i--) fixDown(i);
    }
    int findMin()
    {
        if (isEmpty()) return inf;
        return keys[0];
    }
    void insertNode(int val)
    {
        keys.push_back(val);
        n++;
        fixUp(n);
    }
    void deleteMin()
    {
        if (isEmpty()) return;
        swap(keys[0], keys[n-1]);
        keys.pop_back();
        n--;
        fixDown(0);
    }
    void decreaseKey(int x, int val)
    {
        if (x>=n) return;
        keys[x]=val;
        fixUp(x);
    }
    void deleteNode(int x)
    {
        if (isEmpty()) return;
        decreaseKey(x, -inf);
        deleteMin();
    }
};

int main()
{
    return 0;
}
