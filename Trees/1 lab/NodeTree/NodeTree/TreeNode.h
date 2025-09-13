//@author: Natalya Arsentyeva


#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Узел бинарного дерева
template <typename T>
class TreeNode
{
private:
	// Тип данных
	T data;					
	// Указатели левого и правого узлов
	TreeNode<T>* left;			
	TreeNode<T>* right;

public:
	// Конструктор без параметров
	TreeNode() = default;			

	// C параметрами по умолчанию
	// (передача идёт по ссылке const T&, то есть без копирования
	// const гарантирует, что внутри конструктора аргумент нельзя изменить)
	TreeNode(const T& data1, TreeNode<T>* left1 = nullptr, TreeNode<T>* right1 = nullptr); 

	//Методы доступа (геттеры)
	T Data() const;
	TreeNode<T>* Left() const;
	TreeNode<T>* Right() const;

	// Методы изменения (сеттеры)
	void setData(const T& data1);
	void setLeft(TreeNode<T>* left1);
	void setRight(TreeNode<T>* right1);
};

// Конструктор инициализирует поля данных и указателей
// (значение nullptr соответствует пустому поддереву)
template <typename T>
TreeNode<T>::TreeNode(const T& data1, TreeNode<T>* left1, TreeNode<T>* right1)
{
	data = data1;
	left = left1;
	right = right1;
}

// Метод Data возвращает значение поля данных
template <typename T>
T TreeNode<T>::Data() const
{
	return this->data;
}

// Методы Left и Right возвращают значения полей левого и правого указателей
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

// Метод задания значения поля данных
template <typename T>
void TreeNode<T>::setData(const T& data1) {
	this->data = data1;
}

// Метод задания левого потомка
template <typename T>
void TreeNode<T>::setLeft(TreeNode<T>* left1)
{
	this->left = left1;
}

// Метод задания правого потомка
template <typename T>
void TreeNode<T>::setRight(TreeNode<T>* right1)
{
	right = right1;
}

// Рекурсивное удаление узлов дерева
template <typename T>
void deleteTree(TreeNode<T>* root)
{
	if (root==nullptr) return;
	deleteTree(root->Left());
	deleteTree(root->Right());
	delete root;
}

// Прямой обход(NLR)
template<typename T>
void printNLR(TreeNode<T>* root) {
	if (root != nullptr) {
		cout << root->Data() << " ";	//Показываем поле данные текущего узла).
		printNLR(root->Left());			//Обходим левое поддерево рекурсивно, вызвав функцию прямого обхода.
		printNLR(root->Right());		//Обходим правое поддерево рекурсивно, вызвав функцию прямого обхода.
	}
}

// Симметричный обход(LNR)
template<typename T>
void printLNR(TreeNode<T>* root) {
	if (root != nullptr) {
		printLNR(root->Left());			//Обходим левое поддерево рекурсивно, вызвав функцию центрированного обхода.
		cout << root->Data() << " ";			//Показываем поле данные текущего узла).
		printLNR(root->Right());		//Обходим правое поддерево рекурсивно, вызвав функцию центрированного обхода.
	}
}

// Обратный обход(LRN)
template<typename T>
void printLRN(TreeNode<T>* root) {
	if (root != nullptr) {
		printLRN(root->Left());			//Обходим левое поддерево рекурсивно, вызвав функцию обратного обхода.
		printLRN(root->Right());		//Обходим правое поддерево рекурсивно, вызвав функцию обратного обхода.
		cout << root->Data() << " ";			//Показываем поле данные текущего узла).
	}
}

// добавление узла в вектор
template<typename T>
void createVectorNLR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		array.push_back(root->Data());
		createVectorNLR(root->Left(), array);
		createVectorNLR(root->Right(), array);
	}
}

// Вывод значений вектора
template<typename T>
void printVector(vector<T>& array) {
	for (const auto& element : array) {
		cout << element << " ";
	}
	cout << endl;
}