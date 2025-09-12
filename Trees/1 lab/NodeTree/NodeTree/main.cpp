//@author: Natalya Arsentyeva


#include <iostream>
#include "TreeNode.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "RUS");
    // Создаем узлы
    TreeNode<int>* node1 = new TreeNode<int>(5, nullptr, nullptr);
    TreeNode<int>* node2 = new TreeNode<int>(4, nullptr, nullptr);
    TreeNode<int>* node4 = new TreeNode<int>(3, node2, node1);
    TreeNode<int>* node3 = new TreeNode<int>(2, nullptr, nullptr);
    TreeNode<int>* root = new TreeNode<int>(1, node3, node4);

    /*   1
      2     3
          4   5                      */

          // Выводим дерево
    cout << "Дерево из 5 узлов:\n";
    cout << "    " << root->data << "\n";
    cout << "  " << root->left->data << "   " << root->right->data << "\n";
    cout << "     " << root->right->left->data << "  " << root->right->right->data << "\n";

    // Обращаемся к содержимому узлов
    cout << "Содержимое узла 1: " << node1->data << std::endl;
    cout << "Содержимое узла 3: " << node3->data << std::endl;

    // Удаляем узлы
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete root;

    return 0;
}

