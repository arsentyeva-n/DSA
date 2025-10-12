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

    // Деструктор
    ~Heap() { lst.clear(); };

    // Возвращает размер кучи
    size_t Size() const;
   
    
    void insert(const T& value);         // Вставка
    void printList();                    // Вывод массива данных
    T extractMax();                      // Удаление корня (максимального элемента в куче) и его извлечение
    bool empty() const;                  // Проверка на пустоту
    void clear();

    

};

// Конструктор по умолчанию
template <typename T>
Heap<T>::Heap() 
{
    heapSize = lst.size();
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
    T min = lst[0];
    
    // На его место ставим самый правый лист дерева (последний элемент)
    lst[0] = lst[heapSize - 1];
    // Уменьшаем размер массива
    heapSize = heapSize - 1;
    // Восстанавливаем свойство кучи просеиванием вниз
    trickleDown(0);
    // Удаляем лишний элемент в массиве
    lst.pop_back();

    //Возвращаем максимум
    return min;
}


// Просеивание вниз, О(log n) в худшем, в лучшем О(1)
template <typename T>
void Heap<T>::trickleDown(int i)
{
    // Инициалищируем дополнительные переменные
    int left, right, j;

    //cout << lst[i];
    // Сравниваем корень с потомками, пока не кончится дерево
    while (2 * i + 1 < heapSize) {    // heapSize — количество элементов в куче
        left = 2 * i + 1;             // left — левый сын
        right = 2 * i + 2;            // right — правый сын
        
        // Если правый сын больше
        if (lst[i] < lst[right])
            // Запоминаем его индекс
            j = right;

        // Если левый сын больше
        else if (lst[i] < lst[left])
            // Запоминаем его индекс
            j = left;
        
        // Если текущий элемент больше или равен, то цикл заканчивается
        if (lst[i] >= lst[j])
            break;

        // Иначе меняем местами корень и потомка
        swap(lst[i], lst[j]);
        // Дальше просеиваем корень с его потомками
        i = j;
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