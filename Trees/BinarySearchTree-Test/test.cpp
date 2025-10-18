//@author: Natalya Arsentyeva

//#include "pch.h"
#include "../..gtest/gtest.h"
// ! скачать Google Test

#include "../BinarySearchTree/BinarySearchTree.h"


// Тестирование бинарного дерева поиска (BST)

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

    /*TreeNode<char>* root = new TreeNode<char>('A');
    TreeNode<char>* n1 = new TreeNode<char>('B');
    TreeNode<char>* n2 = new TreeNode<char>('C');
    TreeNode<char>* n3 = new TreeNode<char>('D');
    TreeNode<char>* n4 = new TreeNode<char>('E');
    TreeNode<char>* n5 = new TreeNode<char>('H');
    TreeNode<char>* n6 = new TreeNode<char>('I');
    TreeNode<char>* n7 = new TreeNode<char>('F');
    TreeNode<char>* n8 = new TreeNode<char>('G');
    TreeNode<char>* n9 = new TreeNode<char>('J');

    root->setLeft(n1);
    root->setRight(n2);

    n1->setLeft(n3);
    n1->setRight(n4);

    n2->setLeft(n7);
    n2->setRight(n8);

    n8->setLeft(n9);

    n3->setLeft(n5);
    n3->setRight(n6);*/

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


// Тест конструкторов по умолчанию, копирования, оператора копирования
TEST(TestBST, TestConstructors) 
{
    vector <int> vec1, vec2;

    // Обычное
    BinarySearchTree<int> bst1(createTree2());
    BinarySearchTree<int> bst2 = bst1;

    
    createVectorNLR(bst1.get_root(), vec1);
    createVectorNLR(bst2.get_root(), vec2);

    EXPECT_EQ(vec1, vec2);
    vec1.clear(); vec2.clear();

    // Вырожденное вправо
    BinarySearchTree<int> bst3(createTree1());
    BinarySearchTree<int> bst4 = bst3;

    createVectorNLR(bst3.get_root(), vec1);
    createVectorNLR(bst4.get_root(), vec2);

    EXPECT_EQ(vec1, vec2);
    vec1.clear(); vec2.clear();


    // Вырожденное влево
    BinarySearchTree<int> bst5(createTree3());
    bst1 = bst5;
    createVectorNLR(bst1.get_root(), vec1);
    createVectorNLR(bst5.get_root(), vec2);

    EXPECT_EQ(vec1, vec2);
    vec1.clear(); vec2.clear();


    // Пустое дерево
    BinarySearchTree<int> bst6;

    EXPECT_EQ(bst6.Size(), 0);
    EXPECT_EQ(bst6.Empty(), true);
    

    // Дерево с одним узлом
    TreeNode<int>* root = new TreeNode<int>(42);
    BinarySearchTree<int> bst7(root);
    bst3 = bst7;
    createVectorNLR(bst3.get_root(), vec1);
    createVectorNLR(bst7.get_root(), vec2);

    EXPECT_EQ(vec1, vec2);
    vec1.clear(); vec2.clear();
}


// Тест вставки
TEST(TestBST, TestInsert)
{
    vector <int> result, exp = { 8, 4, 2, 1, 3, 7, 5, 6, 10, 9, 30 };

    BinarySearchTree<int> bst1(createTree4());

     // Завершённое дерево
     //          8
     //       /    \
     //      4      10
     //    /   \    / \
     //   2     7   9   30
     //  / \    /       
     // 1   3  5      
    bst1.Insert(6);
    createVectorNLR(bst1.get_root(), result);

    EXPECT_EQ(result, exp);
    result.clear(); exp.clear();

    // Пустое дерево
    BinarySearchTree<int> bst2;
    exp = { 42 };
    bst2.Insert(42);
    createVectorNLR(bst2.get_root(), result);
    EXPECT_EQ(bst2.Size(), 1);
    EXPECT_EQ(result, exp);

}

// Тест удаления
TEST(TestBST, TestRemove)
{
    vector <int> result, exp = { 8, 4, 2, 1, 3, 7, 5, 10, 30 };

    BinarySearchTree<int> bst1(createTree4());

     //         8
     //       /    \
     //      4      10
     //    /   \    / \
     //   2     7   9   30
     //  / \    /       
     // 1   3  5      
     
    // Удаление узла без потомков
    bst1.Remove(9);
    createVectorNLR(bst1.get_root(), result);

    EXPECT_EQ(result, exp);
    result.clear();

    //         8
    //       /    \
     //      4      10
     //    /   \      \
     //   2     7       30
     //  / \    /       
     // 1   3  5      

    // с 1 потомком
    exp = { 8, 4, 2, 1, 3, 5, 10, 30 };
    bst1.Remove(7);
    createVectorNLR(bst1.get_root(), result);

    EXPECT_EQ(result, exp);
    result.clear();


     //         8
     //       /    \
     //      4      10
     //    /   \      \
     //   2     5       30
     //  / \           
     // 1   3       

    // с 2 потомками
    exp = { 10, 4, 2, 1, 3, 5,  30 };
    bst1.Remove(8);
    createVectorNLR(bst1.get_root(), result);

    EXPECT_EQ(result, exp);
    result.clear();

    //         10
     //       /    \
     //      4      30
     //    /   \      
     //   2     5       
     //  / \           
     // 1   3       


}