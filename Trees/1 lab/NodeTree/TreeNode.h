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


/// Функции для бинарного дерева


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

// LRN vector
template<typename T>
void createVectorLRN(TreeNode<T>* root, vector<T>& array) {
	if (root != nullptr) {
		createVectorLRN(root->Left(), array);
		createVectorLRN(root->Right(), array);
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
size_t countNode(TreeNode<T>* node)   // todo size t
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
void BFS(TreeNode<T>* root)							// todo зачем очередь?
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

// Копирование дерева
template <typename T>
TreeNode<T>* copyTree(TreeNode<T>* oldTree) {

	TreeNode<T>* newleft, * newright, * newroot;

	// остановить рекурсивное прохождение при достижении пустого дерева
	if (oldTree == nullptr)
		return nullptr;

	// CopyTree строит новое дерево в процессе прохождения узлов копируемого дерева, в каждом
	// узле этого дерева функция CopyTree проверяет наличие левого потомка, если он
	// есть, создается его копия, в противном случае возвращается nullprt
	if (oldTree->Left() != nullptr)
		newleft = copyTree(oldTree->Left());
	else
		newleft = nullptr;

	// проверка правого потомка
	if (oldTree->Right() != nullptr)
		newright = copyTree(oldTree->Right());
	else
		newright = nullptr;

	// Построение нового дерева снизу вверх
	newroot = new TreeNode<T>(oldTree->Data(), newleft, newright);

	return newroot;
}


//// Функция возведения в квадрат
//template <typename T>
//void printSqr(TreeNode<T>*& root) {
//	if (root != nullptr) {
//		setData() 
//	}
//}



/// Бинарное дерево поиска


// Нахождение минимального узла в поддереве
template <typename T>
TreeNode<T>* findMin(TreeNode<T>* root)
{
	while (root->Left() != nullptr) {
		root = root->Left();
	}
	return root;
}


// Нахождение ближайшего наибольшего
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

	// Базовый случай (пустое дерево)
	if (root == nullptr) {
		succ = nullptr;
	}

	// если найден узел, для которого нужно найти ближайшее наибольшее
	else if (root->Data() == key)
	{
		// если есть правый потомок
		if (root->Right() != nullptr) {
			// находим самый левый узел от правого потомка
			succ = findMin(root->Right());
		}
	}

	// поиск нужного узла в левом или правом поддереве
	else if (key < root->Data())
	{
		succ = root;
		Successor(root->Left(), succ, key);
	}
	else { // key > root->Data()  
		Successor(root->Right(), succ, key);
	}
}










//// Поиск узла по значению
//template <typename T>
//void SearchNode(TreeNode<T>* root, const T key) {
//	TreeNode<T>* current = root;
//	if (current->Data() == key) {
//		cout << "Найден";
//	}
//	else if (current->Data() < key) {
//		current = current->Right();
//
//	}
//}














// операция удаления узла из бинарного дерева поиска
//template <typename T>
//TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {
//
//	// базовый случай
//	if (root == nullptr) {
//		return root;
//	}
//
//	// рекурсивный вызов функции, пока не будет найден узел, который нужно удалить
//	if (root->Data() > value) {
//		root->SetLeft(DeleteNode(root->Left(), value));
//		return root;
//	}
//	else if (root->Data() < value) {
//		root->SetRight(DeleteNode(root->Right(), value));
//		return root;
//	}
//
//	// Когда найден узел на удаление
//
//	// Случаи 1 и 2. если есть только 1 потомок или удалить необходимо лист (0 потомков)
//	// если нет левого потомка, то правый поднимается на место удаляемого узла
//	if (root->Left() == nullptr) {
//		TreeNode<T>* temp = root->Right();
//		delete root;
//		return temp;
//	}
//	// если нет правого потомка, то левый поднимается на место удаляемого узла
//	else if (root->Right() == nullptr) {
//		TreeNode<T>* temp = root->Left();
//		delete root;
//		return temp;
//	}
//
//	// Случай 3. если есть оба потомка
//	else {
//
//		// узел, который является родителем ближайшего наибольшего
//		TreeNode<T>* succParent = root;
//
//		// Находим ближайшее наибольшее (самый левый узел в правом поддереве) и его родителя
//		TreeNode<T>* succ = root->Right();
//		while (succ->Left() != nullptr) {
//			succParent = succ;
//			succ = succ->Left();
//		}
//
//
//		// задача сводится к случаю удаления узла только с правым потомком
//		// правого потомка ближайшего наибольшего делаем левым потомком родителя
//		// ближайшего наибольшего
//
//		if (succParent != root)
//			succParent->SetLeft(succ->Right());
//		else
//			// если спуска по левому поддереву не было
//			succParent->SetRight(succ->Right());
//
//
//		// данные из ближайшего наибольшего переносятся на место удаляемого узла
//		root->SetData(succ->Data());
//
//		// Удаляем ближайшее наибольшее
//		delete succ;
//		return root;
//	}
//}
//
//// операция копирования бинарного дерева поиска
//// возвращает указатель на корень нового дерева
//template <typename T>
//TreeNode<T>* CopyTree(TreeNode<T>* t) {
//
//	// переменная newnode указывает на новый узел, 
//	// присоединяемый в дальнейшем
//	// к новому дереву, указатели newlptr и newrptr адресуют сыновей
//	// нового узла и передаются в качестве параметров при создании узла
//	TreeNode<T>* newlptr, * newrptr, * newnode;
//	// остановить рекурсивное прохождение при достижении пустого дерева
//	if (t == nullptr)
//		return nullptr;
//
//	// CopyTree строит новое дерево в процессе прохождения узлов дерева t. в каждом
//	// узле этого дерева функция CopyTree проверяет наличие левого сына, если он
//	// есть, создается его копия, в противном случае возвращается NULL. CopyTree
//	// создает копию узла с помощью GetTreeNode и подвешивает к нему копии сыновей.
//	if (t->Left() != nullptr)
//		newlptr = CopyTree(t->Left());
//	else
//		newlptr = nullptr;
//	if (t->Right() != nullptr)
//		newrptr = CopyTree(t->Right());
//	else
//		newrptr = nullptr;
//
//	// построить новое дерево снизу вверх, сначала создавая
//	// двух сыновей, а затем их родителя
//	newnode = new TreeNode<T>(t->Data(), newlptr, newrptr);
//
//	// вернуть указатель на вновь созданное дерево
//	return newnode;
//
//}

//// поиск узла по значению
//// возвращает уровень, на котором был найден узел
//// либо -1, если узла с искомым значением нет
//template <typename T>
//int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
//	// если дошли до nullptr, до искомого значения в дереве нет
//	if (root == nullptr) {
//		return -1;
//	}
//
//	// поиск в правом поддереве
//	if (key > root->Data()) {
//		SearchNode(root->Right(), key, depth + 1);
//	}
//
//	// поиск в левом поддереве
//	else if (key < root->Data()) {
//		SearchNode(root->Left(), key, depth + 1);
//	}
//
//	// если key равен значению в текущем узле
//	else return depth;
//}
//
//// операция вставки узла в бинарное дерево поиска
//template <typename T>
//TreeNode<T>* InsertNode(TreeNode<T>* root, const T value) {
//
//	if (root == nullptr) {
//
//		// если дерево пустое, то создаём корень (первый узел)
//		return new TreeNode<T>(value);
//	}
//
//	// Вставляем данные либо в левое, либо в правое поддерево
//	if (value > root->Data()) {
//		// если значение, которое нужно добавить, больше текущего
//		root->SetRight(InsertNode(root->Right(), value));
//	}
//	else if (value < root->Data()) {
//		// если значение, которое нужно добавить, меньше текущего
//		root->SetLeft(InsertNode(root->Left(), value));
//	}
//
//	//возвращаем корень дерева
//	return root;
//}
