//@author: Natalya Arsentyeva


#pragma once

#include <iostream>
#include "BinarySearchTree.h"
#include <stdexcept>


int main() {
    setlocale(LC_ALL, "RUS");
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

    printNLR(bst1.get_root()); // Ожидается: 12 7 4 1 5 10 8 15 13 30
    cout << "\nРазмер: " << bst1.Size() << "\n"; // Ожидается: 10

    // Удаление
    bst1.Remove(7);
    cout << "\nДерево после удаления 7: \n";
    printNLR(bst1.get_root()); // Ожидается: 12 8 4 1 5 10 15 13 30
    cout << "\nРазмер: " << bst1.Size() << "\n"; // Ожидается: 9

    // Конструктор копирования
    BinarySearchTree<int> bst2(bst1);
    printNLR(bst2.get_root());

    // Конструктор оператора копирования
    BinarySearchTree<int> bst3;
    bst3 = bst1;
    printNLR(bst3.get_root());

    try {
    BinarySearchTree<int> bst4;

    bst4.Insert(2);
    bst4.Insert(4);
    bst4.Insert(8);
    bst4.Insert(16);
    bst4.Insert(32);

    // Конструктор перемещения
    BinarySearchTree<int> bst5 = move(bst4);
    printNLR(bst5.get_root());

    
    // Конструктор оператора перемещения
    BinarySearchTree<int> bst6;
    bst6 = move(bst5);
    printNLR(bst6.get_root());

   // bst5.Remove(4); 
    }
    catch (const exception& e)
    {
        cout << "\nОбъект уже перемещен! " << e.what() << endl;
    }
    return 0;
}