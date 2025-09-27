//@author: Natalya Arsentyeva


#pragma once
#include "TreeNode.h"


///  �������� ������ ������

template <typename T>
class BinarySearchTree
{
	private:
		// ��������� �� ������ � �� ������� ����
		TreeNode<T>* root;
		TreeNode<T>* current;

		// ����� ��������� ������ 
		int size;


	public:
		// ����������� �� ���������
		BinarySearchTree();

		// ����������� � ����������
		BinarySearchTree(TreeNode<T>* tree);

		// ����������
		~BinarySearchTree() { deleteTree(this->root); };

		TreeNode<T>*

};


