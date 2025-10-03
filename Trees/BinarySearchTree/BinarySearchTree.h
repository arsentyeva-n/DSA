//@author: Natalya Arsentyeva


#pragma once
#include "../NodeTree/NodeTree.h"


///  Бинарное дерево поиска

template <typename T>
class BinarySearchTree
{
private:
	// Указатель на корень
	TreeNode<T>* root;

	// Число элементов дерева 
	size_t size;


public:
	// Конструктор по умолчанию
	BinarySearchTree();

	//// Конструктор с параметром
	//BinarySearchTree(TreeNode<T>* tree);

	// Деструктор
	~BinarySearchTree() { deleteTree(root); };

	size_t Size() const;
	void Insert(const T& item);
	void Remove(const T& item);
	TreeNode<T>* get_root() const;
	void Clear();
	bool Empty() const;
};

// Конструктор по умолчанию
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
	size = 0;
}

// Конструктор с параметрами
//template <typename T>
//BinarySearchTree<T>::BinarySearchTree(TreeNode<T>* tree)
//{
//	root = сopyTree(tree);
//	size = countNode(this->root);
//}

// Вставка узла
template<class T>
void BinarySearchTree<T>::Insert(const T& item) {
	root = InsertNode(root, item);
	size++;
}

// Удаление узла
template<class T>
void BinarySearchTree<T>::Remove(const T& item) {
	root = removeNode(root, item);
	size--;
}

// Очистка дерева
template <typename T>
void BinarySearchTree<T>::Clear() {
	deleteTree(this->root);
	root = nullptr;
	size = 0;
}

// Возвращает указатель на корень
template <typename T>
TreeNode<T>* BinarySearchTree<T>::get_root() const
{
	return root;
}

// Проверка, пустое ли дерево
template<class T>
bool BinarySearchTree<T>::Empty() const {
	return (root == nullptr);
}

// Количество узлов в дереве
template<class T>
size_t BinarySearchTree<T>::Size() const {
	return size;
}



