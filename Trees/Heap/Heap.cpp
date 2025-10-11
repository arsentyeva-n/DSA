

#include <iostream>
#include "Heap.h"
using namespace std;

int main()
{
	Heap<int> h;
	h.insert(2);
	h.insert(10);
	h.insert(5);
	h.insert(12);
	h.printList();

	cout << "\n" << h.extractMax() << endl;
	h.printList();
	
}

