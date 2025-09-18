//@author: Natalya Arsentyeva

#include "pch.h"
#include "../NodeTree/NodeTree/TreeNode.h"



TEST(TreeNodeTest, CreateNode)
{
    TreeNode<int> node(10);                    // Создаём узел с данными
    EXPECT_EQ(node.Data(), 10);                // Проверяем, что get-метод Data() возвращает 10
    EXPECT_EQ(node.Left(), nullptr);           // Проверяем, что левый потомок отсутствует
    EXPECT_EQ(node.Right(), nullptr);          // Проверяем, что правый потомок отсутствует
}



TEST(TreeNodeTest, Setters)
{
    TreeNode<int>* left = new TreeNode<int>(5);    // Создаём левый дочерний узел
    TreeNode<int>* right = new TreeNode<int>(15);  // Создаём правый дочерний узел
    TreeNode<int> root(10, left, right);           // Создаём корень с двумя узлами

    EXPECT_EQ(root.Left()->Data(), 5);            // Проверяем левого потомка
    EXPECT_EQ(root.Right()->Data(), 15);          // Проверяем правого потомка

    delete left;                                  
    delete right;                                 
}