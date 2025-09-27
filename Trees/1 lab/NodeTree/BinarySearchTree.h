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
		size_t size;


	public:
		// ����������� �� ���������
		BinarySearchTree();

		// ����������� � ����������
		BinarySearchTree(TreeNode<T>* tree, size_t size = 0);

		// ����������
		~BinarySearchTree() { deleteTree(this->root); };

		size_t Size() const {return size};
		TreeNode<T>* insert(TreeNode<T>* tree);
		TreeNode<T>* remove(TreeNode<T>* tree);
		TreeNode<T>* get_root(TreeNode<T>* tree) {return root};
		TreeNode<T>* clear(TreeNode<T>* tree) { return deleteTree(this->root); };
		bool empty(TreeNode<T>* tree);
		size_t height();
};


