

#include <iostream>
#include "Heap.h"
using namespace std;

TreeNode<int>* createTree1() {


    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    // Создание узлов
    TreeNode<int>* root = new TreeNode<int>(5);
    TreeNode<int>* n1 = new TreeNode<int>(4);
    TreeNode<int>* n2 = new TreeNode<int>(22);
    TreeNode<int>* n3 = new TreeNode<int>(12);
    TreeNode<int>* n4 = new TreeNode<int>(24);
    TreeNode<int>* n5 = new TreeNode<int>(10);

    root->setLeft(n1);
    root->setRight(n2);

    n2->setLeft(n3);
    n2->setRight(n4);

    n3->setLeft(n5);

    return root;
}

// Вырожденное вправо
TreeNode<int>* createTree2() {

    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

     // Создание узлов
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* n1 = new TreeNode<int>(19);
    TreeNode<int>* n2 = new TreeNode<int>(30);
    TreeNode<int>* n3 = new TreeNode<int>(33);

    root->setRight(n1);
    n1->setRight(n2);
    n2->setRight(n3);

    return root;
}

// Вырожденное влево
TreeNode<int>* createTree3() {

    //       60
    //       /  
    //      42   
    //      /   
    //     14     
    //     /
    //    21
    //    /
    //   13


     // Создание узлов
    TreeNode<int>* root = new TreeNode<int>(60);
    TreeNode<int>* n1 = new TreeNode<int>(42);
    TreeNode<int>* n2 = new TreeNode<int>(14);
    TreeNode<int>* n3 = new TreeNode<int>(21);
    TreeNode<int>* n4 = new TreeNode<int>(13);

    root->setLeft(n1);
    n1->setLeft(n2);
    n2->setLeft(n3);
    n3->setLeft(n4);

    return root;
}

// Завершенное дерево
TreeNode<int>* createTree4() {

    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5        

     // Создание узлов
    TreeNode<int>* root = new TreeNode<int>(8);
    TreeNode<int>* n1 = new TreeNode<int>(4);
    TreeNode<int>* n2 = new TreeNode<int>(10);
    TreeNode<int>* n3 = new TreeNode<int>(2);
    TreeNode<int>* n4 = new TreeNode<int>(7);
    TreeNode<int>* n5 = new TreeNode<int>(9);
    TreeNode<int>* n6 = new TreeNode<int>(30);
    TreeNode<int>* n7 = new TreeNode<int>(1);
    TreeNode<int>* n8 = new TreeNode<int>(3);
    TreeNode<int>* n9 = new TreeNode<int>(5);

    // Построение дерева
    root->setLeft(n1);
    root->setRight(n2);

    n1->setLeft(n3);
    n1->setRight(n4);

    n2->setLeft(n5);
    n2->setRight(n6);

    n3->setLeft(n7);
    n3->setRight(n8);

    n4->setLeft(n9);

    return root;
}


int main()
{
	setlocale(LC_ALL, "RUS");

    // Создаем max-heap
	Heap<int> h;
	h.insert(20);
	h.insert(10);
	h.insert(5);
	h.insert(15);
	h.insert(30);
	h.insert(25);
	h.insert(100);
	cout << "\nsize: " << h.Size() << endl;
	h.printList();

    // Извлекаем максимум и удаляем его
	cout << "\n" << h.extractMax() << endl;
	cout << "\nsize: " << h.Size() << endl;
	h.printList();
    
    // Проверка путсоты дерева
	h.clear();
	if (h.empty() == true) cout << "\nКуча пустая\n";

    // Создание кучи на основе бинарного дерева
    TreeNode<int>* root = createTree3();
    Heap<int> h2 = buildHeapBinTree(root);
    cout << "\nsize: " << h2.Size() << endl;
    h2.printList();

    // Удаляем бинарное дерево
    deleteTree(root);

    // Вставка в кучу на основе бинарного дерева
    h2.insert(100);
    cout << "\nsize: " << h2.Size() << endl;
    h2.printList();

    vector<int> vec = { 10, 30, 5, 20, 25, 15 };
    Heap<int> h3({ 10, 30, 5, 20, 25, 15 });
   // Heap<int> h3(vec); 
    cout << "\nsize: " << h3.Size() << endl;

    h3.printList();
    cout << "\n" << h3.search(5) << endl;

    // Извлекаем максимум и удаляем его
    cout << "\n" << h3.extractMax() << endl;
    cout << "\nsize: " << h3.Size() << endl;
    h3.printList();

    cout << "\n" << h3.search(30) << endl;
}

