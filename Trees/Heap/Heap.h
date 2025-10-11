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
    int maxheapsize; // ���� ��� ������� ������
    int heapSize; // ���������� ����� ������

    void bubbleUp(int i);
    void trickleDown(int i);

public:
	Heap();
    //~Heap();
	size_t get_heapSize() const; // ������������ � ������� ������� ��������
   
    void insert(const T& value);
    void remove(const T& value);
    void removeMax();
    void printList();
    // delete
    // emty
    //clear
    //

    

};

template <typename T>
Heap<T>::Heap() 
{
    heapSize = 0;
    maxheapsize = lst.size();
}


template <typename T>
size_t Heap<T>::get_heapSize() const
{
    return heapSize;
}

// ����������� �����
template <typename T>
void Heap<T>::bubbleUp(int i)
{
    // ���� ����������� ������� ������ �����
    while (lst[i] > lst[(i - 1) / 2]) {     // max-heap 
        // ������ �� �������
        swap(lst[i], lst[(i - 1) / 2]);
        // ��������� � ������
        i = (i - 1) / 2;
    }
}

// ����������� ����
template <typename T>
void Heap<T>::trickleDown(int i)
{
    

}

template <typename T>
void Heap<T>::insert(const T& value)
{
    heapSize = heapSize + 1;
    lst.push_back(value);
    bubbleUp(heapSize-1);
}

template <typename T>
void Heap<T>::remove(const T& value)
{
 /*   heapSize = heapSize - 1;
    lst.push_back(value);
    trickleDown(heapSize-1);*/
}

template <typename T>
void Heap<T>::removeMax()
{
    /*   heapSize = heapSize - 1;
       lst.push_back(value);
       trickleDown(heapSize-1);*/
}

// ����� ������� ������
template<typename T>
void Heap<T>::printList() {
    for (const auto& element : this->lst) {
        cout << element << " ";
    }
    cout << endl;
}