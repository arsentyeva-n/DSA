//@author: Natalya Arsentyeva


#pragma once
#include "TreeNode.h"


///  Бинарное дерево поиска

template <typename T>
class BinarySearchTree
{
	private:
		// Указатели на корень и на текущий узел
		TreeNode<T>* root;
		TreeNode<T>* current;

		// Число элементов дерева 
		int size;


	public:
		// Конструктор по умолчанию
		BinarySearchTree();

		// Конструктор с параметром
		BinarySearchTree(TreeNode<T>* tree);

		// Деструктор
		~BinarySearchTree() { deleteTree(this->root); };

		TreeNode<T>*

};


