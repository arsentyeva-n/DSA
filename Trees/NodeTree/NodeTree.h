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
//template<typename T>
//void squareTree(TreeNode<T>* root) {
//	// ���� ������ �� ������
//	if (root != nullptr) {
//		// ��������� � ������� ������� ����, ������ ������� preorder (NLR)
//		root->setData(root->Data() * root->Data());
//		// ��������� ������ ���������
//		squareTree(root->Left());		
//		// ��������� ������� ���������
//		squareTree(root->Right());		
//	}
//}
//
//// ������� ��������� �� 3
//template<typename T>
//void calcTree(TreeNode<T>* root) {
//	// ���� ������ �� ������
//	if (root != nullptr) {
//		// �������� �� 3, ������ ������� preorder (NLR)
//		root->setData(root->Data() * 3);
//		// ��������� ������ ���������
//		calcTree(root->Left());
//		// ��������� ������� ���������
//		calcTree(root->Right());
//	}
//}

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

	return  left_count + right_count + 1;
}


// ������, ��������� ����� � ������ (����� �� �������)
template <typename T>
void BFS(TreeNode<T>* root)							// todo ����� �������?
{
	cout << endl;
	// ���� ������ �� ������
	if (root != nullptr) {
		// ������� �������
		queue <TreeNode<T>*> q;
		// ��������� ������ � �������
		q.push(root);

		// ���� ������� �� ������
		while (!q.empty()) {
			// ���������� ��������� �� ������ ������
			size_t levelSize = q.size();

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

// ������, ��������� ����� � ������� ������
//template <typename T>
//void BFS(TreeNode<T>* root)							
//{
//	cout << endl;
//	// ���� ������ �� ������
//	if (root != nullptr) {
//		// ������� �������
//		queue <TreeNode<T>*> q;
//		// ��������� ������ � �������
//		q.push(root);
//
//		// ���� ������� �� ������
//		while (!q.empty()) {
//			// ���������� ��������� �� ������ ������
//			size_t levelSize = q.size();
//
//			for (int i = 0; i < levelSize; i++) {
//				// ��������� ������ ������� �� ������� � ������� ���
//				TreeNode<T>* node = q.front();
//				cout << node->Data() << " ";
//				q.pop(); // ������� ������� ���� � ��������� � ���������
//
//				// ��������� � ������� ������ � ������� ������� (���� ����������)
//				if (node->Left() != nullptr)
//					q.push(node->Left());
//				if (node->Right() != nullptr)
//					q.push(node->Right());
//			}
//			cout << endl;
//		}
//	}
//}


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

	// �������� ������ ���� �� �������������� �������:
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
int SearchNode(TreeNode<T>* root, const T& key) {
	// �������� �� ������ ������
	if (root == nullptr) {
		cout << "�������� �� �������!" << endl;
		return -1;
	}

	// ��������� �������� � ������� ����
	if (root->Data() == key) {
		cout << "�������� �������!" << endl;
		return 0;
	}

	int depth;
	// ����� � ����� ���������
	if (key < root->Data()) {
		depth = SearchNode(root->Left(), key);
	}
	// ����� � ������ ���������
	else {
		depth = SearchNode(root->Right(), key);
	}

	// ���� ���� �� ������ � ��������� (depth == -1), ���������� -1
	if (depth == -1) {
		return -1;
	}

	// ����������� ������� �� 1, ��� ��� ���������� �� ���� �������
	return depth + 1;
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
	if (root == nullptr)
		return nullptr;

	while (root->Left() != nullptr) {
		root = root->Left();
	}
	return root;
}

// ���������� ���������� �����������
// O(n) � ��� �� ����������������� ������
// O(log2n) � ��� ����������������� ������
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
	return successor;
}

// ������������ �����(��������������� �������), ��������� ����� ����������� ����������
template <typename T>
void inOrderSort(TreeNode<T>* root) {
	// ������� ������
	if (root == nullptr) { return nullptr; }

	// ������� ����� ����� ���� (����������� �������)
	TreeNode<T>* current = findMin(root);

	// ��������������� ��������� � ���������� �����������
	while (current != nullptr) {
		cout << current->Data() << " ";
		current = Successor(root, current->Data());
	}
	cout << endl;
}


// O(n) � ��� ������������������� ������
// O(log2n) � ��� ����������������� ������
// �������� ���� �� ��������� ������ ������
template <typename T>
TreeNode<T>* removeNode(TreeNode<T>* root, const T value) {

	// ������� ������, ������ ������ ��� ���� �� ������
	if (root == nullptr) {
		return nullptr;
	}

	// ����� ���� ��������� 
	if (root->Data() > value) {								// ����� � ����� ���������
		root->setLeft(removeNode(root->Left(), value));
	}
	else if (root->Data() < value) {						// ����� � ������ ���������
		root->setRight(removeNode(root->Right(), value));
	}

	else { // ���� ������, root->Data() == value, 

		// 1 ������. ��� �������� �����
		if (root->Left() == nullptr && root->Right() == nullptr) {
			delete root;						// ����������� ������
			return nullptr;						// ���������� ������ ����
		}

		// 2 ������. ���� �������� ����

		if (root->Left() == nullptr) {			// ��� ������ ����
			TreeNode<T>* temp = root->Right();	// ��������� ��������� �� ������ ���������
			delete root;						// ����������� ������
			return temp;						// ���������� ������ ���������
		}
		if (root->Right() == nullptr) {			// ��� ������� ����
			TreeNode<T>* temp = root->Left();   // ��������� ��������� �� ����� ���������
			delete root;						// ����������� ������
			return temp;						// ���������� ����� ���������				
		}
		// 3 ������. ��� �������
		TreeNode<T>* minNode = findMin(root->Right());					// ������ �������� � ������ ������� �������� � ������ ���������
		root->setData(minNode->Data());									// ������ �������� ���������� ���� �� �������� ������� ��������
		root->setRight(removeNode(root->Right(), minNode->Data()));		// ������� ������ ������� � ������ ���������
	}

	// ���������� ���������
	return root;

}