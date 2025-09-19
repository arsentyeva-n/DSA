//@author: Natalya Arsentyeva

#include "pch.h"
#include "../NodeTree/TreeNode.h"


// Тестирование бинарного узла

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

// Test vector NLR, LNR, LRN
TEST(TestTreeNode, TestVectorNLR_LNR_LRN) {


    //// Создаётся указатель на корень дерева 
    //TreeNode<char>* root1 = createTree1();

    ////NLR
    //vector<char> result, expected = { 'A','B','D','H','I','E','C','F','G','J'};
    //createVectorNLR(root1, result);
    //EXPECT_EQ(result, expected);
    //result.clear();
    //expected.clear();

    ////LNR
    //expected = { 'H','D','I','B','E','A','F','C','J','G' };
    //createVectorLNR(root1, result);
    //EXPECT_EQ(result, expected);
    //result.clear();
    //expected.clear();

    ////LRN
    //expected = { 'H','I','D','E','B','F','J','G','C','A' };
    //createVectorLRN(root1, result);
    //EXPECT_EQ(result, expected);
    //result.clear();
    //expected.clear();

    //deleteTree(root1);


    // Создаётся указатель на корень дерева 
    TreeNode<int>* root1 = createTree1();

    //NLR
    vector<int> result, expected = { 5, 4, 22, 12, 10, 24 };
    createVectorNLR(root1, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    //LNR
    expected = { 4, 5, 10, 12, 22, 24 };
    createVectorLNR(root1, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    //LRN
    expected = { 4, 10, 12, 24, 22, 5 };
    createVectorLRN(root1, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    deleteTree(root1);

    // Вырожденное вправо
    TreeNode<int>* root2 = createTree2();

    expected = { 10,19,30,33 };
    createVectorNLR(root2, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 10,19,30,33 };
    createVectorLNR(root2, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 33, 30, 19, 10 };
    createVectorLRN(root2, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    deleteTree(root2);

    // Вырожденное влево
    TreeNode<int>* root3 = createTree3();

    expected = { 60, 42, 14, 21, 13 };
    createVectorNLR(root3, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 13, 21, 14, 42, 60 };
    createVectorLNR(root3, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 13, 21, 14, 42, 60 };
    createVectorLRN(root3, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    deleteTree(root3);

    // Завершённое дерево
    TreeNode<int>* root4 = createTree4();

    expected = { 8, 4, 2, 1, 3, 7, 5, 10, 9, 30 };
    createVectorNLR(root4, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 1, 2, 3, 4, 5, 7, 8, 9, 10, 30 };
    createVectorLNR(root4, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 1, 3, 2, 5, 7, 4, 9, 30, 10, 8 };
    createVectorLRN(root4, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    deleteTree(root4);

    // Пустое дерево
    TreeNode<int>* root5 = nullptr;

    expected = { };
    createVectorNLR(root5, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { };
    createVectorLNR(root5, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { };
    createVectorLRN(root5, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    deleteTree(root5);

    // Дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(42);
    expected = { 42 };
    createVectorNLR(root6, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 42 };
    createVectorLNR(root6, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    expected = { 42 };
    createVectorLRN(root6, result);
    EXPECT_EQ(result, expected);
    result.clear();
    expected.clear();

    deleteTree(root6);
}


// Тест поиск глубины
TEST(TestTreeNode, TestFindDepth) {

    // Создаётся указатель на корень дерева 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(3, findDepth(root1));

    // Вырожденное вправо
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(3, findDepth(root2));

    // Вырожденное влево
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(4, findDepth(root3));

    // Завершённое дерево
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(3, findDepth(root4));

    // Пустое дерево
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(-1, findDepth(root5));

    // Дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(0, findDepth(root6));
}


// Тест нахождения количества узлов в дереве
TEST(TestTreeNode, TestCount) {

    // Cоздаётся указатель на корень дерева 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(6, countNode(root1));

    // Вырожденное вправо
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(4, countNode(root2));

    // Вырожденное влево
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(5, countNode(root3));

    // Завершённое дерево
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(10, countNode(root4));

    // Пустое дерево
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(0, countNode(root5));

    // Дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(1, countNode(root6));
}