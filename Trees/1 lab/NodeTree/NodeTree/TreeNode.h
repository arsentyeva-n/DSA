//@author: Natalya Arsentyeva


#pragma once
#include <iostream>
#include <vector>
#include <queue>
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
TreeNode<T>* deleteTree(TreeNode<T>* root)
{
	if (root != nullptr) { 
	
	// Удаляем в порядке LRN
	deleteTree(root->Left());
	deleteTree(root->Right());
	delete root;
	}
	return nullptr;
}

// Все обходы: O(n), где n - количество узлов
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

// LNR vector
template<typename T>
void createVectorLRN(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLNR(root->Left(), array);
		createVectorLNR(root->Right(), array);
		array.push_back(root->Data());
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

// Поиск максимальной глубины  O(n) - посещаем каждый узел один раз
template<typename T>
int findDepth(TreeNode<T>* root)
{	
	// Если дерево пустое
	if (root == nullptr) {
		return -1;
	}

	// Найти максимальную глубину левого поддерева
	int leftDepth = findDepth(root->Left());

	// Найти максимальную глубину правого поддерева
	int rightDepth = findDepth(root->Right());

	// Максимальное поддерево + сам корень
	return max(leftDepth, rightDepth) + 1; 
}

// Подсчёт узлов  O(n) - посещаем каждый узел один раз
template<typename T>
int countNode(TreeNode<T>* node)
{
	// Базовый случай
	if (node == nullptr) {
		return 0;
	}
	// Рекурсивно считаем узлы в левом поддереве
	int left_count = countNode(node->Left());

	// Найти максимальную глубину правого поддерева
	int right_count = countNode(node->Right());

	return  left_count  + right_count + 1;
}

// Печать, используя обход в ширину
template <typename T>
void BFS(TreeNode<T>* root)
{
	// Если дерево не пустое
	if (root != nullptr) {
		queue <TreeNode<T>*> q;
		// Сохраняем корень в очередь
		q.push(root);

		// Пока очередь не пустая
		while (!q.empty()) {
			// Извлекаем первый элемент из очереди и выводим его
			TreeNode<T>* node = q.front();
			cout << node->Data() << " ";
			q.pop(); // Удаляем первый элемент из очереди

			// Добавляем в очередь левого и правого потомка (если существуют)
			if (node->Left() != nullptr)
				q.push(node->Left());
			if (node->Right() != nullptr)
				q.push(node->Right());
		}
	}
}

