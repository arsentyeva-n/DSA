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
		BinarySearchTree(TreeNode<T>* tree);

		// ����������
		~BinarySearchTree() { deleteTree(this->root); };

		size_t Size() const;
		void Insert(const T& item);
		void Remove(const T& item);
		TreeNode<T>* get_root() const;
		void Clear();
		bool Empty() const;
		//size_t Height();
};

// ����������� �� ���������
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// ����������� � �����������
template <typename T>
BinarySearchTree<T>::BinarySearchTree(TreeNode<T>* tree)
{
	this->root = �opyTree(tree);
	this->current = nullptr;
	this->size = countNode(this->root);
}

// ������� ����
template<class T>
void BinarySearchTree<T>::Insert(const T& item) {
	this->root = InsertNode(this->root, item);
	size++;
}

// �������� ����
template<class T>
void BinarySearchTree<T>::Remove(const T& item) {
	this->root = removeNode(this->root, item);
	size--;
}

// ������� ������
template <typename T>
void BinarySearchTree<T>::Clear() {
	deleteTree(this->root);
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// ���������� ��������� �� ������
template <typename T>
TreeNode<T>* BinarySearchTree<T>::get_root() const
{
	return this->root;
}

// ��������, ������ �� ������
template<class T>
bool BinarySearchTree<T>::Empty() const {
	return (this->root == nullptr);
}

// ���������� ����� � ������
template<class T>
size_t BinarySearchTree<T>::Size() const {
	return this->size;
}




//	// ����������� �����������
//	BinSTree(const BinSTree<T>& tree);
//
//	// �������� ����������� (������������)
//	BinSTree<T>& operator= (const BinSTree<T>& rhs);
//
//	// ����������
//	~BinSTree() { deleteTree(this->root); }
//
//
//	// ����������� ������ ��������� �������
//
//	// ���������� �������, �� ������� ��������� ������� ����
//	// ���� -1, ���� ���� � ����� ��������� � ������ ���
//	int Find(const T& item) const;
//	void Insert(const T& item);
//	void Delete(const T& item);
//	void ClearList();
//
//	// ��������, ������ �� ������
//	bool ListEmpty() const;
//
//	// ���������� ����� � ������
//	int ListSize() const;
//
//	TreeNode<T>* GetRoot() const;
//};
//

//// ����������� �����������
//template <typename T>
//BinSTree<T>::BinSTree(const BinSTree<T>& tree)
//{
//	this->root = CopyTree(tree.root);
//
//	// ��������� �������� ��������� �������� ����� � ������ ������ ������
//	this->current = this->root;
//	this->size = tree.size;
//}
//
//
//// �������� ����������� (������������)
//template <class T>
//BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
//{
//	// ������ ���������� ������ � ���� ����
//	if (this == &rhs)
//		return *this;
//
//	// �������� ������� ������
//	ClearList();
//
//	// ����������� ����� ������ � ������� ������
//	this->root = CopyTree(rhs.root);
//
//	// ��������� �������� ��������� �������� ����� � ������ ������ ������
//	this->current = this->root;
//	this->size = rhs.size;
//
//	// ���������� ������ �� ������� ������
//	return *this;
//}
//


//// ����� ����
//// ���������� �������, �� ������� ��� ������ ����
//// ���� -1, ���� ���� � ������� ��������� ���
//template<class T>
//int BinSTree<T>::Find(const T& item) const {
//	return SearchNode(this->root, item);
//}


//
