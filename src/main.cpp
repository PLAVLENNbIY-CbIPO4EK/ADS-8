// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>

#include "bst.h"
#include "alg.h"

int main() {
    BST<std::string> tree;

    makeTree(tree, "war_peace.txt");

    std::cout << tree.depth() << std::endl;

    printFreq(tree);

    return 0;
}
