//@author: Natalya Arsentyeva

#pragma once

// Шаблонный клас узел бинарного дерева
template <typename T>
struct  TreeNode
{
	T data;						 // данные
	TreeNode* left, * right;	 // потомки


	TreeNode();						// конструктор без параметров
	TreeNode(T data1, TreeNode<T>* left1 = nullptr, TreeNode<T>* right1 = nullptr); // с параметрами по умолчанию
};

// конструктор без параметров
template<typename T>
// inline используется для запроса у компилятора обработки вашей функции как встраиваемой функции. 
// Когда компилятор компилирует ваш код, все встраиваемые (inline) функции разворачиваются на месте, 
//то есть вызов функции заменяется копией содержимого самой функции, что устраняет накладные расходы на вызов функции! 
inline TreeNode<T>::TreeNode()
{
	this->left = nullptr;
	this->right = nullptr;
}

// конструктор с параметров
template<typename T>
inline TreeNode<T>::TreeNode(T data1, TreeNode<T>* left1, TreeNode<T>* right1)
{
	this->left = left1;		// this представляет указатель на текущий объект данного класса
	this->right = right1;
	this->data = data1;
};