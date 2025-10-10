//@author: Natalya Arsentyeva


#pragma once

#include <iostream>
#include "BinarySearchTree.h"



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
    cout << "\nКонструктор копирования: \n";
    BinarySearchTree<int> bst2 = bst1;
    printNLR(bst2.get_root());

    // Конструктор с параметром
    cout << "\nДерево конструктора с параметром: \n";
    BinarySearchTree<int> bst3(bst1);
    printNLR(bst3.get_root());

    //          12
    //       /     \
    //      8      15
    //    /   \     / \
    //   4     10 13   30
    //  / \             \      
    // 1   5            100
    // Вставка
    bst3.Insert(100);
    bst3.Insert(6);
    cout << "\nДерево после вставки 100 и 6: \n";
    BFS(bst3.get_root()); 
    cout << "\nРазмер: " << bst3.Size() << "\n"; 

    //          12
    //       /     \
    //      8      15
    //    /   \     / \
    //   4     10 13   30
    //  / \             \      
    // 1   5            100
    //      \
    //       6

    cout << "\nДерево присваивания: \n";
    bst3 = bst2;
    printNLR(bst3.get_root()); 
    cout << "\nРазмер: " << bst3.Size() << "\n"; // 9

    bst1.Clear();
    cout << "\nРазмер после удаления: " << bst1.Size() << "\n"; // Ожидается: 0

    

    return 0;
}