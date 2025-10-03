//@author: Natalya Arsentyeva


#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Шаблонный класс узла бинарного дерева
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


/// Функции для бинарного дерева


// Рекурсивное удаление узлов дерева снизу вверх
template <typename T>
TreeNode<T>* deleteTree(TreeNode<T>* root)
{
	if (root != nullptr) {

		// Удаляем в порядке postorder
		deleteTree(root->Left());	// левое поддерево
		deleteTree(root->Right());	// правое поддерево	
		delete root;				// удаляем корень
	}
	return nullptr;
}

// Все обходы (DFS, обходы в глубину): O(n), где n - количество узлов

// Прямой обход(preoder)
template<typename T>
void printNLR(TreeNode<T>* root) {
	if (root != nullptr) {
		cout << root->Data() << " ";	//Показываем поле данные текущего узла.
		printNLR(root->Left());			//Обходим левое поддерево рекурсивно, вызвав функцию прямого обхода.
		printNLR(root->Right());		//Обходим правое поддерево рекурсивно, вызвав функцию прямого обхода.
	}
}

// Симметричный обход(inorder) 
template<typename T>
void printLNR(TreeNode<T>* root) {
	if (root != nullptr) {
		printLNR(root->Left());			//Обходим левое поддерево рекурсивно, вызвав функцию центрированного обхода.
		cout << root->Data() << " ";	//Показываем поле данные текущего узла.
		printLNR(root->Right());		//Обходим правое поддерево рекурсивно, вызвав функцию центрированного обхода.
	}
}

// Обратный обход(postorder)
template<typename T>
void printLRN(TreeNode<T>* root) {
	if (root != nullptr) {
		printLRN(root->Left());			//Обходим левое поддерево рекурсивно, вызвав функцию обратного обхода.
		printLRN(root->Right());		//Обходим правое поддерево рекурсивно, вызвав функцию обратного обхода.
		cout << root->Data() << " ";	//Показываем поле данные текущего узла.
	}
}

// Заполнение векторов с помощью разных обходов
// вектор передается по ссылке
// Добавление в вектор прямым порядком
template<typename T>
void createVectorNLR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		array.push_back(root->Data());				// добавление в вектор данных, текущего узла
		createVectorNLR(root->Left(), array);
		createVectorNLR(root->Right(), array);
	}
}

// Добавление в вектор симметричным порядком
template<typename T>
void createVectorLNR(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLNR(root->Left(), array);
		array.push_back(root->Data());
		createVectorLNR(root->Right(), array);
	}
}

// Добавление в вектор обратным порядком
template<typename T>
void createVectorLRN(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLRN(root->Left(), array);
		createVectorLRN(root->Right(), array);
		array.push_back(root->Data());
	}
}

// Вывод массива данных
template<typename T>
void printVector(vector<T>& array) {
	for (const auto& element : array) {
		cout << element << " ";
	}
	cout << endl;
}

// Функция возведения в квадрат каждого узла дерева
//template<typename T>
//void squareTree(TreeNode<T>* root) {
//	// Если дерево не пустое
//	if (root != nullptr) {
//		// Вовзводим в квадрат текущий узел, проход методом preorder (NLR)
//		root->setData(root->Data() * root->Data());
//		// Обработка левого поддерева
//		squareTree(root->Left());		
//		// Обработка правого поддерева
//		squareTree(root->Right());		
//	}
//}
//
//// Функция умножения на 3
//template<typename T>
//void calcTree(TreeNode<T>* root) {
//	// Если дерево не пустое
//	if (root != nullptr) {
//		// Умножаем на 3, проход методом preorder (NLR)
//		root->setData(root->Data() * 3);
//		// Обработка левого поддерева
//		calcTree(root->Left());
//		// Обработка правого поддерева
//		calcTree(root->Right());
//	}
//}

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
size_t countNode(TreeNode<T>* node)
{
	// Базовый случай
	if (node == nullptr) {
		return 0;
	}
	// Рекурсивно считаем узлы в левом поддереве
	size_t left_count = countNode(node->Left());

	// Найти максимальную глубину правого поддерева
	size_t right_count = countNode(node->Right());

	return  left_count + right_count + 1;
}


// Печать, используя обход в ширину (поиск по уровням)
template <typename T>
void BFS(TreeNode<T>* root)							// todo зачем очередь?
{
	cout << endl;
	// Если дерево не пустое
	if (root != nullptr) {
		// создаем очередь
		queue <TreeNode<T>*> q;
		// Сохраняем корень в очередь
		q.push(root);

		// Пока очередь не пустая
		while (!q.empty()) {
			// количество элементов на данном уровне
			size_t levelSize = q.size();

			for (int i = 0; i < levelSize; i++) {
				// Извлекаем первый элемент из очереди и выводим его
				TreeNode<T>* node = q.front();
				cout << node->Data() << " ";
				q.pop(); // Удаляем текущий узел и переходим к следующим

				// Добавляем в очередь левого и правого потомка (если существуют)
				if (node->Left() != nullptr)
					q.push(node->Left());
				if (node->Right() != nullptr)
					q.push(node->Right());
			}
			cout << endl;
		}
	}
}

// Печать, используя обход в глубину СТЭКОМ
//template <typename T>
//void BFS(TreeNode<T>* root)							
//{
//	cout << endl;
//	// Если дерево не пустое
//	if (root != nullptr) {
//		// создаем очередь
//		queue <TreeNode<T>*> q;
//		// Сохраняем корень в очередь
//		q.push(root);
//
//		// Пока очередь не пустая
//		while (!q.empty()) {
//			// количество элементов на данном уровне
//			size_t levelSize = q.size();
//
//			for (int i = 0; i < levelSize; i++) {
//				// Извлекаем первый элемент из очереди и выводим его
//				TreeNode<T>* node = q.front();
//				cout << node->Data() << " ";
//				q.pop(); // Удаляем текущий узел и переходим к следующим
//
//				// Добавляем в очередь левого и правого потомка (если существуют)
//				if (node->Left() != nullptr)
//					q.push(node->Left());
//				if (node->Right() != nullptr)
//					q.push(node->Right());
//			}
//			cout << endl;
//		}
//	}
//}


// Глубокое копирование дерева обратным обходом рекурсивно
// глубокое, потому что создаются новые узлы, а не копируются
template <typename T>
TreeNode<T>* copyTree(TreeNode<T>* oldTree) {

	// Объявляем указатели для новых узлов
	TreeNode<T>* newleft, * newright, * newroot;

	// Базовый случай рекурсии: если исходное дерево пустое
	if (oldTree == nullptr) return nullptr;

	// Рекурсивное копирование ЛЕВОГО поддерева, если в исходном дереве есть левый потомок
	if (oldTree->Left() != nullptr)
		// Рекурсивно копируем всё левое поддерево
		newleft = copyTree(oldTree->Left());
	else
		// Если левого потомка нет - сохраняем nullptr
		newleft = nullptr;

	// Рекурсивное копирование ПРАВОГО поддерева, если в исходном дереве есть правый потомок  
	if (oldTree->Right() != nullptr)
		// Рекурсивно копируем всё правое поддерево
		newright = copyTree(oldTree->Right());
	else
		// Если правого потомка нет - сохраняем nullptr
		newright = nullptr;

	// Создание нового узла со скопированными данными:
	// oldTree->Data() - копируем значение из исходного узла
	// newleft - указатель на скопированное левое поддерево
	// newright - указатель на скопированное правое поддерево
	newroot = new TreeNode<T>(oldTree->Data(), newleft, newright);

	// Возвращаем корень нового (скопированного) поддерева
	return newroot;
}




/// Бинарное дерево поиска

// Поиск узла по значению
template <typename T>
int SearchNode(TreeNode<T>* root, const T& key) {
	// Проверка на пустое дерево
	if (root == nullptr) {
		cout << "Значение не найдено!" << endl;
		return -1;
	}

	// Проверяем значение в текущем узле
	if (root->Data() == key) {
		cout << "Значение найдено!" << endl;
		return 0;
	}

	int depth;
	// Поиск в левом поддереве
	if (key < root->Data()) {
		depth = SearchNode(root->Left(), key);
	}
	// Поиск в правом поддереве
	else {
		depth = SearchNode(root->Right(), key);
	}

	// Если узел не найден в поддереве (depth == -1), возвращаем -1
	if (depth == -1) {
		return -1;
	}

	// Увеличиваем глубину на 1, так как спустились на один уровень
	return depth + 1;
}


// Операция вставки узла в бинарное дерево поиска
template <typename T>
TreeNode<T>* InsertNode(TreeNode<T>* root, const T& key) {
	// Если узел пустой, то создаём новый узел
	if (root == nullptr) {
		return new TreeNode<T>(key);
	}
	// Если корень больше значения, вставляем в левое поддерево
	if (key < root->Data()) {
		root->setLeft(InsertNode(root->Left(), key));
	}
	// Если корень меньше значения, вставляем в правое поддерево
	else if (key > root->Data()) {
		root->setRight(InsertNode(root->Right(), key));
	}

	// Возвращаем корень дерева
	return root;
}

// Нахождение минимального узла в поддереве
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

// Нахождение ближайшего наибольшего
// O(n) — для не сбалансированного дерева
// O(log2n) — для сбалансированного дерева
template <typename T>
TreeNode<T>* Successor(TreeNode<T>* root, const T& key) {
	// Базовый случай (пустое дерево)
	if (root == nullptr) return nullptr;

	// Текущий узел и следующее наибольшее
	TreeNode<T>* current = root;
	TreeNode<T>* successor = nullptr;

	// Ищем узел с заданным элементом, пока дерево не кончилось
	while (current != nullptr) {
		if (key < current->Data()) {
			// Идем влево
			// Если мы идем влево, значит корень больше, 
			// чем искомое, значит оно может быть следующим наибольшим
			successor = current;
			current = current->Left();
		}
		else if (key > current->Data()) {
			// Идем вправо
			// Текущий узел не может быть больше, поэтому не запоминаем
			current = current->Right();
		}
		// Узел найден
		else {
			// Случай 1: есть правое поддерево
			if (current->Right() != nullptr) {
				// Находим самый левый узел от правого потомка
				return findMin(current->Right());
			}
			else {
				// Случай 2: нет правого поддерева - возвращаем сохраненное следующее наибольшее
				return successor;
			}
		}
	}
	// Если узел не найден
	return successor;
}

// Симметричный обход(отсортированный порядок), используя поиск наибольшего следующего
template <typename T>
void inOrderSort(TreeNode<T>* root) {
	// Базовый случай
	if (root == nullptr) { return nullptr; }

	// Находим самый левый узел (минимальный элемент)
	TreeNode<T>* current = findMin(root);

	// Последовательно переходим к следующему наибольшему
	while (current != nullptr) {
		cout << current->Data() << " ";
		current = Successor(root, current->Data());
	}
	cout << endl;
}


// O(n) — для несбалансированного дерева
// O(log2n) — для сбалансированного дерева
// Удаление узла из бинарного дерева поиска
template <typename T>
TreeNode<T>* removeNode(TreeNode<T>* root, const T value) {

	// Базовый случай, пустое дерево или узел не найден
	if (root == nullptr) {
		return nullptr;
	}

	// Поиск узла рекурсией 
	if (root->Data() > value) {								// Поиск в левом поддереве
		root->setLeft(removeNode(root->Left(), value));
	}
	else if (root->Data() < value) {						// Поиск в правом поддереве
		root->setRight(removeNode(root->Right(), value));
	}

	else { // Узел найден, root->Data() == value, 

		// 1 случай. Нет дочерних узлов
		if (root->Left() == nullptr && root->Right() == nullptr) {
			delete root;						// Освобождаем память
			return nullptr;						// Возвращаем пустой узел
		}

		// 2 случай. Одни дочерний узел

		if (root->Left() == nullptr) {			// Нет левого узла
			TreeNode<T>* temp = root->Right();	// Сохраняем указатель на правое поддерево
			delete root;						// Освобождаем память
			return temp;						// Возвращаем правое поддерево
		}
		if (root->Right() == nullptr) {			// Нет правого узла
			TreeNode<T>* temp = root->Left();   // Сохраняем указатель на левое поддерево
			delete root;						// Освобождаем память
			return temp;						// Возвращаем левое поддерево				
		}
		// 3 случай. Два потомка
		TreeNode<T>* minNode = findMin(root->Right());					// Задача сводится к поиску первого большего в правом поддереве
		root->setData(minNode->Data());									// Меняем значение удаляемого узла на значение первого большего
		root->setRight(removeNode(root->Right(), minNode->Data()));		// Удаляем первое большее в правом поддереве
	}

	// Возвращаем указатель
	return root;

}