// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <vector>
#include <utility>

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

    void addNode(Node *&cur, T val) {
        if (cur == nullptr) {
            cur = new Node;
            cur->data = val;
            cur->count = 1;
            cur->left = nullptr;
            cur->right = nullptr;
            return;
        }

        if (val < cur->data) {
            addNode(cur->left, val);
        } else if (val > cur->data) {
            addNode(cur->right, val);
        } else {
            cur->count++;
        }
    }

    int getDepth(Node *cur) {
        if (cur == nullptr) {
            return 0;
        }

        int l = getDepth(cur->left);
        int r = getDepth(cur->right);

        if (l > r) {
            return l + 1;
        }

        return r + 1;
    }

    Node* find(Node *cur, T val) {
        if (cur == nullptr) {
            return nullptr;
        }

        if (cur->data == val) {
            return cur;
        }

        if (val < cur->data) {
            return find(cur->left, val);
        }

        return find(cur->right, val);
    }

    void makeVec(Node *cur, std::vector<std::pair<T, int>> *arr) {
        if (cur == nullptr) {
            return;
        }
    
        makeVec(cur->left, arr);
    
        arr->push_back(std::make_pair(cur->data, cur->count));
    
        makeVec(cur->right, arr);
    }

        makeVec(cur->left, arr);
        arr->push_back(cur);
        makeVec(cur->right, arr);
    }

 public:
    BST() {
        root = nullptr;
    }

    void insert(T val) {
        addNode(root, val);
    }

    int depth() {
        return getDepth(root);
    }

    int search(T val) {
        Node *tmp = find(root, val);

        if (tmp == nullptr) {
            return 0;
        }

        return tmp->count;
    }

    void getWords(std::vector<std::pair<T, int>> *arr) {
        makeVec(root, arr);
    }
};

#endif  // INCLUDE_BST_H_
