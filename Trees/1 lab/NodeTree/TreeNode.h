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


/// ������� ��� ��������� ������


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

// LRN vector
template<typename T>
void createVectorLRN(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLRN(root->Left(), array);
		createVectorLRN(root->Right(), array);
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
size_t countNode(TreeNode<T>* node)   // todo size t
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
void BFS(TreeNode<T>* root)							// todo ����� �������?
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

// ����������� ������
template <typename T>
TreeNode<T>* copyTree(TreeNode<T>* oldTree) {

	TreeNode<T>* newleft, * newright, * newroot;

	// ���������� ����������� ����������� ��� ���������� ������� ������
	if (oldTree == nullptr)
		return nullptr;

	// CopyTree ������ ����� ������ � �������� ����������� ����� ����������� ������, � ������
	// ���� ����� ������ ������� CopyTree ��������� ������� ������ �������, ���� ��
	// ����, ��������� ��� �����, � ��������� ������ ������������ nullprt
	if (oldTree->Left() != nullptr)
		newleft = copyTree(oldTree->Left());
	else
		newleft = nullptr;

	// �������� ������� �������
	if (oldTree->Right() != nullptr)
		newright = copyTree(oldTree->Right());
	else
		newright = nullptr;

	// ���������� ������ ������ ����� �����
	newroot = new TreeNode<T>(oldTree->Data(), newleft, newright);

	return newroot;
}


//// ������� ���������� � �������
//template <typename T>
//void printSqr(TreeNode<T>*& root) {
//	if (root != nullptr) {
//		setData() 
//	}
//}



/// �������� ������ ������


// ���������� ������������ ���� � ���������
template <typename T>
TreeNode<T>* findMin(TreeNode<T>* root)
{
	while (root->Left() != nullptr) {
		root = root->Left();
	}
	return root;
}


// ���������� ���������� �����������
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

	// ������� ������ (������ ������)
	if (root == nullptr) {
		succ = nullptr;
	}

	// ���� ������ ����, ��� �������� ����� ����� ��������� ����������
	else if (root->Data() == key)
	{
		// ���� ���� ������ �������
		if (root->Right() != nullptr) {
			// ������� ����� ����� ���� �� ������� �������
			succ = findMin(root->Right());
		}
	}

	// ����� ������� ���� � ����� ��� ������ ���������
	else if (key < root->Data())
	{
		succ = root;
		Successor(root->Left(), succ, key);
	}
	else { // key > root->Data()  
		Successor(root->Right(), succ, key);
	}
}










//// ����� ���� �� ��������
//template <typename T>
//void SearchNode(TreeNode<T>* root, const T key) {
//	TreeNode<T>* current = root;
//	if (current->Data() == key) {
//		cout << "������";
//	}
//	else if (current->Data() < key) {
//		current = current->Right();
//
//	}
//}














// �������� �������� ���� �� ��������� ������ ������
//template <typename T>
//TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {
//
//	// ������� ������
//	if (root == nullptr) {
//		return root;
//	}
//
//	// ����������� ����� �������, ���� �� ����� ������ ����, ������� ����� �������
//	if (root->Data() > value) {
//		root->SetLeft(DeleteNode(root->Left(), value));
//		return root;
//	}
//	else if (root->Data() < value) {
//		root->SetRight(DeleteNode(root->Right(), value));
//		return root;
//	}
//
//	// ����� ������ ���� �� ��������
//
//	// ������ 1 � 2. ���� ���� ������ 1 ������� ��� ������� ���������� ���� (0 ��������)
//	// ���� ��� ������ �������, �� ������ ����������� �� ����� ���������� ����
//	if (root->Left() == nullptr) {
//		TreeNode<T>* temp = root->Right();
//		delete root;
//		return temp;
//	}
//	// ���� ��� ������� �������, �� ����� ����������� �� ����� ���������� ����
//	else if (root->Right() == nullptr) {
//		TreeNode<T>* temp = root->Left();
//		delete root;
//		return temp;
//	}
//
//	// ������ 3. ���� ���� ��� �������
//	else {
//
//		// ����, ������� �������� ��������� ���������� �����������
//		TreeNode<T>* succParent = root;
//
//		// ������� ��������� ���������� (����� ����� ���� � ������ ���������) � ��� ��������
//		TreeNode<T>* succ = root->Right();
//		while (succ->Left() != nullptr) {
//			succParent = succ;
//			succ = succ->Left();
//		}
//
//
//		// ������ �������� � ������ �������� ���� ������ � ������ ��������
//		// ������� ������� ���������� ����������� ������ ����� �������� ��������
//		// ���������� �����������
//
//		if (succParent != root)
//			succParent->SetLeft(succ->Right());
//		else
//			// ���� ������ �� ������ ��������� �� ����
//			succParent->SetRight(succ->Right());
//
//
//		// ������ �� ���������� ����������� ����������� �� ����� ���������� ����
//		root->SetData(succ->Data());
//
//		// ������� ��������� ����������
//		delete succ;
//		return root;
//	}
//}
//
//// �������� ����������� ��������� ������ ������
//// ���������� ��������� �� ������ ������ ������
//template <typename T>
//TreeNode<T>* CopyTree(TreeNode<T>* t) {
//
//	// ���������� newnode ��������� �� ����� ����, 
//	// �������������� � ����������
//	// � ������ ������, ��������� newlptr � newrptr �������� �������
//	// ������ ���� � ���������� � �������� ���������� ��� �������� ����
//	TreeNode<T>* newlptr, * newrptr, * newnode;
//	// ���������� ����������� ����������� ��� ���������� ������� ������
//	if (t == nullptr)
//		return nullptr;
//
//	// CopyTree ������ ����� ������ � �������� ����������� ����� ������ t. � ������
//	// ���� ����� ������ ������� CopyTree ��������� ������� ������ ����, ���� ��
//	// ����, ��������� ��� �����, � ��������� ������ ������������ NULL. CopyTree
//	// ������� ����� ���� � ������� GetTreeNode � ����������� � ���� ����� �������.
//	if (t->Left() != nullptr)
//		newlptr = CopyTree(t->Left());
//	else
//		newlptr = nullptr;
//	if (t->Right() != nullptr)
//		newrptr = CopyTree(t->Right());
//	else
//		newrptr = nullptr;
//
//	// ��������� ����� ������ ����� �����, ������� ��������
//	// ���� �������, � ����� �� ��������
//	newnode = new TreeNode<T>(t->Data(), newlptr, newrptr);
//
//	// ������� ��������� �� ����� ��������� ������
//	return newnode;
//
//}

//// ����� ���� �� ��������
//// ���������� �������, �� ������� ��� ������ ����
//// ���� -1, ���� ���� � ������� ��������� ���
//template <typename T>
//int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
//	// ���� ����� �� nullptr, �� �������� �������� � ������ ���
//	if (root == nullptr) {
//		return -1;
//	}
//
//	// ����� � ������ ���������
//	if (key > root->Data()) {
//		SearchNode(root->Right(), key, depth + 1);
//	}
//
//	// ����� � ����� ���������
//	else if (key < root->Data()) {
//		SearchNode(root->Left(), key, depth + 1);
//	}
//
//	// ���� key ����� �������� � ������� ����
//	else return depth;
//}
//
//// �������� ������� ���� � �������� ������ ������
//template <typename T>
//TreeNode<T>* InsertNode(TreeNode<T>* root, const T value) {
//
//	if (root == nullptr) {
//
//		// ���� ������ ������, �� ������ ������ (������ ����)
//		return new TreeNode<T>(value);
//	}
//
//	// ��������� ������ ���� � �����, ���� � ������ ���������
//	if (value > root->Data()) {
//		// ���� ��������, ������� ����� ��������, ������ ��������
//		root->SetRight(InsertNode(root->Right(), value));
//	}
//	else if (value < root->Data()) {
//		// ���� ��������, ������� ����� ��������, ������ ��������
//		root->SetLeft(InsertNode(root->Left(), value));
//	}
//
//	//���������� ������ ������
//	return root;
//}
