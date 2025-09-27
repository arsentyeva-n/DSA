//@author: Natalya Arsentyeva


#include <iostream>
#include "TreeNode.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "RUS");

    cout << "\nБинарное дерево: " << endl;
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
    n3->setLeft(n4);
    n3->setRight(n5);
    
    cout << "Корень дерева: " << n1->Data() << endl;
    cout << "Левый потомок корня: " << n1->Left()->Data() << endl;
    cout << "Правый потомок корня: " << n1->Right()->Data() << endl;

    cout << "Дерево:\n";
    cout << "       1\n";
    cout << "     /   \\\n";
    cout << "    2     3\n";
    cout << "         / \\\n";
    cout << "        4   5\n";

   
    // Прямой, симметричный и обратный обходы
    /*printNLR(n1);
    cout << endl;
    printLNR(n1);
    cout << endl;
    printLRN(n1);
    cout << endl;*/

    vector<int> arrayNLR;                   // Пустой вектор для хранения значений
    createVectorNLR(n1, arrayNLR);          // Заполнение вектора значениями
    printVector(arrayNLR);                  // Вывод вектора

    vector<int> arrayLNR;
    createVectorLNR(n1, arrayLNR);
    printVector(arrayLNR);

    vector<int> arrayLRN;
    createVectorLRN(n1, arrayLRN);
    printVector(arrayLRN);

    // Поиск глубины дерева
    cout << "Глубина дерева: " << findDepth(n1) << endl;

    // Подсчет узлов дерева
    cout << "Кол-во узлов: " << countNode(n1) << endl;


    cout << "\nКопирование дерева" ;
    TreeNode<int>* newT;
    newT = copyTree(n1);
    calcTree(newT);
    cout << "\nСкопированное дерево, вывод по уровням: " << endl;
    // Печать, используя обход в ширину
    BFS(newT);

    //printSqr(newT);

    // Удаление дерева
    n1 = deleteTree(n1);
    newT = deleteTree(newT);

    // Проверка, что дерево удалено
    cout << "\nКоличество узлов: " << countNode(newT) << endl;
    cout << "Глубина дерева: " << findDepth(n1) << endl;
    


    cout << "\nБинарное дерево поиска: " << endl;

    //     8
    //    / \
    //   3   10
    //  / \
    // 1   6
    //    /
    //   4

    // Создание узлов и построение дерева
    // указатели на узлы дерева 
   /* TreeNode<int>* lnode, * rnode, * root;*/
    TreeNode<int>* lnode = new TreeNode<int>(4);                    // создание левого узла без потомков
    TreeNode<int>* rnode = new TreeNode<int>(6, lnode, nullptr);    // создание правого узла 6 с левым потомком
    lnode = new TreeNode<int>(1);                                   // создание нового левого узла без потомков
    TreeNode<int>* root = new TreeNode<int>(3,lnode,rnode);         // создание поддерева с потомками от 3
    lnode = root;                                                   // после это поддерево становится левым потомком
    rnode = new TreeNode<int>(10);
    root = new TreeNode<int>(8, lnode, rnode);                      // основной корень этого дерева

    cout << "Дерево:\n";
    cout << "       8\n";
    cout << "     /   \\\n";
    cout << "    3     10\n";
    cout << "   / \\\n";
    cout << "  1   6       \n";
    cout << "     /         \n";
    cout << "    4           \n";

    cout << "\nВывод дерева: " << endl;
    BFS(root);
    SearchNode(root,5);
    InsertNode(root, 7);
    BFS(root);

    cout << "\nНахождение следующего наибольшего для 7: ";
    TreeNode<int>* s = nullptr;
    s = Successor(root, 7);
    if (s != nullptr) {
        cout << s->Data();
    }
    else cout << "Не существует\n";
    cout << " \n";
    removeNode(root,7);
    removeNode(root, 3);
    BFS(root);
    //inOrderSort(root);

    // Удаление дерева
    root = deleteTree(root);

    return 0;
}

