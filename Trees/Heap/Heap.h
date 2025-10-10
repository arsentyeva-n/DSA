//@author: Natalya Arsentyeva


#pragma once
#include "../NodeTree/NodeTree.h"
#include <vector>
using namespace std;


///  Двоичная куча max-heap

template <typename T>
class Heap
{
private:

	vector<T> lst;
    size_t  maxheapsize; // макс или текущий размер
    size_t heapSize; // определяет конец списка

    void bubbleUp(size_t i);
    void trickleDown(size_t i);

public:
	Heap();
    
	size_t get_heapSize() const;
    // максимальный и текущий размеры пирамиды
    void add(const T& value);
    // delete
    // emty
    //clear
    //

    

};

template <typename T>
Heap<T>::Heap() 
{
    heapSize = lst.size();

}


template <typename T>
size_t Heap<T>::get_heapSize() const
{
    return heapSize;
}

// просеивание вверх
template <typename T>
void bubbleUp(size_t i) 
{

}
// просеивание вниз
template <typename T>
void trickleDown(size_t i) 
{
    //while 2 * i + 1 < lst.heapSize     // heapSize — количество элементов в куче
    //    left = 2 * i + 1             // left — левый сын
    //    right = 2 * i + 2            // right — правый сын
    //    j = left
    //    if right < a.heapSize and a[right] < a[left]
    //        j = right
    //        if a[i] <= a[j]
    //            break
    //            swap(a[i], a[j])
    //            i = j

    //            int size = data.size();

    //while (index < size) {
    //    int leftChild = 2 * index + 1;   // Левый потомок
    //    int rightChild = 2 * index + 2;  // Правый потомок
    //    int smallest = index;            // Индекс наименьшего элемента

    //    // Сравниваем с левым потомком
    //    if (leftChild < size && data[leftChild] < data[smallest]) {
    //        smallest = leftChild;
    //    }

    //    // Сравниваем с правым потомком
    //    if (rightChild < size && data[rightChild] < data[smallest]) {
    //        smallest = rightChild;
    //    }

    //    // Если найден потомок меньше текущего элемента - меняем местами
    //    if (smallest != index) {
    //        swap(data[index], data[smallest]);
    //        index = smallest;  // Продолжаем с новым положением
    //    }
    //    else {
    //        break;  // Свойство кучи восстановлено
    //    }
    //}
}

template <typename T>
void Heap<T>::add(const T& value)
{
    list.add(value);
    int i = heapSize - 1;
    int parent = (i - 1) / 2;

    while (i > 0 && list[parent] < list[i])
    {
        int temp = list[i];
        list[i] = list[parent];
        list[parent] = temp;

        i = parent;
        parent = (i - 1) / 2;
    }
}

