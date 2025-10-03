//@author: Natalya Arsentyeva


#pragma once
#include "TreeNode.h"


///  Ѕинарное дерево поиска

template <typename T>
class BinarySearchTree
{
	private:
		// ”казатели на корень и на текущий узел
		TreeNode<T>* root;
		TreeNode<T>* current;

		// „исло элементов дерева 
		size_t size;


	public:
		//  онструктор по умолчанию
		BinarySearchTree();

		//  онструктор с параметром
		BinarySearchTree(TreeNode<T>* tree);

		// ƒеструктор
		~BinarySearchTree() { deleteTree(this->root); };

		size_t Size() const;
		void Insert(const T& item);
		void Remove(const T& item);
		TreeNode<T>* get_root() const;
		void Clear();
		bool Empty() const;
		//size_t Height();
};

//  онструктор по умолчанию
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

//  онструктор с параметрами
template <typename T>
BinarySearchTree<T>::BinarySearchTree(TreeNode<T>* tree)
{
	this->root = сopyTree(tree);
	this->current = nullptr;
	this->size = countNode(this->root);
}

// ¬ставка узла
template<class T>
void BinarySearchTree<T>::Insert(const T& item) {
	this->root = InsertNode(this->root, item);
	size++;
}

// ”даление узла
template<class T>
void BinarySearchTree<T>::Remove(const T& item) {
	this->root = removeNode(this->root, item);
	size--;
}

// ќчистка дерева
template <typename T>
void BinarySearchTree<T>::Clear() {
	deleteTree(this->root);
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// ¬озвращает указатель на корень
template <typename T>
TreeNode<T>* BinarySearchTree<T>::get_root() const
{
	return this->root;
}

// ѕроверка, пустое ли дерево
template<class T>
bool BinarySearchTree<T>::Empty() const {
	return (this->root == nullptr);
}

//  оличество узлов в дереве
template<class T>
size_t BinarySearchTree<T>::Size() const {
	return this->size;
}




//	// конструктор копировани€
//	BinSTree(const BinSTree<T>& tree);
//
//	// оператор копировани€ (присваивани€)
//	BinSTree<T>& operator= (const BinSTree<T>& rhs);
//
//	// деструктор
//	~BinSTree() { deleteTree(this->root); }
//
//
//	// стандартные методы обработки списков
//
//	// возвращает уровень, на котором находитс€ искомый узел
//	// либо -1, если узла с таким значением в дереве нет
//	int Find(const T& item) const;
//	void Insert(const T& item);
//	void Delete(const T& item);
//	void ClearList();
//
//	// проверка, пустое ли дерево
//	bool ListEmpty() const;
//
//	// количество узлов в дереве
//	int ListSize() const;
//
//	TreeNode<T>* GetRoot() const;
//};
//

//// конструктор копировани€
//template <typename T>
//BinSTree<T>::BinSTree(const BinSTree<T>& tree)
//{
//	this->root = CopyTree(tree.root);
//
//	// присвоить текущему указателю значение корн€ и задать размер дерева
//	this->current = this->root;
//	this->size = tree.size;
//}
//
//
//// оператор копировани€ (присваивани€)
//template <class T>
//BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
//{
//	// нельз€ копировать дерево в само себ€
//	if (this == &rhs)
//		return *this;
//
//	// очистить текущее дерево
//	ClearList();
//
//	// скопировать новое дерево в текущий объект
//	this->root = CopyTree(rhs.root);
//
//	// присвоить текущему указателю значение корн€ и задать размер дерева
//	this->current = this->root;
//	this->size = rhs.size;
//
//	// возвратить ссылку на текущий объект
//	return *this;
//}
//


//// поиск узла
//// возвращает уровень, на котором был найден узел
//// либо -1, если узла с искомым значением нет
//template<class T>
//int BinSTree<T>::Find(const T& item) const {
//	return SearchNode(this->root, item);
//}


//
