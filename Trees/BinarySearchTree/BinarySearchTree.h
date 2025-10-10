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

	// ����������� � ����������
	BinarySearchTree(TreeNode<T>* tree);

	// ����������� �����������
	BinarySearchTree (const BinarySearchTree<T>& tree);

	// ����������
	~BinarySearchTree() { deleteTree(root); };

	size_t Size() const;
	void Insert(const T& item);
	void Remove(const T& item);
	TreeNode<T>* get_root() const;
	void Clear();
	bool Empty() const;
	//find

	// �������� ������������ ������������
	BinarySearchTree<T>& operator=( const BinarySearchTree<T>& tree);
};

// ����������� �� ���������
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
	size = 0;
}

// ����������� � �����������
template <typename T>
BinarySearchTree<T>::BinarySearchTree(TreeNode<T>* tree)
{
	root = copyTree(tree);
	size = countNode(root);
}

// ����������� �����������
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree) 
{
	// ���� ��������  �� ������
	if (tree.root != nullptr) {
		root = copyTree(tree.root);
		size = tree.size;
	}
}


// ����������� ������������ � �����������
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (const BinarySearchTree<T>& tree)
{
	// ������ ���������� � ���� ����
	if (this == &tree) return *this;
	
	// �������� ������� ������
	Clear();

	// ����������� ������ ������
	this->root = copyTree(tree.root);
	this->size = tree.size;
	
	
	// ���������� ������ �� ������� ������
	return *this;
}

// ������� ����
template <typename T>
void BinarySearchTree<T>::Insert(const T& item) {
	root = InsertNode(root, item);
	size++;
}

// �������� ����
template <typename T>
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
template <typename T>
bool BinarySearchTree<T>::Empty() const {
	return (root == nullptr);
}

// ���������� ����� � ������
template <typename T>
size_t BinarySearchTree<T>::Size() const {
	return size;
}



