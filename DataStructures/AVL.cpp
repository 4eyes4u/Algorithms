/*
    Name: AVL tree

    Time complexity: O(logN) per operation
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class AVLTree {
private:
    struct Node {
        int key, height;
        T data;
        Node *l, *r, *parent;

        Node(pair<int, T> p, Node *parent) {
            this->key = p.first;
            this->data = p.second;
            this->parent = parent;
        }
    };

    Node *root = nullptr;
    int size = 0;

    void balance(Node *cur) {
        while (cur) {
            cur->height = max(get_height(cur->l), get_height(cur->r)) + 1;

            // right subtree is much higher
            if (get_balance_factor(cur) == -2) {
                // worst case
                if (get_height(cur->l->r) > get_height(cur->l->l))
                    rotate_left(cur->l);

                rotate_right(cur);
            }
            // left subtree is much higher
            else if (get_balance_factor(cur) == 2) {
                // worst case
                if (get_balance_factor(cur->r->l) > get_height(cur->r->r))
                    rotate_right(cur->r);

                rotate_left(cur);
            }

            cur = cur->parent;
        }
    }

    void rotate_left(Node *cur) {
        Node *pivot = cur->r;
        Node *parent = cur->parent;
        cur->r = pivot->l;

        if (cur->r)
            cur->r->parent = cur;

        pivot->l = cur;
        cur->parent = pivot;
        if (parent) {
            if (parent->r == cur)
                parent->r = pivot;
            else
                parent->l = pivot;
        }

        pivot->parent = parent;
        if (root == cur)
            root = pivot;

        cur->height = max(get_height(cur->l), get_height(cur->r)) + 1;
        pivot->height = max(get_height(pivot->l), get_height(pivot->r)) + 1;  
    }

    void rotate_right(Node *cur) {
        Node *pivot = cur->l;
        Node *parent = cur->parent;
        cur->l = pivot->r;

        if (cur->l)
            cur->l->parent = cur;
        
        pivot->r = cur;
        cur->parent = pivot;
        if (parent) {
            if (parent->r == cur)
                parent->r = pivot;
            else
                parent->l = pivot;
        }

        pivot->parent = parent;
        if (root == cur)
            root = pivot;

        cur->height = max(get_height(cur->l), get_height(cur->r)) + 1;
        pivot->height = max(get_height(pivot->l), get_height(pivot->r)) + 1;
    }

    int get_balance_factor(Node *cur) {
        return get_height(cur->l) - get_height(cur->r);
    }

    int get_height(Node *cur) {
        return cur ? cur->height : 0;
    }

public:
    bool find(int key, T &data) {
        // simple traversal
        Node *cur = root;
        while(cur) {
            if (cur->key == key) {
                data = cur->data;
                return true;
            }
            else if (cur->key > key)
                cur = cur->l;
            else
                cur = cur->r;
        }

        return false;
    }

    bool insert(pair<int, T> p) {
        // the tree is empty
        if (!root) {
            root = new Node(p, NULL);
            size++;
            return true;
        }

        // simple traversal
        int key = p.first;
        Node *cur = root;
        while (p.first != cur->key) {
            if (cur->key > key) {
                if (!cur->l) {
                    cur->l = new Node(p, cur);
                    size++;
                    balance(cur);

                    return true;
                }
                cur = cur->l;
            }
            else {
                if (!cur->r) {
                    cur->r = new Node(p, cur);
                    size++;
                    balance(cur);

                    return true;
                }
                cur = cur->r;
            }
        }

        // that key is already present in the tree
        return false;
    }

    bool remove(int key) {
        Node *cur = root;
        
        // basic traversal
        while (cur && key != cur->key) {
            if (cur->key > key)
                cur = cur->l;
            else
                cur = cur->r;
        }

        // nothing to delete
        if (!cur)
            return false;

        Node *parent = cur->parent;
        Node **tmp;
        if (cur == root)
            tmp = &root;
        else if (parent->l == cur)
            tmp = &(parent->l);
        else
            tmp = &(parent->r);

        // removing node from the tree
        if (!cur->l || !cur->r) {
            // no children, just delete it
            if (!cur->l && !cur->r)
                *tmp = nullptr;
            // no left children, swap with the right one
            else if (!cur->l) {
                *tmp = cur->r;
                cur->r->parent = parent;
            }
            // no right children, swap with the left one
            else {
                *tmp = cur->l;
                cur->l->parent = parent;
            }

            delete(cur);
            size--;
            balance(parent);
        }
        else {
            // there are both children, so swap with predecessor
            Node *pred = cur->r;
            while (pred->r)
                pred = pred->r;

            int pred_key = pred->key;
            T pred_data = pred->data;
            remove(pred_key);
            cur->key = pred_key;
            cur->data = pred_data;
        }

        return true;
    }

    int get_size() {
        return size;
    }
};

int main() {
    AVLTree<string> *tree = new AVLTree<string>();

    tree->insert({5, "kosta"});
    tree->insert({3, "mdcs"});
    tree->insert({7, "hololens"});
    tree->insert({1, "analog"});
    tree->insert({4, "cognition"});
    tree->insert({6, "bezier"});
    tree->insert({8, "dnn"});

    // size is 7
    cout << tree->get_size() << endl;
    string data;
    // there is 6
    cout << tree->find(6, data) << endl;
    cout << data << endl;

    // there is no 10
    tree->remove(10);
    // 6 should be deleted
    tree->remove(6);

    // size is now 6
    cout << tree->get_size() << endl;
    // there is no 6 anymore
    cout << tree->find(6, data) << endl;

    return 0;
}
