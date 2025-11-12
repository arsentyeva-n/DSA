//@author: Natalya Arsentyeva

#include "pch.h"
//#include "../googletest-main/googletest/include/gtest/gtest.h"
// ! скачать Google Test

#include "../BinarySearchTree.h"


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



// Тест конструктора по умолчанию
TEST(TestBST, DefaultConstructor) {
    BinarySearchTree<int> tree;

    EXPECT_TRUE(tree.Empty());
    EXPECT_EQ(tree.Size(), 0);
    EXPECT_EQ(tree.get_root(), nullptr);
}



// Тест конструктора копирования
TEST(TestBST, CopyConstructor) {
    BinarySearchTree<int> original = createTree3();

    // Используем конструктор копирования
    BinarySearchTree<int> copy(original);

    // Проверяем, что размер одинаковый
    EXPECT_EQ(original.Size(), copy.Size());

    // Проверяем, что структура одинаковая
    vector<int> exp,result;
    createVectorNLR(original.get_root(), exp);
    createVectorNLR(copy.get_root(), result);
    EXPECT_EQ(original.Size(), copy.Size());
    EXPECT_EQ(exp, result);

    // Проверяем, что это разные объекты
    EXPECT_NE(original.get_root(), copy.get_root());

    // Изменяем оригинал - копия не должна измениться
    original.Insert(25);
    EXPECT_EQ(original.Size(), 6);
    EXPECT_EQ(copy.Size(), 5);
}

// Тест оператора присваивания копированием
TEST(TestBST, CopyAssignmentOperator) {
    BinarySearchTree<int> original = createTree1();
    BinarySearchTree<int> copy;

    // Используем оператор присваивания копированием
    copy = original;

    // Проверяем, что размер одинаковый
    EXPECT_EQ(original.Size(), copy.Size());

    // Проверяем, что структура одинаковая
    vector<int> exp, result;
    createVectorNLR(original.get_root(), exp);
    createVectorNLR(copy.get_root(), result);
    EXPECT_EQ(original.Size(), copy.Size());
    EXPECT_EQ(exp, result);

    // Проверяем, что это разные объекты
    EXPECT_NE(original.get_root(), copy.get_root());

    // Изменяем оригинал - копия не должна измениться
    original.Insert(25);
    EXPECT_EQ(original.Size(), 7);
    EXPECT_EQ(copy.Size(), 6);

    // Проверяем самоприсваивание
    copy = copy;  
    EXPECT_EQ(copy.Size(), 6);
}


// Тест конструктора перемещения
TEST(TestBST, MoveConstructor) {
    BinarySearchTree<int> original = createTree1();

    size_t originalSize = original.Size();
    TreeNode<int>* originalRoot = original.get_root();

    // Используем конструктор перемещения
    BinarySearchTree<int> moved(move(original));

    // Проверяем что данные переместились
    EXPECT_EQ(moved.Size(), originalSize);
    EXPECT_EQ(moved.get_root(), originalRoot);

    // Проверяем что оригинал обнулился
    EXPECT_TRUE(original.Empty());
    EXPECT_EQ(original.Size(), 0);
    EXPECT_EQ(original.get_root(), nullptr);

    // Проверяем что перемещенный объект работает
    EXPECT_FALSE(moved.Empty());
    moved.Insert(6);
    EXPECT_EQ(moved.Size(), 7);
}

// Тест оператора присваивания перемещением
TEST(TestBST, MoveAssignmentOperator) {
    BinarySearchTree<int> original = createTree1();

    BinarySearchTree<int> moved;

    size_t originalSize = original.Size();
    TreeNode<int>* originalRoot = original.get_root();

    // Используем оператор присваивания перемещением
    moved = move(original);

    // Проверяем перемещение
    EXPECT_EQ(moved.Size(), originalSize);
    EXPECT_EQ(moved.get_root(), originalRoot);

    // Проверяем что источник обнулился
    EXPECT_TRUE(original.Empty());
    EXPECT_EQ(original.Size(), 0);
    EXPECT_EQ(original.get_root(), nullptr);

    // Проверяем самоприсваивание перемещением
    moved = move(moved); 
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


// Тест очистки дерева
TEST(TestBST, ClearTree) {
    BinarySearchTree<int> tree;

    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);

    EXPECT_FALSE(tree.Empty());
    EXPECT_EQ(tree.Size(), 3);

    tree.Clear();

    EXPECT_TRUE(tree.Empty());
    EXPECT_EQ(tree.Size(), 0);
    EXPECT_EQ(tree.get_root(), nullptr);
}



