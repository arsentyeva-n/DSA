//@author: Natalya Arsentyeva


#include <iostream>
#include "TreeNode.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "RUS");
    // Создание узлов
    TreeNode<int>* n1 = new TreeNode<int>(1);
    TreeNode<int>* n2 = new TreeNode<int>(2);
    TreeNode<int>* n3 = new TreeNode<int>(3);
    TreeNode<int>* n4 = new TreeNode<int>(4);
    TreeNode<int>* n5 = new TreeNode<int>(5);

    // Построение дерева
    //           1
    //         /   \
    //        2     3
    //             / \
    //            4   5
    n1->setLeft(n2);
    n1->setRight(n3);
    n2->setLeft(n4);
    n2->setRight(n5);
    
    cout << "Корень дерева: " << n1->Data() << endl;
    cout << "Левый потомок корня: " << n1->Left()->Data() << endl;
    cout << "Правый потомок корня: " << n1->Right()->Data() << endl;

    cout << "Дерево:\n";
    cout << "       1\n";
    cout << "     /   \\\n";
    cout << "    2     3\n";
    cout << "         / \\\n";
    cout << "        4   5\n";

    deleteTree(n1);

    cout << "Корень дерева: " << n1->Data() << endl;

    return 0;
}

