//@author: Natalya Arsentyeva

#pragma once

// ��������� ���� ���� ��������� ������
template <typename T>
struct  TreeNode
{
	T data;						 // ������
	TreeNode* left, * right;	 // �������


	TreeNode();						// ����������� ��� ����������
	TreeNode(T data1, TreeNode<T>* left1 = nullptr, TreeNode<T>* right1 = nullptr); // � ����������� �� ���������
};

// ����������� ��� ����������
template<typename T>
// inline ������������ ��� ������� � ����������� ��������� ����� ������� ��� ������������ �������. 
// ����� ���������� ����������� ��� ���, ��� ������������ (inline) ������� ��������������� �� �����, 
//�� ���� ����� ������� ���������� ������ ����������� ����� �������, ��� ��������� ��������� ������� �� ����� �������! 
inline TreeNode<T>::TreeNode()
{
	this->left = nullptr;
	this->right = nullptr;
}

// ����������� � ����������
template<typename T>
inline TreeNode<T>::TreeNode(T data1, TreeNode<T>* left1, TreeNode<T>* right1)
{
	this->left = left1;		// this ������������ ��������� �� ������� ������ ������� ������
	this->right = right1;
	this->data = data1;
};