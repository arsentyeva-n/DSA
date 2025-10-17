//@author: Natalya Arsentyeva


#pragma once
#include "../NodeTree/NodeTree.h"
#include <vector>
using namespace std;


///  Двоичная куча (max-heap)

template <typename T>
class Heap
{
private:
	vector<T> lst;         // Создаем динамический массив с помощью вектора
    size_t heapSize;       // Размер массива

    void bubbleUp(int i);       // Функция просеивания вверх
    void trickleDown(int i);    // Функция просеивания вниз

public:
    // Конструктор по умолчанию
	Heap();
    // Конструктор с парамектром (вектором)
    Heap(vector<T> elements);

    // Деструктор
    ~Heap() { lst.clear(); };

    // Возвращает размер кучи
    size_t Size() const;
   
    
    void insert(const T& value);         // Вставка
    void printList();                    // Вывод массива данных
    T extractMax();                      // Удаление корня (максимального элемента в куче) и его извлечение
    bool empty() const;                  // Проверка на пустоту
    void clear();                        // Очистка кучи
    int search(const T& value) const;    // Поиск элемента в куче
    

};

// Конструктор по умолчанию
template <typename T>
Heap<T>::Heap() 
{
    heapSize = lst.size();
}

// Конструктор с параметром
template <typename T>
Heap<T>::Heap(vector<T> elements)
{
    lst = elements;
    heapSize = lst.size();
    // Просеиваем потомков
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        trickleDown(i);
    }
}

// Размер кучи
template <typename T>
size_t Heap<T>::Size() const
{
    return heapSize;
}

// Функция вставки в кучу, О(log n) в худшем, в лучшем О(1)
template <typename T>
void Heap<T>::insert(const T& value)
{
    // Увеличиваем текущий размер
    heapSize = heapSize + 1;
    // Вставляем новый элемент
    lst.push_back(value);
    // Восстанавливаем свойство кучи (max-heap)
    bubbleUp(heapSize - 1);
}


// Просеивание вверх, О(log n) в худшем, в лучшем О(1)
template <typename T>
void Heap<T>::bubbleUp(int i)
{
    // Пока вставляемый элемент (сын) больше корня (родителя)
    while (lst[i] > lst[(i - 1) / 2]) {     // max-heap 
        // Меняем их местами, если сын больше
        swap(lst[i], lst[(i - 1) / 2]);
        // Переходим к родителю и просеиваем его
        i = (i - 1) / 2;
    }
}


// Удаление корня (максимального элемента в куче) и его извлечение, О(log n) в худшем, 
// в лучшем О(1) возможно только, если последний элемент больше всех остальных
template <typename T>
T Heap<T>::extractMax()
{
    // Запоминаем max
    T max = lst[0];
    
    // На его место ставим самый правый лист дерева (последний элемент)
    lst[0] = lst[heapSize - 1];
   
    // Восстанавливаем свойство кучи просеиванием вниз
    trickleDown(0);
    // Удаляем лишний элемент в массиве
    lst.pop_back();
    // Уменьшаем размер массива
    heapSize = heapSize - 1;
    //Возвращаем максимум
    return max;
}


template <typename T>
void Heap<T>::trickleDown(int i)
{
   
    // Инициализируем дополнительные переменные
    int left, right, j;
    //cout << lst[i];
    while (2 * i + 1 < heapSize) {    // Пока есть хотя бы левый потомок
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;  // По умолчанию считаем левого потомка наибольшим

        // Если есть правый потомок и он больше левого
        if (right < heapSize && lst[right] > lst[left]) {
            j = right;
        }

        // Если текущий элемент уже больше наибольшего потомка - выходим
        if (lst[i] >= lst[j]) {
            break;
        }

        // Меняем местами с наибольшим потомком
        swap(lst[i], lst[j]);
        i = j;  // Переходим к потомку
    }
}

// Проверка на пустоту
template<typename T>
bool Heap<T>::empty() const {
    return lst.empty();
}


// Очистка массива
template<typename T>
void Heap<T>::clear() {
    lst.clear();
    heapSize = 0;
}


// Вывод массива данных
template<typename T>
void Heap<T>::printList() {
    for (const auto& element : lst) {
        cout << element << " ";
    }
    cout << endl;
}

// Поиск элемента в куче и вывод его индекса
template<typename T>
int Heap<T>::search(const T& value) const
{
    for (int i = 0; i < heapSize; i++)
    {
        if (lst[i] == value) {
            return i;
            break;
        }
    }
    return -1;
}

// Создание кучи на основе бинарного дерева
template <typename T>
Heap<T> buildHeapBinTree(TreeNode<T>* root)
{
    Heap<T> heap;
    // Если дерево не пустое
    if (root != nullptr) 
    {
        // Создаем очередь
        queue <TreeNode<T>*> q;

        // Сохраняем корень в очередь
        q.push(root);

        // Пока очередь не пустая
        while (!q.empty()) 
        {
            // Извлекаем первый элемент из очереди и добавляем в кучу
            TreeNode<T>* node = q.front();
            heap.insert(node->Data());

            // Удаляем текущий узел и переходим к следующим
            q.pop();                    

            // Добавляем в очередь левого и правого потомка (если существуют)
            if (node->Left() != nullptr)
                q.push(node->Left());
            if (node->Right() != nullptr)
                q.push(node->Right());
        }
    }
    return heap;
}

// Создание вектора на основе бинарного дерева
template <typename T>
vector<T> buildHeapArr(TreeNode<T>* root)
{
    vector<T> elements;
    // Если дерево не пустое
    if (root != nullptr)
    {
        
        queue<T> q;
        // Сохраняем корень в очередь
        q.push(root);

        // Пока очередь не пустая
        while (!q.empty())
        {
            // Извлекаем первый элемент из очереди и добавляем в кучу
            TreeNode<T>* node = q.front();
            elements.insert(node->Data());

            // Удаляем текущий узел и переходим к следующим
            q.pop();

            // Добавляем в очередь левого и правого потомка (если существуют)
            if (node->Left() != nullptr)
                q.push(node->Left());
            if (node->Right() != nullptr)
                q.push(node->Right());
        }
    }
    return elements;
}