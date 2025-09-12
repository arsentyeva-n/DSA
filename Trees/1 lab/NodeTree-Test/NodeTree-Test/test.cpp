//@author: Natalya Arsentyeva

#include "pch.h"
#include "../../NodeTree/NodeTree/TreeNode.h"


// 
TEST(TreeNodeTest, CreateNode)
{
    TreeNode<int> node(10);                    // ������ ���� � �������
    EXPECT_EQ(node.Data(), 10);                // ���������, ��� get-����� Data() ���������� 10
    EXPECT_EQ(node.Left(), nullptr);           // ���������, ��� ����� ������� �����������
    EXPECT_EQ(node.Right(), nullptr);          // ���������, ��� ������ ������� �����������
}



//
TEST(TreeNodeTest, Setters)
{
    TreeNode<int>* left = new TreeNode<int>(5);    // ������ ����� �������� ����
    TreeNode<int>* right = new TreeNode<int>(15);  // ������ ������ �������� ����
    TreeNode<int> root(10, left, right);           // ������ ������ � ����� ������

    EXPECT_EQ(root.Left()->Data(), 5);            // ��������� ����� �������
    EXPECT_EQ(root.Right()->Data(), 15);          // ��������� ������ �������

    delete left;                                  // ����������� ������ ��� ������ ����
    delete right;                                 // ����������� ������ ��� ������� ����
}