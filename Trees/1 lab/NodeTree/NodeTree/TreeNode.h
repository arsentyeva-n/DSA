//@author: Natalya Arsentyeva


#pragma once
#include <iostream>


// ���� ��������� ������
template <typename T>
class TreeNode
{
private:
	// ��� ������
	T data;					
	// ��������� ������ � ������� �����
	TreeNode<T>* left;			
	TreeNode<T>* right;

public:
	// ����������� ��� ����������
	TreeNode() = default;			

	// C ����������� �� ���������
	// (�������� ��� �� ������ const T&, �� ���� ��� �����������
	// const �����������, ��� ������ ������������ �������� ������ ��������)
	TreeNode(const T& data1, TreeNode<T>* left1 = nullptr, TreeNode<T>* right1 = nullptr); 

	//������ ������� (�������)
	T Data() const;
	TreeNode<T>* Left() const;
	TreeNode<T>* Right() const;

	// ������ ��������� (�������)
	void setData(const T& data1);
	void setLeft(TreeNode<T>* left1);
	void setRight(TreeNode<T>* right1);
};

// ����������� �������������� ���� ������ � ����������
// (�������� nullptr ������������� ������� ���������)
template <typename T>
TreeNode<T>::TreeNode(const T& data1, TreeNode<T>* left1, TreeNode<T>* right1)
{
	data = data1;
	left = left1;
	right = right1;
}

// ����� Data ���������� �������� ���� ������
template <typename T>
T TreeNode<T>::Data() const
{
	return this->data;
}

// ������ Left � Right ���������� �������� ����� ������ � ������� ����������
template <typename T>
TreeNode<T>* TreeNode<T>::Left() const 
{
	return this->left;
}

template <typename T>
TreeNode<T>* TreeNode<T>::Right() const
{
	return this->right;
}

// ����� ������� �������� ���� ������
template <typename T>
void TreeNode<T>::setData(const T& data1) {
	this->data = data1;
}

// ����� ������� ������ �������
template <typename T>
void TreeNode<T>::setLeft(TreeNode<T>* left1)
{
	this->left = left1;
}

// ����� ������� ������� �������
template <typename T>
void TreeNode<T>::setRight(TreeNode<T>* right1)
{
	right = right1;
}

// ����������� �������� ����� ������
template <typename T>
void deleteTree(TreeNode<T>* node)
{
	if (node==nullptr) return;
	deleteTree(node->Left());
	deleteTree(node->Right());
	delete node;
}
