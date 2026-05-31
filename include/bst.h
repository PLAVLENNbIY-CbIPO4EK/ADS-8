// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <utility>
#include <vector>

template <class T>
class BST {
 private:
    struct Node {
        T data;
        int count;
        Node *left;
        Node *right;
    };

    Node *root;

    void add(Node *&p, T x) {
        if (p == nullptr) {
            p = new Node;
            p->data = x;
            p->count = 1;
            p->left = nullptr;
            p->right = nullptr;
            return;
        }

        if (x < p->data) {
            add(p->left, x);
        } else if (x > p->data) {
            add(p->right, x);
        } else {
            p->count++;
        }
    }

    int dep(Node *p) {
        if (p == nullptr) {
            return 0;
        }

        int a = dep(p->left);
        int b = dep(p->right);

        if (a > b) {
            return a + 1;
        }

        return b + 1;
    }

    Node* find(Node *p, T x) {
        if (p == nullptr) {
            return nullptr;
        }

        if (p->data == x) {
            return p;
        }

        if (x < p->data) {
            return find(p->left, x);
        }

        return find(p->right, x);
    }

    void makeVec(Node *p, std::vector<std::pair<T, int>> *v) {
        if (p == nullptr) {
            return;
        }

        makeVec(p->left, v);

        v->push_back(std::make_pair(p->data, p->count));

        makeVec(p->right, v);
    }

 public:
    BST() {
        root = nullptr;
    }

    void insert(T x) {
        add(root, x);
    }

    int depth() {
        return dep(root);
    }

    int search(T x) {
        Node *p = find(root, x);

        if (p == nullptr) {
            return 0;
        }

        return p->count;
    }

    void getWords(std::vector<std::pair<T, int>> *v) {
        makeVec(root, v);
    }
};

#endif  // INCLUDE_BST_H_
