//@author: Natalya Arsentyeva


#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ��������� ����� ���� ��������� ������
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


// ����������� �������� ����� ������ ����� �����
template <typename T>
TreeNode<T>* deleteTree(TreeNode<T>* root)
{
	if (root != nullptr) { 
	
	// ������� � ������� postorder
	deleteTree(root->Left());	// ����� ���������
	deleteTree(root->Right());	// ������ ���������	
	delete root;				// ������� ������
	}
	return nullptr;
}

// ��� ������ (DFS, ������ � �������): O(n), ��� n - ���������� �����

// ������ �����(preoder)
template<typename T>
void printNLR(TreeNode<T>* root) {
	if (root != nullptr) {
		cout << root->Data() << " ";	//���������� ���� ������ �������� ����.
		printNLR(root->Left());			//������� ����� ��������� ����������, ������ ������� ������� ������.
		printNLR(root->Right());		//������� ������ ��������� ����������, ������ ������� ������� ������.
	}
}

// ������������ �����(inorder) 
template<typename T>
void printLNR(TreeNode<T>* root) {
	if (root != nullptr) {
		printLNR(root->Left());			//������� ����� ��������� ����������, ������ ������� ��������������� ������.
		cout << root->Data() << " ";	//���������� ���� ������ �������� ����.
		printLNR(root->Right());		//������� ������ ��������� ����������, ������ ������� ��������������� ������.
	}
}

// �������� �����(postorder)
template<typename T>
void printLRN(TreeNode<T>* root) {
	if (root != nullptr) {
		printLRN(root->Left());			//������� ����� ��������� ����������, ������ ������� ��������� ������.
		printLRN(root->Right());		//������� ������ ��������� ����������, ������ ������� ��������� ������.
		cout << root->Data() << " ";	//���������� ���� ������ �������� ����.
	}
}

// ���������� �������� � ������� ������ �������
// ������ ���������� �� ������
// ���������� � ������ ������ ��������
template<typename T>
void createVectorNLR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		array.push_back(root->Data());				// ���������� � ������ ������, �������� ����
		createVectorNLR(root->Left(), array);
		createVectorNLR(root->Right(), array);
	}
}

// ���������� � ������ ������������ ��������
template<typename T>
void createVectorLNR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLNR(root->Left(), array);
		array.push_back(root->Data());
		createVectorLNR(root->Right(), array);
	}
}

// ���������� � ������ �������� ��������
template<typename T>
void createVectorLRN(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLRN(root->Left(), array);
		createVectorLRN(root->Right(), array);
		array.push_back(root->Data());
	}
}

// ����� ������� ������
template<typename T>
void printVector(vector<T>& array) {
	for (const auto& element : array) {
		cout << element << " ";
	}
	cout << endl;
}

// ������� ���������� � ������� ������� ���� ������
template<typename T>
void squareTree(TreeNode<T>* root) {
	// ���� ������ �� ������
	if (root != nullptr) {
		// ��������� � ������� ������� ����, ������ ������� preorder (NLR)
		root->setData(root->Data() * root->Data());
		// ��������� ������ ���������
		squareTree(root->Left());		
		// ��������� ������� ���������
		squareTree(root->Right());		
	}
}

// ������� ��������� �� 3
template<typename T>
void calcTree(TreeNode<T>* root) {
	// ���� ������ �� ������
	if (root != nullptr) {
		// ��������� � ������� ������� ����, ������ ������� preorder (NLR)
		root->setData(root->Data() * 3);
		// ��������� ������ ���������
		calcTree(root->Left());
		// ��������� ������� ���������
		calcTree(root->Right());
	}
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
size_t countNode(TreeNode<T>* node)   
{ 
	// ������� ������
	if (node == nullptr) {
		return 0;
	}
	// ���������� ������� ���� � ����� ���������
	size_t left_count = countNode(node->Left());

	// ����� ������������ ������� ������� ���������
	size_t right_count = countNode(node->Right());

	return  left_count  + right_count + 1;
}


// ������, ��������� ����� � ������ (����� �� �������)
template <typename T>
void BFS(TreeNode<T>* root)							// todo ����� �������?
{
	// ���� ������ �� ������
	if (root != nullptr) {
		// ������� �������
		queue <TreeNode<T>*> q;
		// ��������� ������ � �������
		q.push(root);

		// ���� ������� �� ������
		while (!q.empty()) {
			// ���������� ��������� �� ������ ������
			int levelSize = q.size();
			
			for (int i = 0; i < levelSize; i++) {
				// ��������� ������ ������� �� ������� � ������� ���
				TreeNode<T>* node = q.front();
				cout << node->Data() << " ";
				q.pop(); // ������� ������� ���� � ��������� � ���������

				// ��������� � ������� ������ � ������� ������� (���� ����������)
				if (node->Left() != nullptr)
					q.push(node->Left());
				if (node->Right() != nullptr)
					q.push(node->Right());
			}
			cout << endl;
		}
	}
}


// �������� ����������� ������ �������� ������� ����������
// ��������, ������ ��� ��������� ����� ����, � �� ����������
template <typename T>
TreeNode<T>* copyTree(TreeNode<T>* oldTree) {

	// ��������� ��������� ��� ����� �����
	TreeNode<T>* newleft, * newright, * newroot;

	// ������� ������ ��������: ���� �������� ������ ������
	if (oldTree == nullptr) return nullptr;

	// ����������� ����������� ������ ���������, ���� � �������� ������ ���� ����� �������
	if (oldTree->Left() != nullptr)
		// ���������� �������� �� ����� ���������
		newleft = copyTree(oldTree->Left());
	else
		// ���� ������ ������� ��� - ��������� nullptr
		newleft = nullptr;

	// ����������� ����������� ������� ���������, ���� � �������� ������ ���� ������ �������  
	if (oldTree->Right() != nullptr)
		// ���������� �������� �� ������ ���������
		newright = copyTree(oldTree->Right());
	else
		// ���� ������� ������� ��� - ��������� nullptr
		newright = nullptr;

	// �������� ������ ���� � �������������� �������:
	// oldTree->Data() - �������� �������� �� ��������� ����
	// newleft - ��������� �� ������������� ����� ���������
	// newright - ��������� �� ������������� ������ ���������
	newroot = new TreeNode<T>(oldTree->Data(), newleft, newright);

	// ���������� ������ ������ (��������������) ���������
	return newroot;
}




/// �������� ������ ������

// ����� ���� �� ��������
template <typename T>
void SearchNode(TreeNode<T>* root, const T& key) {
	// �������� �� ������ ������ ��� ���������� ����
	if (root == nullptr) {
		cout << "�������� �� �������!" << endl;
		return;
	}

	// ��������� �������� � ������� ����
	if (root->Data() == key) {
		cout << "�������� �������!" << endl;
		return;
	}
	// ����� � ����� ���������
	else if (key < root->Data()) {
		SearchNode(root->Left(), key);
	}
	// ����� � ������ ���������
	else {
		SearchNode(root->Right(), key);
	}
}


// �������� ������� ���� � �������� ������ ������
template <typename T>
TreeNode<T>* InsertNode(TreeNode<T>* root, const T& key) {
	// ���� ���� ������, �� ������ ����� ����
	if (root == nullptr) {
		return new TreeNode<T>(key);
	}
	// ���� ������ ������ ��������, ��������� � ����� ���������
	if (key < root->Data()) {
		root->setLeft(InsertNode(root->Left(), key));
	}
	// ���� ������ ������ ��������, ��������� � ������ ���������
	else if (key > root->Data()) {
		root->setRight(InsertNode(root->Right(), key));
	}

	// ���������� ������ ������
	return root;
}

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
// O(n) � ��� �� ����������������� ������
// O(log2n) � ��� ����������������� ������
// ���������������� ���������: O(1)
template <typename T>
TreeNode<T>* Successor(TreeNode<T>* root, const T& key) {
	// ������� ������ (������ ������)
	if (root == nullptr) return nullptr;

	// ������� ���� � ��������� ����������
	TreeNode<T>* current = root;
	TreeNode<T>* successor = nullptr;

	// ���� ���� � �������� ���������, ���� ������ �� ���������
	while (current != nullptr) {
		if (key < current->Data()) {
			// ���� �����
			// ���� �� ���� �����, ������ ������ ������, 
			// ��� �������, ������ ��� ����� ���� ��������� ����������
			successor = current;
			current = current->Left();
		}
		else if (key > current->Data()) {
			// ���� ������
			// ������� ���� �� ����� ���� ������, ������� �� ����������
			current = current->Right();
		}
		// ���� ������
		else {
			// ������ 1: ���� ������ ���������
			if (current->Right() != nullptr) {
				// ������� ����� ����� ���� �� ������� �������
				return findMin(current->Right());
			}
			else {
				// ������ 2: ��� ������� ��������� - ���������� ����������� ��������� ����������
				return successor;
			}
		}
	}
	// ���� ���� �� ������
	return nullptr;
}

// ������������ �����(��������������� �������) 
template <typename T>
void inOrderSort(TreeNode<T>* root) {
	// ������� ������
	if (root == nullptr) { return; }

	// ������� ����� ����� ���� (����������� �������)
	TreeNode<T>* current = findMin(root);

	// ��������������� ��������� � ���������� �����������
	while (current != nullptr) {
		cout << current->Data() << " ";
		current = Successor(root, current->Data());
	}
	cout << endl;
}

// �������� ����
// O(n) � ��� ������������������� ������
// O(log2n) � ��� ����������������� ������

template <typename T>
TreeNode<T>* removeNode(TreeNode<T>* root, const T key) {
	// ������� ������
	if (root == nullptr) { return root; }

	else {
		TreeNode<T>* current = root;   // ������� ����	
		TreeNode<T>* parent = nullptr; // ������ �������� �������� ����

		// ����� ���� � ������
		while (current != nullptr && current->Data() != key) {
			// ���������� ��������
			parent = current;
			if (key < current->Data()) {
				// ���� �����
				current = current->Left();
			}
			else if (key > current->Data()) {
				// ���� ������
				current = current->Right();
			}

			
		}
		// ���� �� ������
		if (current == nullptr) { return root; }
		if (parent == nullptr) {
			delete root;
			return nullptr;
		}

		// ������ 1. ��� �������� �����
		if (current->Left() == nullptr && current->Right() == nullptr) {
			// ��������� ����� ��� ������ ��������� ����
			if (parent->Left() == current) {
				// ������� ��������� �� �����
				delete parent->Left();
				parent->setLeft(nullptr);
			}
			else {
				// ������� ��������� �� ������
				delete parent->Right();
				parent->setRight(nullptr);
			}
		}
		// ������ 2. ���� �������� ����
		else if (current->Left() == nullptr || current->Right() == nullptr) {
			// ��������� ����� ��� ������ ������� ���������� ����
			TreeNode<T>* child = nullptr;
			if (current->Left() != nullptr) {
				// ���������� �������� ����
				child = current->Left();
			}
			else if (current->Right() != nullptr){
				child = current->Right();
			}
			// ��������� ����� ��� ������ ��������� ����
			if (parent->Left() == current) {
				// ������� ��������� �� �����
				delete parent->Left();
				// ������������ �������� ����
				parent->setLeft(child);
			}
			else {
				// ������� ��������� �� ������
				delete parent->Right();
				// ������������ �������� ����
				parent->setRight(child);
			}
		}
		// ������ 3. ��� �������� ����
		else {        
			// ������� ��������� ���������� 
			TreeNode<T>* succ = Successor(root, current->Data());
			if (succ != nullptr) {
				current->setData(succ->Data());
				// ������� ��������� ����������
				root = removeNode(root, succ->Data());
			}
		}
	}
	return root;
}





















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

