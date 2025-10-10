//@author: Natalya Arsentyeva


#pragma once
#include "../NodeTree/NodeTree.h"
#include <vector>
using namespace std;


///  �������� ���� max-heap

template <typename T>
class Heap
{
private:

	vector<T> lst;
    size_t  maxheapsize; // ���� ��� ������� ������
    size_t heapSize; // ���������� ����� ������

    void bubbleUp(size_t i);
    void trickleDown(size_t i);

public:
	Heap();
    
	size_t get_heapSize() const;
    // ������������ � ������� ������� ��������
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

// ����������� �����
template <typename T>
void bubbleUp(size_t i) 
{

}
// ����������� ����
template <typename T>
void trickleDown(size_t i) 
{
    //while 2 * i + 1 < lst.heapSize     // heapSize � ���������� ��������� � ����
    //    left = 2 * i + 1             // left � ����� ���
    //    right = 2 * i + 2            // right � ������ ���
    //    j = left
    //    if right < a.heapSize and a[right] < a[left]
    //        j = right
    //        if a[i] <= a[j]
    //            break
    //            swap(a[i], a[j])
    //            i = j

    //            int size = data.size();

    //while (index < size) {
    //    int leftChild = 2 * index + 1;   // ����� �������
    //    int rightChild = 2 * index + 2;  // ������ �������
    //    int smallest = index;            // ������ ����������� ��������

    //    // ���������� � ����� ��������
    //    if (leftChild < size && data[leftChild] < data[smallest]) {
    //        smallest = leftChild;
    //    }

    //    // ���������� � ������ ��������
    //    if (rightChild < size && data[rightChild] < data[smallest]) {
    //        smallest = rightChild;
    //    }

    //    // ���� ������ ������� ������ �������� �������� - ������ �������
    //    if (smallest != index) {
    //        swap(data[index], data[smallest]);
    //        index = smallest;  // ���������� � ����� ����������
    //    }
    //    else {
    //        break;  // �������� ���� �������������
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

