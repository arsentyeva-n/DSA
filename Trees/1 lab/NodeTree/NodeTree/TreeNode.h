//@author: Natalya Arsentyeva


#pragma once
#include <iostream>
#include <vector>
#include <queue>
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
TreeNode<T>* deleteTree(TreeNode<T>* root)
{
	if (root != nullptr) { 
	
	// ������� � ������� LRN
	deleteTree(root->Left());
	deleteTree(root->Right());
	delete root;
	}
	return nullptr;
}

// ��� ������: O(n), ��� n - ���������� �����
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

// NLR vector
template<typename T>
void createVectorNLR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		array.push_back(root->Data());
		createVectorNLR(root->Left(), array);
		createVectorNLR(root->Right(), array);
	}
}

// LNR vector
template<typename T>
void createVectorLNR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLNR(root->Left(), array);
		array.push_back(root->Data());
		createVectorLNR(root->Right(), array);
	}
}

// LNR vector
template<typename T>
void createVectorLRN(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLNR(root->Left(), array);
		createVectorLNR(root->Right(), array);
		array.push_back(root->Data());
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

// ����� ������������ �������  O(n) - �������� ������ ���� ���� ���
template<typename T>
int findDepth(TreeNode<T>* root)
{	
	// ���� ������ ������
	if (root == nullptr) {
		return -1;
	}

	// ����� ������������ ������� ������ ���������
	int leftDepth = findDepth(root->Left());

	// ����� ������������ ������� ������� ���������
	int rightDepth = findDepth(root->Right());

	// ������������ ��������� + ��� ������
	return max(leftDepth, rightDepth) + 1; 
}

// ������� �����  O(n) - �������� ������ ���� ���� ���
template<typename T>
int countNode(TreeNode<T>* node)
{
	// ������� ������
	if (node == nullptr) {
		return 0;
	}
	// ���������� ������� ���� � ����� ���������
	int left_count = countNode(node->Left());

	// ����� ������������ ������� ������� ���������
	int right_count = countNode(node->Right());

	return  left_count  + right_count + 1;
}

// ������, ��������� ����� � ������
template <typename T>
void BFS(TreeNode<T>* root)
{
	// ���� ������ �� ������
	if (root != nullptr) {
		queue <TreeNode<T>*> q;
		// ��������� ������ � �������
		q.push(root);

		// ���� ������� �� ������
		while (!q.empty()) {
			// ��������� ������ ������� �� ������� � ������� ���
			TreeNode<T>* node = q.front();
			cout << node->Data() << " ";
			q.pop(); // ������� ������ ������� �� �������

			// ��������� � ������� ������ � ������� ������� (���� ����������)
			if (node->Left() != nullptr)
				q.push(node->Left());
			if (node->Right() != nullptr)
				q.push(node->Right());
		}
	}
}

