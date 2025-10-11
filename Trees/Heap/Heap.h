//@author: Natalya Arsentyeva


#pragma once
#include "../NodeTree/NodeTree.h"
#include <vector>
using namespace std;


///  �������� ���� (max-heap)

template <typename T>
class Heap
{
private:
	vector<T> lst;         // ������� ������������ ������ � ������� �������
    size_t maxheapsize;    // ���� ��� ������� ������ ?? todo:
    size_t heapSize;       // ������ �������

    void bubbleUp(int i);       // ������� ����������� �����
    void trickleDown(int i);    // ������� ����������� ����

public:
    // ����������� �� ���������
	Heap();

    // ����������
    //~Heap();

    // ���������� ������ ����
    size_t Size() const;
   
    
    void insert(const T& value);         // �������
    void printList();                    // ����� ������� ������
    T extractMax();                      // �������� ����� (������������� �������� � ����) � ��� ����������
    // emty
    // clear
    //

    

};

// ����������� �� ���������
template <typename T>
Heap<T>::Heap() 
{
    heapSize = lst.size();
    maxheapsize = lst.size();
}


// ������ ����
template <typename T>
size_t Heap<T>::Size() const
{
    return heapSize;
}

// ����������� �����
template <typename T>
void Heap<T>::bubbleUp(int i)
{
    // ���� ����������� ������� (���) ������ ����� (��������)
    while (lst[i] > lst[(i - 1) / 2]) {     // max-heap 
        // ������ �� �������, ���� ��� ������
        swap(lst[i], lst[(i - 1) / 2]);
        // ��������� � �������� � ���������� ���
        i = (i - 1) / 2;
    }
}

// ����������� ����
template <typename T>
void Heap<T>::trickleDown(int i)
{

    int left, right, j;
    while (2 * i + 1 > heapSize){    // heapSize � ���������� ��������� � ����
        left = 2 * i + 1;            // left � ����� ���
        right = 2 * i + 2;           // right � ������ ���
        j = left;

        if (right < heapSize && lst[right] < lst[left])
            j = right;

        if (lst[i] <= lst[j])
            break;

        swap(lst[i], lst[j]);
        i = j;
    } 
}

// ������� ������� � ����
template <typename T>
void Heap<T>::insert(const T& value)
{
    heapSize = heapSize + 1;
    lst.push_back(value);
    bubbleUp(heapSize-1);
}

// �������� ����� (������������� �������� � ����) � ��� ���������� TODO
template <typename T>
T Heap<T>::extractMax()
{
    T min = lst[0];
    lst[0] = lst[heapSize - 1];
    heapSize = heapSize - 1;
    trickleDown(0);
    return min;
}


// ����� ������� ������
template<typename T>
void Heap<T>::printList() {
    for (const auto& element : this->lst) {
        cout << element << " ";
    }
    cout << endl;
}