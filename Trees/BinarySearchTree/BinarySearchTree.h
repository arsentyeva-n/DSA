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

	// Конструктор с параметром
	BinarySearchTree(TreeNode<T>* tree);

	// Конструктор копирования
	BinarySearchTree(const BinarySearchTree<T>& tree);

	// Конструктор перемещения
	BinarySearchTree(BinarySearchTree<T>&& tree) noexcept;

	// Деструктор
	~BinarySearchTree() { deleteTree(root); };

	size_t Size() const;
	void Insert(const T& item);
	void Remove(const T& item);
	TreeNode<T>* get_root() const;
	void Clear();
	bool Empty() const;
	//find

	// Оператор присваивания копированием
	BinarySearchTree<T>& operator =(const BinarySearchTree<T>& tree);

	// Оператор присваивания перемещения
	BinarySearchTree<T>& operator =( BinarySearchTree<T>&& tree) noexcept;

};

// Конструктор по умолчанию
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
	size = 0;
}

// Конструктор с параметром
template <typename T>
BinarySearchTree<T>::BinarySearchTree(TreeNode<T>* tree)
{
	root = copyTree(tree);
	size = countNode(root);
}

// Конструктор копирования
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree)
{
	// Если параметр  не пустой
	if (tree.root != nullptr) {
		
		cout << "\nКонструктор копирования" << endl;

		root = copyTree(tree.root);
		size = tree.size;
		
	}

}

// Конструктор перемещения
template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& tree) noexcept
{
	// Если параметр  не пустой
	if (tree.root != nullptr) {
		cout << "\nКонструктор перемещения" << endl;

		// Старую память используем в новом объекте, можно использовать swap
		root = tree.root;
		size = tree.size;
		
		// Удаляем старый объект
		tree.root = nullptr;
		tree.size = 0;
	}

}

// Оператор копирования
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator = (const BinarySearchTree<T>& tree) 
{
	// Нельзя копировать в само себя
	if (this == &tree) return *this;

	cout << "\nОператор копирования" << endl;

	// Очистить текущее дерево
	Clear();

	// Копирование нового дерева
	this->root = copyTree(tree.root);
	this->size = tree.size;

	
	// Возвратить ссылку на текущий объект
	return *this;
}

// Оператор перемещения
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator = (BinarySearchTree<T>&& tree) noexcept
{
	// Нельзя копировать в само себя
	if (this == &tree) return *this;
	
	cout << "\nОператор перемещения" << endl;

	// Очистить текущее дерево
	Clear();

	// Старую память используем в новом объекте, можно использовать swap
	// Копирование нового дерева
	this->root = tree.root;
	this->size = tree.size;

	// Удаляем старый объект
	tree.root = nullptr;
	tree.size = 0;

	
	// Возвратить ссылку на текущий объект
	return *this;
}

// Вставка узла
template <typename T>
void BinarySearchTree<T>::Insert(const T& item) {
	root = InsertNode(root, item);
	size++;
}

// Удаление узла
template <typename T>
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
template <typename T>
bool BinarySearchTree<T>::Empty() const {
	return (root == nullptr);
}

// Количество узлов в дереве
template <typename T>
size_t BinarySearchTree<T>::Size() const {
	return size;
}


