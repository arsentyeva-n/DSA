//@author: Natalya Arsentyeva

#include "pch.h"
#include "../../NodeTree/NodeTree/TreeNode.h"


// ������������ ��������� ����

TreeNode<int>* createTree1() {


    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    // �������� �����
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

// ����������� ������
TreeNode<int>* createTree2() {

    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

     // �������� �����
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* n1 = new TreeNode<int>(19);
    TreeNode<int>* n2 = new TreeNode<int>(30);
    TreeNode<int>* n3 = new TreeNode<int>(33);

    root->setRight(n1);
    n1->setRight(n2);
    n2->setRight(n3);

    return root;
}

// ����������� �����
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


     // �������� �����
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

// ����������� ������
TreeNode<int>* createTree4() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* rightleaf, * leftleaf, * root;


    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5        

    rightleaf = new TreeNode<int>(3);
    leftleaf = new TreeNode<int>(1);


    root = new TreeNode<int>(2, leftleaf, rightleaf);

    leftleaf = new TreeNode<int>(5);
    rightleaf = new TreeNode<int>(7, leftleaf, nullptr);

    root = new TreeNode<int>(4, root, rightleaf);

    leftleaf = new TreeNode<int>(9);
    rightleaf = new TreeNode<int>(30);

    rightleaf = new TreeNode<int>(10, leftleaf, rightleaf);

    root = new TreeNode<int>(8, root, rightleaf);

    return root;
}

TEST(TestTreeNode, TestFindDepth) {

    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(3, findDepth(root1));

    // ����������� ������
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(3, findDepth(root2));

    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(4, findDepth(root3));

    // ����������� ������
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(3, findDepth(root4));

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(-1, findDepth(root5));

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(0, findDepth(root6));
}



TEST(TestTreeNode, CreateNode)
{
    TreeNode<int> node(10);                    // ������ ���� � �������
    EXPECT_EQ(node.Data(), 10);                // ���������, ��� get-����� Data() ���������� 10
    EXPECT_EQ(node.Left(), nullptr);           // ���������, ��� ����� ������� �����������
    EXPECT_EQ(node.Right(), nullptr);          // ���������, ��� ������ ������� �����������
}


//
TEST(TestTreeNode, Setters)
{
    TreeNode<int>* left = new TreeNode<int>(5);    // ������ ����� �������� ����
    TreeNode<int>* right = new TreeNode<int>(15);  // ������ ������ �������� ����
    TreeNode<int> root(10, left, right);           // ������ ������ � ����� ������

    EXPECT_EQ(root.Left()->Data(), 5);            // ��������� ����� �������
    EXPECT_EQ(root.Right()->Data(), 15);          // ��������� ������ �������

    delete left;                                  // ����������� ������ ��� ������ ����
    delete right;                                 // ����������� ������ ��� ������� ����
}