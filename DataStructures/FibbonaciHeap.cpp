/*
    Name: Fibonacci Heap

    Time complexity: O(logN) amortized per operation
    Space complexity: O(N)

* * *
    Useless in practice.
*/
 
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    Node* first_child;
    int key, degree;
    bool marked;

    explicit Node(int key) {
        this->key = key;
        this->degree = 0;
        this->parent = this->first_child = NULL;
        this->left = this->right = this;
        this->marked = false;
    }
};
 
class FibonacciHeap {
public:
    FibonacciHeap();
    Node* FindMin();
    void DeleteMin();
    void Insert(Node* curr);
    void DecreaseKey(Node* curr, int new_key);
    void Merge(FibonacciHeap* h);
    int GetSize();

private:
    void LinkRootNodes(Node* top, Node* bottom);
    void MakeRootNode(Node* curr);
    Node* min_node;
    int size;
};
 
FibonacciHeap::FibonacciHeap() {
    size = 0;
    min_node = NULL;
}
 
Node* FibonacciHeap::FindMin() {
    return min_node;
}
 
void FibonacciHeap::DeleteMin() {
    if (size == 0) return;
    if (size == 1) {
        delete min_node;
        min_node = NULL;
        size = 0;
        return;
    }
    Node* child = min_node->first_child;
    int deg = min_node->degree;
    for (int i = 0; i < deg; i++) {
        Node* next = child->right;
        MakeRootNode(child);
        child = next;
    }
    int D = 2 * ceil(log2(size));
    Node* tmp[D];
    for (int i = 0; i < D; i++)
        tmp[i] = NULL;
    Node* curr = min_node->right;
    while (curr != min_node) {
        Node* next = curr->right;
        int deg = curr->degree;
        while (tmp[deg] != NULL) {
            Node* other = tmp[deg];
            if (curr->key > other->key)
                swap(curr, other);
            LinkRootNodes(curr, other);
            tmp[deg++] = NULL;
        }
        tmp[deg] = curr;
        curr = next;
    }
    delete min_node;
    size--;
    Node* first;
    Node* last;
    first = last = min_node = NULL;
    for (int i = 0; i < D; i++) {
        if (tmp[i] != NULL) {
            if (first == NULL) min_node = first = last = tmp[i];
            else {
                if (tmp[i]->key < min_node->key)
                    min_node = tmp[i];
                last->right = tmp[i];
                tmp[i]->left = last;
                last = tmp[i];
            }
        }
    }
    if (first != NULL) {
        last->right = first;
        first->left = last;
    }
}
 
void FibonacciHeap::Insert(Node* curr) {
    FibonacciHeap* unit_heap = new FibonacciHeap();
    unit_heap->min_node = curr;
    unit_heap->size = 1;
    Merge(unit_heap);
    delete unit_heap;
}
 
void FibonacciHeap::DecreaseKey(Node* curr, int new_key) {
    curr->key = new_key;
    Node* parent = curr->parent;
    if (parent != NULL && curr->key < parent->key) {
        MakeRootNode(curr);
        curr->marked = false;
        if (curr->key < min_node->key)
            min_node = curr;
        curr = parent;
        while (curr != NULL && curr->marked) {
            parent = curr->parent;
            MakeRootNode(curr);
            curr->marked = false;
            curr = parent;
        }
        if (curr != NULL && curr->parent != NULL)
            curr->marked = true;
    }
    else if (parent == NULL && curr->key < min_node->key)
        min_node = curr;
}
 
void FibonacciHeap::Merge(FibonacciHeap* other) {
    if (other->size == 0) return;
    if (this->size == 0) this->min_node = other->min_node;
    else
    {
        Node* this_right = this->min_node->right;
        Node* other_left = other->min_node->left;
        this->min_node->right = other->min_node;
        other->min_node->left = this->min_node;
        this_right->left = other_left;
        other_left->right = this_right;
    }
    this->size += other->size;
}
 
int FibonacciHeap::GetSize() {
    return size;
}
 
void FibonacciHeap::LinkRootNodes(Node* top, Node* bottom) {
    bottom->left->right = bottom->right;
    bottom->right->left = bottom->left;
    Node* child = top->first_child;
    bottom->parent = top;
    top->first_child = bottom;
    bottom->left = bottom->right = NULL;
    if (child != NULL) {
        bottom->right = child;
        child->left = bottom;
    }
    top->degree++;
    top->marked = false;
}
 
void FibonacciHeap::MakeRootNode(Node* curr) {
    if (curr->left != NULL) curr->left->right = curr->right;
    if (curr->right != NULL) curr->right->left = curr->left;
    if (curr->parent != NULL) {
        if (curr->parent->first_child == curr)
            curr->parent->first_child = curr->right;
        curr->parent->degree--;
    }
    curr->parent = NULL;
    Node* min_right = min_node->right;
    curr->right = min_right;
    min_right->left = curr;
    curr->left = min_node;
    min_node->right = curr;
}
 
int main() {
    return 0;
}