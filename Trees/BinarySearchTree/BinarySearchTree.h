//@author: Natalya Arsentyeva


#pragma once
#include "../NodeTree/NodeTree.h"


///  �������� ������ ������

template <typename T>
class BinarySearchTree
{
private:
	// ��������� �� ������
	TreeNode<T>* root;

	// ����� ��������� ������ 
	size_t size;


public:
	// ����������� �� ���������
	BinarySearchTree();

	//// ����������� � ����������
	//BinarySearchTree(TreeNode<T>* tree);

	// ����������
	~BinarySearchTree() { deleteTree(root); };

	size_t Size() const;
	void Insert(const T& item);
	void Remove(const T& item);
	TreeNode<T>* get_root() const;
	void Clear();
	bool Empty() const;
};

// ����������� �� ���������
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
	size = 0;
}

// ����������� � �����������
//template <typename T>
//BinarySearchTree<T>::BinarySearchTree(TreeNode<T>* tree)
//{
//	root = �opyTree(tree);
//	size = countNode(this->root);
//}

// ������� ����
template<class T>
void BinarySearchTree<T>::Insert(const T& item) {
	root = InsertNode(root, item);
	size++;
}

// �������� ����
template<class T>
void BinarySearchTree<T>::Remove(const T& item) {
	root = removeNode(root, item);
	size--;
}

// ������� ������
template <typename T>
void BinarySearchTree<T>::Clear() {
	deleteTree(this->root);
	root = nullptr;
	size = 0;
}

// ���������� ��������� �� ������
template <typename T>
TreeNode<T>* BinarySearchTree<T>::get_root() const
{
	return root;
}

// ��������, ������ �� ������
template<class T>
bool BinarySearchTree<T>::Empty() const {
	return (root == nullptr);
}

// ���������� ����� � ������
template<class T>
size_t BinarySearchTree<T>::Size() const {
	return size;
}



