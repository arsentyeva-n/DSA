//@author: Natalya Arsentyeva
#include <iostream>
#include "LinkedList.h"
#include "Iterator.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    LinkedList<int> list;
    list.addNode(10);
    list.addNode(20);
    list.addNode(30);

    cout << "Список: ";
    list.print();

    // Создаём итератор
    LinkedListIterator<int> it(list.getHead()); 

    cout << "Обход через итератор: ";
    while (it.hasNext()) {
        cout << it.get_data() << " ";
        it.next();
    }
    cout << endl;

    // Добавляем и удаляем узлы
    list.addNode(40);
    list.removeNode(20);

    // Сброс и повторный проход
    it.reset();
    cout << "После reset: ";
    while (it.hasNext()) {
        cout << it.get_data() << " "; 
        it.next();
    }
    cout << endl;

    it.next();
    it.reset();
    it.next();
    cout << it.get_data() << " ";

    return 0;
}