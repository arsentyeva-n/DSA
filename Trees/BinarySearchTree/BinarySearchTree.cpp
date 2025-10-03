//@author: Natalya Arsentyeva


#pragma once

#include <iostream>
#include "BinarySearchTree.h"

// Вспомогательная функция для печати дерева в NLR-порядке
template <typename T>
void printTreeNLR(TreeNode<T>* root) {
    if (root == nullptr) return;
    std::cout << root->Data() << " ";
    printTreeNLR(root->Left());
    printTreeNLR(root->Right());
}

int main() {
    //          12
    //       /     \
    //      7       15
    //    /   \     / \
    //   4     10 13   30
    //  / \    /       
    // 1   5  8        

    BinarySearchTree<int> bst1;

    bst1.Insert(12);
    bst1.Insert(7);
    bst1.Insert(15);
    bst1.Insert(4);
    bst1.Insert(10);
    bst1.Insert(5);
    bst1.Insert(1);
    bst1.Insert(8);
    bst1.Insert(13);
    bst1.Insert(30);

    printTreeNLR(bst1.get_root()); // Ожидается: 12 7 4 1 5 10 8 15 13 30
    std::cout << "\nSize: " << bst1.Size() << "\n"; // Ожидается: 10

    std::cout << "\nRemove node 4\n";
    bst1.Remove(7);
    std::cout << "Tree after removing 7: ";
    printTreeNLR(bst1.get_root()); // Ожидается: 12 8 4 1 5 10 15 13 30
    std::cout << "\nSize: " << bst1.Size() << "\n"; // Ожидается: 9
    bst1.Clear();
    std::cout << "Size: " << bst1.Size() << "\n"; // Ожидается: 0

    //// Тест 5: Конструктор с параметром
    //std::cout << "\nTest 5: Constructor with parameter\n";
    //TreeNode<int>* tempRoot = new TreeNode<int>(5);
    //tempRoot->setLeft(new TreeNode<int>(3));
    //tempRoot->setRight(new TreeNode<int>(7));
    //BinarySearchTree<int> bst2(tempRoot);
    //std::cout << "Tree from constructor: ";
    //printTreeNLR(bst2.get_root()); // Ожидается: 5 3 7
    //std::cout << "\nSize: " << bst2.Size() << "\n"; // Ожидается: 3
    //deleteTree(tempRoot); // Очистка временного дерева

    return 0;
}