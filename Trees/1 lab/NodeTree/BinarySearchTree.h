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
		size_t size;


	public:
		// Конструктор по умолчанию
		BinarySearchTree();

		// Конструктор с параметром
		BinarySearchTree(TreeNode<T>* tree, size_t size = 0);

		// Деструктор
		~BinarySearchTree() { deleteTree(this->root); };

		size_t Size() const {return size};
		TreeNode<T>* insert(TreeNode<T>* tree);
		TreeNode<T>* remove(TreeNode<T>* tree);
		TreeNode<T>* get_root(TreeNode<T>* tree) {return root};
		TreeNode<T>* clear(TreeNode<T>* tree) { return deleteTree(this->root); };
		bool empty(TreeNode<T>* tree);
		size_t height();
};


