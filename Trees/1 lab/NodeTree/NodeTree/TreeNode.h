//@author: Natalya Arsentyeva


#pragma once
#include <iostream>
#include <vector>
using namespace std;

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
void deleteTree(TreeNode<T>* root)
{
	if (root==nullptr) return;
	deleteTree(root->Left());
	deleteTree(root->Right());
	delete root;
}

// ������ �����(NLR)
template<typename T>
void printNLR(TreeNode<T>* root) {
	if (root != nullptr) {
		cout << root->Data() << " ";	//���������� ���� ������ �������� ����).
		printNLR(root->Left());			//������� ����� ��������� ����������, ������ ������� ������� ������.
		printNLR(root->Right());		//������� ������ ��������� ����������, ������ ������� ������� ������.
	}
}

// ������������ �����(LNR)
template<typename T>
void printLNR(TreeNode<T>* root) {
	if (root != nullptr) {
		printLNR(root->Left());			//������� ����� ��������� ����������, ������ ������� ��������������� ������.
		cout << root->Data() << " ";			//���������� ���� ������ �������� ����).
		printLNR(root->Right());		//������� ������ ��������� ����������, ������ ������� ��������������� ������.
	}
}

// �������� �����(LRN)
template<typename T>
void printLRN(TreeNode<T>* root) {
	if (root != nullptr) {
		printLRN(root->Left());			//������� ����� ��������� ����������, ������ ������� ��������� ������.
		printLRN(root->Right());		//������� ������ ��������� ����������, ������ ������� ��������� ������.
		cout << root->Data() << " ";			//���������� ���� ������ �������� ����).
	}
}

// ���������� ���� � ������
template<typename T>
void createVectorNLR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		array.push_back(root->Data());
		createVectorNLR(root->Left(), array);
		createVectorNLR(root->Right(), array);
	}
}

// ����� �������� �������
template<typename T>
void printVector(vector<T>& array) {
	for (const auto& element : array) {
		cout << element << " ";
	}
	cout << endl;
}