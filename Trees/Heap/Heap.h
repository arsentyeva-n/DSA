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
    size_t heapSize;       // ������ �������

    void bubbleUp(int i);       // ������� ����������� �����
    void trickleDown(int i);    // ������� ����������� ����

public:
    // ����������� �� ���������
	Heap();

    // ����������
    ~Heap() { lst.clear(); };

    // ���������� ������ ����
    size_t Size() const;
   
    
    void insert(const T& value);         // �������
    void printList();                    // ����� ������� ������
    T extractMax();                      // �������� ����� (������������� �������� � ����) � ��� ����������
    bool empty() const;                  // �������� �� �������
    void clear();

    

};

// ����������� �� ���������
template <typename T>
Heap<T>::Heap() 
{
    heapSize = lst.size();
}


// ������ ����
template <typename T>
size_t Heap<T>::Size() const
{
    return heapSize;
}

// ������� ������� � ����, �(log n) � ������, � ������ �(1)
template <typename T>
void Heap<T>::insert(const T& value)
{
    // ����������� ������� ������
    heapSize = heapSize + 1;
    // ��������� ����� �������
    lst.push_back(value);
    // ��������������� �������� ���� (max-heap)
    bubbleUp(heapSize - 1);
}


// ����������� �����, �(log n) � ������, � ������ �(1)
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


// �������� ����� (������������� �������� � ����) � ��� ����������, �(log n) � ������, 
// � ������ �(1) �������� ������, ���� ��������� ������� ������ ���� ���������
template <typename T>
T Heap<T>::extractMax()
{
    // ���������� max
    T min = lst[0];
    
    // �� ��� ����� ������ ����� ������ ���� ������ (��������� �������)
    lst[0] = lst[heapSize - 1];
    // ��������� ������ �������
    heapSize = heapSize - 1;
    // ��������������� �������� ���� ������������ ����
    trickleDown(0);
    // ������� ������ ������� � �������
    lst.pop_back();

    //���������� ��������
    return min;
}


// ����������� ����, �(log n) � ������, � ������ �(1)
template <typename T>
void Heap<T>::trickleDown(int i)
{
    // �������������� �������������� ����������
    int left, right, j;

    //cout << lst[i];
    // ���������� ������ � ���������, ���� �� �������� ������
    while (2 * i + 1 < heapSize) {    // heapSize � ���������� ��������� � ����
        left = 2 * i + 1;             // left � ����� ���
        right = 2 * i + 2;            // right � ������ ���
        
        // ���� ������ ��� ������
        if (lst[i] < lst[right])
            // ���������� ��� ������
            j = right;

        // ���� ����� ��� ������
        else if (lst[i] < lst[left])
            // ���������� ��� ������
            j = left;
        
        // ���� ������� ������� ������ ��� �����, �� ���� �������������
        if (lst[i] >= lst[j])
            break;

        // ����� ������ ������� ������ � �������
        swap(lst[i], lst[j]);
        // ������ ���������� ������ � ��� ���������
        i = j;
    }
}


// �������� �� �������
template<typename T>
bool Heap<T>::empty() const {
    return lst.empty();
}


// ������� �������
template<typename T>
void Heap<T>::clear() {
    lst.clear();
    heapSize = 0;
}


// ����� ������� ������
template<typename T>
void Heap<T>::printList() {
    for (const auto& element : lst) {
        cout << element << " ";
    }
    cout << endl;
}


// �������� ���� �� ������ ��������� ������
template <typename T>
Heap<T> buildHeapBinTree(TreeNode<T>* root)
{
    Heap<T> heap;
    // ���� ������ �� ������
    if (root != nullptr) 
    {
        

        // ������� �������
        queue <TreeNode<T>*> q;

        // ��������� ������ � �������
        q.push(root);

        // ���� ������� �� ������
        while (!q.empty()) 
        {
            // ��������� ������ ������� �� ������� � ��������� � ����
            TreeNode<T>* node = q.front();
            heap.insert(node->Data());

            // ������� ������� ���� � ��������� � ���������
            q.pop();                    

            // ��������� � ������� ������ � ������� ������� (���� ����������)
            if (node->Left() != nullptr)
                q.push(node->Left());
            if (node->Right() != nullptr)
                q.push(node->Right());
        }
    }
    return heap;
}