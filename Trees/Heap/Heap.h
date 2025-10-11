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
    size_t maxheapsize;    // макс или текущий размер ?? todo:
    size_t heapSize;       // Размер массива

    void bubbleUp(int i);       // Функция просеивания вверх
    void trickleDown(int i);    // Функция просеивания вниз

public:
    // Конструктор по умолчанию
	Heap();

    // Деструктор
    //~Heap();

    // Возвращает размер кучи
    size_t Size() const;
   
    
    void insert(const T& value);         // Вставка
    void printList();                    // Вывод массива данных
    T extractMax();                      // Удаление корня (максимального элемента в куче) и его извлечение
    // emty
    // clear
    //

    

};

// Конструктор по умолчанию
template <typename T>
Heap<T>::Heap() 
{
    heapSize = lst.size();
    maxheapsize = lst.size();
}


// Размер кучи
template <typename T>
size_t Heap<T>::Size() const
{
    return heapSize;
}

// Просеивание вверх
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

// Просеивание вниз
template <typename T>
void Heap<T>::trickleDown(int i)
{

    int left, right, j;
    while (2 * i + 1 > heapSize){    // heapSize — количество элементов в куче
        left = 2 * i + 1;            // left — левый сын
        right = 2 * i + 2;           // right — правый сын
        j = left;

        if (right < heapSize && lst[right] < lst[left])
            j = right;

        if (lst[i] <= lst[j])
            break;

        swap(lst[i], lst[j]);
        i = j;
    } 
}

// Функция вставки в кучу
template <typename T>
void Heap<T>::insert(const T& value)
{
    heapSize = heapSize + 1;
    lst.push_back(value);
    bubbleUp(heapSize-1);
}

// Удаление корня (максимального элемента в куче) и его извлечение TODO
template <typename T>
T Heap<T>::extractMax()
{
    T min = lst[0];
    lst[0] = lst[heapSize - 1];
    heapSize = heapSize - 1;
    trickleDown(0);
    return min;
}


// Вывод массива данных
template<typename T>
void Heap<T>::printList() {
    for (const auto& element : this->lst) {
        cout << element << " ";
    }
    cout << endl;
}