//@author: Natalya Arsentyeva



#include "pch.h"
#include "../Heap.h"

// Тестирование кучи

// Тест конструктора с параметром
TEST(TestHeap, TestConstructor) {
	vector<int> exp = { 9, 8, 6, 3, 2, 1, 5 };      // Ожидаемый результат
    Heap<int> h1({ 1, 3, 6, 8, 2, 9, 5 });          // Произвольный вектор
    EXPECT_EQ(h1.HeapToVector(), exp);
    EXPECT_EQ(h1.Size(), 7);

    exp = { 42 };                                   // Ожидаемый результат
    Heap<int> h2({ 42 });                           // Произвольный вектор
    EXPECT_EQ(h2.HeapToVector(), exp);
    EXPECT_EQ(h2.Size(), 1);

    exp = { };                                       // Ожидаемый результат
    Heap<int> h3({ });                               // Произвольный вектор
    EXPECT_EQ(h3.HeapToVector(), exp);
    EXPECT_EQ(h3.Size(), 0);
}


// Тест вставки
TEST(TestHeap, TestInsert) {
    vector<int> exp = { 10, 9, 6, 8, 2, 1, 5, 3 };  // Ожидаемый результат
    Heap<int> h1({ 1, 3, 6, 8, 2, 9, 5 });          // Произвольный вектор
    h1.insert(10);
    EXPECT_EQ(h1.HeapToVector(), exp);
    EXPECT_EQ(h1.Size(), 8);
    
    exp = { 42,5 };                                   // Ожидаемый результат
    Heap<int> h2({ 42 });                             // Произвольный вектор
    h2.insert(5);
    EXPECT_EQ(h2.HeapToVector(), exp);
    EXPECT_EQ(h2.Size(), 2);
    
    exp = { 3 };                                       // Ожидаемый результат
    Heap<int> h3({ });                                 // Произвольный вектор
    h3.insert(3);
    EXPECT_EQ(h3.HeapToVector(), exp);
    EXPECT_EQ(h3.Size(), 1);
}

// Тест извлечения максимума
TEST(TestHeap, TestExtractMax) {
    vector<int> exp = { 9, 8, 6, 3, 2, 1, 5 };          // Ожидаемый результат
    Heap<int> h1({ 10, 9, 6, 8, 2, 1, 5, 3 });          // Произвольный вектор
    int max = h1.extractMax();
    EXPECT_EQ(h1.HeapToVector(), exp);
    EXPECT_EQ(max, 10);
    EXPECT_EQ(h1.Size(), 7);

    exp = { };                                       // Ожидаемый результат
    Heap<int> h2({ 42 });                             // Произвольный вектор
    max = h2.extractMax();
    EXPECT_EQ(h2.HeapToVector(), exp);
    EXPECT_EQ(max, 42);
    EXPECT_EQ(h2.Size(), 0);
}

// Тест очистки кучи
TEST(TestHeap, TestClear) {
    vector<int> exp = { };                              // Ожидаемый результат
    Heap<int> h1({ 10, 9, 6, 8, 2, 1, 5, 3 });          // Произвольный вектор
    h1.clear();
    EXPECT_EQ(h1.HeapToVector(), exp);
    EXPECT_EQ(h1.Size(), 0);

    Heap<int> h2({ 42 });                             // Произвольный вектор
    h2.clear();
    EXPECT_EQ(h2.HeapToVector(), exp);
    EXPECT_EQ(h2.Size(), 0);
}

// Тест поиска в куче
TEST(TestHeap, TestSearch) {
    Heap<int> h1({ 10, 9, 6, 8, 2, 1, 5, 3 });     
    EXPECT_EQ(h1.search(10), 0);
    EXPECT_EQ(h1.search(8), 3);
    EXPECT_EQ(h1.search(3), 7);
    EXPECT_EQ(h1.search(11), -1);
}


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


// Тест создания кучи из бинарного дерева
TEST(TestHeap, TestBinTreeToHeap) {

    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10
    vector<int> exp = { 24, 12, 22, 5, 4, 10 };          // Ожидаемый результат

    TreeNode<int>* tree1 = createTree1();                // Создаем бинарное дерево 
    Heap<int> h1(buildHeapArr(tree1));                   // Преобразуем вектор в кучу
    EXPECT_EQ(h1.HeapToVector(), exp);
    EXPECT_EQ(h1.Size(), 6);

    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33
    exp = { 33, 19, 30, 10 };                           // Ожидаемый результат

    TreeNode<int>* tree2 = createTree2();               // Создаем бинарное дерево 
    Heap<int> h2(buildHeapArr(tree2));                  // Преобразуем вектор в кучу
    EXPECT_EQ(h2.HeapToVector(), exp);
    EXPECT_EQ(h2.Size(), 4);

    //       60
    //       /  
    //      42   
    //      /   
    //     14     
    //     /
    //    21
    //    /
    //   13

    exp = { 60, 42, 14, 21, 13};                           // Ожидаемый результат

    TreeNode<int>* tree3 = createTree3();               // Создаем бинарное дерево 
    Heap<int> h3(buildHeapArr(tree3));                  // Преобразуем вектор в кучу
    EXPECT_EQ(h3.HeapToVector(), exp);
    EXPECT_EQ(h3.Size(), 5);

    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5   
    exp = { 30, 7, 10, 3, 5, 9, 8, 1, 2, 4};            // Ожидаемый результат

    TreeNode<int>* tree4 = createTree4();               // Создаем бинарное дерево 
    Heap<int> h4(buildHeapArr(tree4));                  // Преобразуем вектор в кучу
    EXPECT_EQ(h4.HeapToVector(), exp);
    EXPECT_EQ(h4.Size(), 10);
}

// Тест сортировки кучей
TEST(TestHeapSort, TestSort) {
    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10
    vector<int> exp = { 4, 5, 10, 12, 22, 24 };          // Ожидаемый результат
    
    TreeNode<int>* tree1 = createTree1();                // Создаем бинарное дерево 
    vector<int> arr = buildHeapArr(tree1);
    sort(arr);
    EXPECT_EQ(arr, exp);
    arr.clear();

    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33
    exp = { 10, 19, 30, 33 };                           // Ожидаемый результат

    TreeNode<int>* tree2 = createTree2();               // Создаем бинарное дерево 
    arr = buildHeapArr(tree2);
    sort(arr);
    EXPECT_EQ(arr, exp);
    arr.clear();

    //       60
    //       /  
    //      42   
    //      /   
    //     14     
    //     /
    //    21
    //    /
    //   13

    exp = { 13, 14, 21, 42, 60 };                           // Ожидаемый результат

    TreeNode<int>* tree3 = createTree3();               
    arr = buildHeapArr(tree3);
    sort(arr);
    EXPECT_EQ(arr, exp);
    arr.clear();

    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5   
    exp = { 1, 2, 3, 4, 5, 7, 8, 9, 10, 30 };            // Ожидаемый результат

    TreeNode<int>* tree4 = createTree4();               
    arr = buildHeapArr(tree4);
    sort(arr);
    EXPECT_EQ(arr, exp);
    arr.clear();

}